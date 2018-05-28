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
    println_string_with_token(" Main menu ", '=', _MAIN_MENU_WIDTH, '|');
    println_string_with_token("1. SHOW sales data", ' ', _MAIN_MENU_WIDTH, '|');
    println_string_with_token("2. ADD new part   ", ' ', _MAIN_MENU_WIDTH, '|');
    println_string_with_token("3. EDIT part info ", ' ', _MAIN_MENU_WIDTH, '|');
    println_string_with_token(NULL, '-', _MAIN_MENU_WIDTH, '|');
    println_string_with_token("4. Exit           ", ' ', _MAIN_MENU_WIDTH, '|');
    println_string_with_token(NULL, '=', _MAIN_MENU_WIDTH, '|');
    printf("> ");
}

void _display_edit_menu() {
    println_string_with_token(" Main menu ", '=', _EDIT_MENU_WIDTH, '|');
    println_string_with_token("1. Product number", ' ', _EDIT_MENU_WIDTH, '|');
    println_string_with_token("2. Product name  ", ' ', _EDIT_MENU_WIDTH, '|');
    println_string_with_token("3. Specification ", ' ', _EDIT_MENU_WIDTH, '|');
    println_string_with_token("4. Price         ", ' ', _EDIT_MENU_WIDTH, '|');
    println_string_with_token("5. Sales         ", ' ', _EDIT_MENU_WIDTH, '|');
    println_string_with_token(NULL, '-', _EDIT_MENU_WIDTH, '|');
    println_string_with_token("6. Back          ", ' ', _EDIT_MENU_WIDTH, '|');
    println_string_with_token(NULL, '=', _EDIT_MENU_WIDTH, '|');
    printf("> ");
}


SalesList new_SalesList(const char **columnNames, const int *columnSpaces) {
    SalesList list = (_SalesList *)malloc(sizeof(_SalesList)+1);
    
    list->parts = (Part *)malloc(sizeof(Part)+1);
    list->colomnNames = columnNames;
    list->colomnSpaces = columnSpaces;
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
                print_sales_list(list, _LIST_ALL);
                break;
            case 2:
                create_new_part_from_input(list);
                break;
            case 3:
                print_sales_list(list, _LIST_ALL);
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
    print_sales_list(list, targetIndex);
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
                print_sales_list(list, targetIndex);
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
                print_sales_list(list, targetIndex);
                free(oldName);
                break;
            case 3:
                printf("Enter new specification: ");
                if (atoi(charBuffer = get_input_string()) != -99) {
                    free(part->specification);
                    part->specification = charBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("The new specification of %s is %s\n\n", part->partName, part->specification);
                print_sales_list(list, targetIndex);
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
                print_sales_list(list, targetIndex);
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
                print_sales_list(list, targetIndex);
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
    print_sales_list(list, _LIST_LAST);
}

void add_to_list(SalesList list, Part part) {
    list->parts = (Part *)realloc(list->parts, sizeof(Part) * (++ list->numberOfParts)+1);
    list->parts[list->numberOfParts - 1] = part;
}

void print_sales_list(SalesList list, const unsigned int specificIndex) {
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
    
    if ((specificIndex > list->numberOfParts - 1) && !(specificIndex & (_LIST_LAST | _LIST_ALL)))
        return;
    
    // print first row
    println_string_cells_with_token(list->colomnNames, _COLUMN_NUM, ' ', list->colomnSpaces, '|');
    println_token('=', _get_sum(list->colomnSpaces, 7) + 1); /* print a row for division */
    
    /* range setup */
    int begin = 0;
    int end = 0;
    
    if (specificIndex == _LIST_ALL) {
        begin = 0;
        end = list->numberOfParts;
    } else if (specificIndex == _LIST_LAST) {
        begin = list->numberOfParts - 1;
        end = list->numberOfParts;
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
        _int_to_string(num, list->parts[i]->partNum);
        _int_to_string_with_comma(price, list->parts[i]->price);
        _int_to_string_with_comma(sales, list->parts[i]->sales);
        _int_to_string_with_comma(revenue, list->parts[i]->revenue);
        
        const char *partProperties[_COLUMN_NUM] = { index, num, list->parts[i]->partName, list->parts[i]->specification, price, sales, revenue };
        
        // print all properties center-aligned, covered and divided by '|'
        println_string_cells_with_token(partProperties, _COLUMN_NUM, ' ', list->colomnSpaces, '|');
    }
    
    /* optional thing to do when printing all */
    if (specificIndex == _LIST_ALL) {
        println_token('=', _get_sum(list->colomnSpaces, 7) + 1);
        char salesTotal[_SMALL_BUFFER_SIZE];
        char revenueTotal[_SMALL_BUFFER_SIZE];
        
        unsigned int salesCount = 0;
        unsigned int revCount = 0;
        for (register unsigned int i = 0; i < list->numberOfParts; ++ i) {
            salesCount += list->parts[i]->sales;
            revCount += list->parts[i]->revenue;
        }
        
        _int_to_string_with_comma(salesTotal, salesCount);
        _int_to_string_with_comma(revenueTotal, revCount);
        const char *partProperties[_COLUMN_NUM] = {"Total", "", "", "", "", salesTotal, revenueTotal};
        
        // print totals
        println_string_cells_with_token(partProperties, _COLUMN_NUM, ' ', list->colomnSpaces, '|');
    }
}

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
