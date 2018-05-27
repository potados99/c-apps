//
//  SalesManagement.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//

#include "SalesManagement.h"

void _display_main_menu() {
    static const int lineLength = 25;
    println_string_with_token(" Main menu ", '=', lineLength, '|');
    println_string_with_token("1. SHOW sales data", ' ', lineLength, '|');
    println_string_with_token("2. ADD new part   ", ' ', lineLength, '|');
    println_string_with_token("3. EDIT part info ", ' ', lineLength, '|');
    println_string_with_token(NULL, '-', lineLength, '|');
    println_string_with_token("4. Exit           ", ' ', lineLength, '|');
    println_string_with_token(NULL, '=', lineLength, '|');
    printf("> ");
}

void _display_edit_menu() {
    static const int lineLength = 25;
    println_string_with_token(" Main menu ", '=', lineLength, '|');
    println_string_with_token("1. Product number", ' ', lineLength, '|');
    println_string_with_token("2. Product name  ", ' ', lineLength, '|');
    println_string_with_token("3. Specification ", ' ', lineLength, '|');
    println_string_with_token("4. Price         ", ' ', lineLength, '|');
    println_string_with_token("5. Sales         ", ' ', lineLength, '|');
    println_string_with_token(NULL, '-', lineLength, '|');
    println_string_with_token("6. Back          ", ' ', lineLength, '|');
    println_string_with_token(NULL, '=', lineLength, '|');
    printf("> ");
}

void _print_parts(Part *parts, const unsigned int length, const unsigned int specificIndex) {
    /*
     In:
     [parts]: pointer of array of (Part).
     [length]: length of that array.
     [specificIndex]:
     Out: none
     Description: print all fields of element in array of (Part).
     view data in form of table.
     I used print_string_with_blank function to get center-aligned table.
     Non-string variables are converted to string to be processed as an element of char * array.
     */
    
    if ((specificIndex > length - 1) && !(specificIndex & (LIST_LAST | LIST_ALL)))
        return;
    
    /* constant variable setup */
    static const char *colomnNames[_COLUMN_NUM] = {"Index", "Number", "Name", "Specification", "Price", "Sales", "Revenue"};
    
    enum {
        index = 8,
        number = 11,
        name = 17,
        spec = 20,
        price = 12,
        sales = 10,
        revenue = 15
    };
    
    static const int spaces[_COLUMN_NUM] = {index, number, name, spec, price, sales, revenue};
    
    // print first row
    println_string_cells_with_token(colomnNames, _COLUMN_NUM, ' ', spaces, '|');
    println_token('=', _get_sum(spaces, 7) + 1); /* print a row for division */
    
    /* range setup */
    int begin = 0;
    int end = 0;
    
    if (specificIndex == LIST_ALL) {
        begin = 0;
        end = length;
    } else if (specificIndex == LIST_LAST) {
        begin = length - 1;
        end = length;
    } else {
        begin = specificIndex;
        end = specificIndex + 1;
    }
    
    /* convert all properties into string and print them */
    for (int i = begin; i < end; ++ i) {
        // buffers to contain the converted variables
        char index[_SMALL_BUFFER_SIZE];
        char num[_SMALL_BUFFER_SIZE];
        char price[_SMALL_BUFFER_SIZE];
        char sales[_SMALL_BUFFER_SIZE];
        char revenue[_SMALL_BUFFER_SIZE];
        
        // int to string
        _int_to_string(index, i);
        _int_to_string(num, parts[i]->partNum);
        _int_to_string_with_comma(price, parts[i]->price);
        _int_to_string_with_comma(sales, parts[i]->sales);
        _int_to_string_with_comma(revenue, parts[i]->revenue);
        
        const char *partProperties[_COLUMN_NUM] = { index, num, parts[i]->partName, parts[i]->specification, price, sales, revenue };
        
        // print all properties center-aligned, covered and divided by '|'
        println_string_cells_with_token(partProperties, _COLUMN_NUM, ' ', spaces, '|');
    }
    
    /* optional thing to do when printing all */
    if (specificIndex == LIST_ALL) {
        println_token('=', _get_sum(spaces, 7) + 1);
        char revenueTotal[_SMALL_BUFFER_SIZE];
        
        unsigned int revCount = 0;
        for (register unsigned int i = 0; i < length; ++ i) {
            revCount += parts[i]->revenue;
        }
        
        _int_to_string_with_comma(revenueTotal, revCount);
        const char *partProperties[_COLUMN_NUM] = {"Total", "", "", "", "", "", revenueTotal};
        
        // print total revenue
        println_string_cells_with_token(partProperties, _COLUMN_NUM, ' ', spaces, '|');
    }
}


SalesList new_SalesList(void) {
    SalesList list = (_SalesList *)malloc(sizeof(_SalesList)+1);
    
    list->parts = (Part *)malloc(sizeof(Part)+1);
    list->numberOfParts = 0;
    
    return list;
}

void destructor(SalesList list) {
    /*
     In: [list]
     Out: none
     Description: free allocated memmory
     */
    
    /*
     SalesList list:
     int numberOfParts
     Part *parts:
     Part part:
     char *partName
     char *specification
     ...
     */
    
    for (register unsigned int i = 0; i < list->numberOfParts; ++ i) {
        free(list->parts[i]->partName);
        free(list->parts[i]->specification);
    }
}

void start_main_loop(SalesList list) {
    _display_main_menu();
    
    int selected = 0;
    rewind(stdin);
    
    while ((selected = getchar() - '0') != 4) {
        rewind(stdin);
        
        bool escapedFromEdit = False;
        
        puts("");
        switch (selected) {
            case 1:
                print_sales_list(list);
                break;
            case 2:
                create_new_part_from_input(list);
                break;
            case 3:
                print_sales_list(list);
                puts("");
                start_edit_loop(list);
                escapedFromEdit = True;
                break;
                
            default:
                puts("Wrong input.");
                break;
        }
        if (! escapedFromEdit )
            wait_for_enter();
        
        rewind(stdin);
        _display_main_menu();
    }
    rewind(stdin);
    printf("Exiting program.\n");
}

void start_edit_loop(SalesList list) {
    int targetIndex = 0;
    printf("Enter the index of part you want to edit: ");
    
    while (((targetIndex = getchar() -'0') < 0) || (targetIndex >= list->numberOfParts) || (targetIndex + '0' == 10))
        printf("**Enter proper index: ");
    
    puts("");
    _print_parts(list->parts, list->numberOfParts, targetIndex);
    wait_for_enter();
    
    _display_edit_menu();
    
    int selected = 0;
    Part part = list->parts[targetIndex];
    rewind(stdin);
    
    selected = getchar() - '0';
    int breakMe = 0;
    
    while (1) {
        rewind(stdin);
        
        breakMe = 0;
        puts("");
        
        int intBuffer;
        char *charBuffer;
        
        switch (selected) {
            case 1:
                printf("Enter new product number: ");
                if ((intBuffer = get_input_number()) != -99) {
                    part->partNum = intBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("The new product number of %s is %d\n\n", part->partName, part->partNum);
                _print_parts(list->parts, list->numberOfParts, targetIndex);
                break;
            case 2:
                printf("Enter new product name: ");
                char *oldName = part->partName;
                if (atoi(charBuffer = get_input_string()) != -99) {
                    part->partName = charBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("The new product name of %s is %s\n\n", oldName, part->partName);
                _print_parts(list->parts, list->numberOfParts, targetIndex);
                break;
            case 3:
                printf("Enter new specification: ");
                if (atoi(charBuffer = get_input_string()) != -99) {
                    part->specification = charBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("The new specification of %s is %s\n\n", part->partName, part->specification);
                _print_parts(list->parts, list->numberOfParts, targetIndex);
                break;
            case 4:
                printf("Enter new price: ");
                if ((intBuffer = get_input_number()) != -99) {
                    part->price = intBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("The new price of %s is %d\n\n", part->partName, part->price);
                part->revenue = part->price * part->sales;
                _print_parts(list->parts, list->numberOfParts, targetIndex);
                break;
            case 5:
                printf("Enter new sales: ");
                if ((intBuffer = get_input_number()) != -99) {
                    part->sales = intBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("The new sales of %s is %d\n\n", part->partName, part->sales);
                part->revenue = part->price * part->sales;
                _print_parts(list->parts, list->numberOfParts, targetIndex);
                break;
            case 6:
                breakMe = 1;
                break;
                
            default:
                puts("Wrong input.");
                break;
        }
        if (breakMe)
            break;
        wait_for_enter();
        _display_edit_menu();
        
        selected = getchar() - '0';
    }
}

void create_new_part_from_input(SalesList list) {
    int partNumber;
    char *partName;
    char *specification;
    int price;
    int sales;
    
    printf("Enter part number: ");
    partNumber = get_input_number();
    if (partNumber == -99) {
        puts("Canceled");
        return;
    }
    
    printf("Enter part name: ");
    partName = get_input_string();
    if (atoi(partName) == -99) {
        puts("Canceled");
        return;
    }
    
    printf("Enter specification: ");
    specification = get_input_string();
    if (atoi(specification) == -99) {
        puts("Canceled");
        return;
    }
    
    printf("Enter price: ");
    price = get_input_number();
    if (price == -99) {
        puts("Canceled");
        return;
    }
    
    printf("Enter sales: ");
    sales = get_input_number();
    if (sales == -99) {
        puts("Canceled");
        return;
    }
    
    Part newPart = new_Part(partNumber, partName, specification, price, sales);
    add_to_list(list, newPart);
    
    puts("\nAdded: ");
    _print_parts(list->parts, list->numberOfParts, LIST_LAST);
}

void add_to_list(SalesList list, Part part) {
    list->parts = (Part *)realloc(list->parts, sizeof(Part) * (++ list->numberOfParts)+1);
    list->parts[list->numberOfParts - 1] = part;
}

void print_sales_list(SalesList list) {
    _print_parts(list->parts, list->numberOfParts, LIST_ALL);
}

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
