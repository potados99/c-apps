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
    println_string_with_token(" Main menu ", "═", _MAIN_MENU_WIDTH, "╔", "╗");
    println_string_with_token("1. Show sales data", " ", _MAIN_MENU_WIDTH, "║", "║");
    println_string_with_token("2. Add new part   ", " ", _MAIN_MENU_WIDTH, "║", "║");
    println_string_with_token("3. Edit part info ", " ", _MAIN_MENU_WIDTH, "║", "║");
    println_string_with_token("4. Export to file ", " ", _MAIN_MENU_WIDTH, "║", "║");
    println_string_with_token(NULL, "═", _MAIN_MENU_WIDTH, "╠", "╣");
    println_string_with_token("5. Exit           ", " ", _MAIN_MENU_WIDTH, "║", "║");
    println_string_with_token(NULL, "═",_MAIN_MENU_WIDTH, "╚", "╝");
    printf("> ");
}

void _display_edit_menu() {
    println_string_with_token(" Edit menu ", "═", _EDIT_MENU_WIDTH, "╔",  "╗");
    println_string_with_token("1. Product number", " ", _EDIT_MENU_WIDTH, "║", "║");
    println_string_with_token("2. Product name  ", " ", _EDIT_MENU_WIDTH, "║", "║");
    println_string_with_token("3. Specification ", " ", _EDIT_MENU_WIDTH, "║", "║");
    println_string_with_token("4. Price         ", " ", _EDIT_MENU_WIDTH, "║", "║");
    println_string_with_token("5. Sales         ", " ", _EDIT_MENU_WIDTH, "║", "║");
    println_string_with_token(NULL, "═", _MAIN_MENU_WIDTH, "╠", "╣");
    println_string_with_token("6. Back          ", " ", _EDIT_MENU_WIDTH, "║", "║");
    println_string_with_token(NULL, "═", _EDIT_MENU_WIDTH,"╚", "╝");
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

void clear_list(SalesList list) {
    for (register unsigned int i = 0; i < list->numberOfParts; ++ i) {
        free(list->parts[i]->partName);
        free(list->parts[i]->specification);
    }
    list->parts = (Part *)malloc(sizeof(Part)+1);
    list->numberOfParts = 0;
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

void start_main_loop(const char *dataFilePath, const char *exportFilePath, SalesList list) {
    _display_main_menu();

    int selected = 0;
    rewind(stdin);
    
    while ((selected = get_input_number(NULL, WITHOUT_BOX)) != 5) {
        rewind(stdin);
        
        read_sales_list(dataFilePath, list);
        
        bool escapedFromEdit = False;
        clear_console();
        switch (selected) {
            case 1:
                print_sales_list(list, _LIST_ALL);
                break;
            case 2:
                create_new_part_from_input(list);
                write_sales_list(dataFilePath, list);
                break;
            case 3:
                print_sales_list(list, _LIST_ALL);
                printf("\n");
                start_edit_loop(list);
                write_sales_list(dataFilePath, list);
                escapedFromEdit = True;
                break;
            case 4:
                export_sales_list(exportFilePath, list, _LIST_ALL);
                break;
            default:
                puts("Wrong input.");
                break;
        }
        if (! escapedFromEdit)
            wait_for_enter();
        clear_console();
        _display_main_menu();
    }
    rewind(stdin);
    printf("Exiting program.\n");
}

void start_edit_loop(SalesList list) {
    int targetIndex = get_input_number("Enter the index of part you want to edit: ", WITHOUT_BOX);
    while ((targetIndex < 0) || (targetIndex >= list->numberOfParts) || targetIndex == INT_INPUT_ERROR) {
        movexy(0, -2);
        printf("\r");
        printf("**Enter proper index. \n");
        targetIndex = get_input_number("Enter the index of part you want to edit: ", WITHOUT_BOX);
    }
    
    clear_console();
    print_sales_list(list, targetIndex);
    printf("\n");
    _display_edit_menu();
    
    int selected = 0;
    Part part = list->parts[targetIndex];
    rewind(stdin);
    
    selected = get_input_number(NULL, WITHOUT_BOX);
    int breakMe = 0;
    
    while (1) {
        rewind(stdin);
        
        breakMe = 0;
        
        int intBuffer;
        char *charBuffer;
        char *oldName;
        
        clear_console();
        print_sales_list(list, targetIndex);

        printf("\n");
        
        switch (selected) {
            case 1:
                intBuffer = get_input_number("Enter new product number: ", WITH_BOX);
                if (intBuffer != INT_INPUT_ERROR && intBuffer != -99) {
                    part->partNum = intBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("\nThe new product number of %s is %d\n", part->partName, part->partNum);
                print_sales_list(list, targetIndex);
                break;
            case 2:
                oldName = part->partName;
                charBuffer = get_input_string("Enter new product name: ", WITH_BOX);
                if (charBuffer && atoi(charBuffer) != -99) {
                    part->partName = charBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("\nThe new product name of %s is %s\n", oldName, part->partName);
                print_sales_list(list, targetIndex);
                free(oldName);
                break;
            case 3:
                charBuffer = get_input_string("Enter new specification: ", WITH_BOX);
                if (charBuffer && atoi(charBuffer) != -99) {
                    free(part->specification);
                    part->specification = charBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("\nThe new specification of %s is %s\n", part->partName, part->specification);
                print_sales_list(list, targetIndex);
                break;
            case 4:
                intBuffer = get_input_number("Enter new price: ", WITH_BOX);
                if (intBuffer != INT_INPUT_ERROR && intBuffer != -99) {
                    part->price = intBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("\nThe new price of %s is %d\n", part->partName, part->price);
                part->revenue = part->price * part->sales;
                print_sales_list(list, targetIndex);
                break;
            case 5:
                intBuffer = get_input_number("Enter new sales: ", WITH_BOX);
                if (intBuffer != INT_INPUT_ERROR && intBuffer != -99) {
                    part->sales = intBuffer;
                }
                else {
                    puts("Canceled");
                    return;
                }
                
                printf("\nThe new sales of %s is %d\n", part->partName, part->sales);
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
        clear_console();
        print_sales_list(list, targetIndex);
        printf("\n");
        _display_edit_menu();
        
        selected = get_input_number(NULL, WITHOUT_BOX);
    }
}

void create_new_part_from_input(SalesList list) {
    int partNumber;
    char *partName;
    char *specification;
    int price;
    int sales;
    
    partNumber = get_input_number("Enter part number: ", WITH_BOX);
    printf("\n");
    if (partNumber == INT_INPUT_ERROR || partNumber == -99) {
        puts("Canceled");
        return;
    }
    
    partName = get_input_string("Enter part name: ", WITH_BOX);
    printf("\n");
    if (!partName || atoi(partName) == -99) {
        puts("Canceled");
        return;
    }
    
    specification = get_input_string("Enter specification: ", WITH_BOX);
    printf("\n");
    if (!specification || atoi(specification) == -99) {
        puts("Canceled");
        free(partName);
        return;
    }
    
    price = get_input_number("Enter price: ", WITH_BOX);
    printf("\n");
    if (price == INT_INPUT_ERROR || price == -99) {
        puts("Canceled");
        free(partName);
        free(specification);
        return;
    }
    
    sales = get_input_number("Enter sales: ", WITH_BOX);
    printf("\n");
    if (sales == INT_INPUT_ERROR || sales == -99) {
        puts("Canceled");
        free(partName);
        free(specification);
        return;
    }
    
    Part newPart = new_Part(partNumber, partName, specification, price, sales);
    add_to_list(list, newPart);
    
    clear_console();

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
    println_string_cells_with_token(NULL, _COLUMN_NUM, "═", list->colomnSpaces, "╔", "╦", "╗");
    
    println_string_cells_with_token(list->colomnNames, _COLUMN_NUM, " ", list->colomnSpaces, "║", "║", "║");
    
    println_string_cells_with_token(NULL, _COLUMN_NUM, "═", list->colomnSpaces, "╠", "╬", "╣");

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
        
        // print all properties center-aligned, covered and divided by "|"
        println_string_cells_with_token(partProperties, _COLUMN_NUM, " ", list->colomnSpaces, "║", "║" ,"║");
    }
    
    /* optional thing to do when printing all */
    if (specificIndex == _LIST_ALL) {
        println_string_cells_with_token(NULL, _COLUMN_NUM, "═", list->colomnSpaces, "╠", "╬", "╣");
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
        println_string_cells_with_token(partProperties, _COLUMN_NUM, " ", list->colomnSpaces, "║", "║", "║");
        
        println_string_cells_with_token(NULL, _COLUMN_NUM, "═", list->colomnSpaces,"╚", "╩", "╝");
    }
    else {
        println_string_cells_with_token(NULL, _COLUMN_NUM, "═", list->colomnSpaces,"╚", "╩", "╝");

    }
}

void read_sales_list(const char *dataFilePath, SalesList list) {
    // opening file for reading
    FILE *fp;
    fp = fopen(dataFilePath, "rb");
    
    // if fopen returned NULL
    if (fp == NULL) {
        fprintf(stderr, "File not exist.\n");
        exit(1);
    }
    
    // buffer to store file content
    char *buffer;
    
    // get file size
    fseek(fp, 0, SEEK_END);
    int fileSize = (int)ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    // allocate memmory for size of file
    buffer = malloc(fileSize + 1);
    memset(buffer, 0, fileSize + 1);
    
    // read file and save it to buffer
    if (fread(buffer, fileSize, 1, fp) < 1) {
        free(buffer);
        fclose(fp);
        fprintf(stderr, "Failed reading file.\n");
        exit(1);
    }
    
    // done with file
    fclose(fp);
    
    // for searching, first position is 0
    int pos = 0;

    // if first character is not {, return
    if (buffer[pos] != '{') {
        fprintf(stderr, "File is not JSON.\n");
        return;
    }
    
    // clear all contents in the list
    clear_list(list);

    // add first element
    add_to_list(list, new_Part(0, allocate_string("NONE"), allocate_string("NONE"), 0, 0));

    int expectingVal = 0;
    int itemIndex = 0;
    
    char *currentKey = NULL;
    char *currentVal = NULL;
    
    Stack stack = new_Stack();

    while (pos < fileSize) {
        
        switch (buffer[pos]) {
            case '{':
                Stack_push(stack, '{');
                expectingVal = 0;
                break;
                
            case '}':
                if (Stack_pop(stack) == '{') {
                    // good
                }
                else {
                    fprintf(stderr, "File is broken. expected }\n");
                }
                break;
        
            case '"': {
                char *begin = buffer + pos + 1;

                char *end = strchr(begin, '"');
                
                if (end == NULL)
                    break;
                
                int stringLength = (int)end - (int)begin;
                
                if (expectingVal) {

                    currentVal = (char *)malloc(stringLength + 1);
                    memset(currentVal, 0, stringLength + 1);
                    memcpy(currentVal, begin, stringLength);
                    
                    if (!strcmp(currentKey, "Number")) {
                        list->parts[itemIndex]->partNum = atoi(currentVal);
                        free(currentVal);
                    }
                    else if (!strcmp(currentKey, "Name")) {
                        list->parts[itemIndex]->partName = currentVal;
                    }
                    else if (!strcmp(currentKey, "Specification")) {
                        list->parts[itemIndex]->specification = currentVal;
                    }
                    else if (!strcmp(currentKey, "Price")) {
                        list->parts[itemIndex]->price = atoi(currentVal);
                        free(currentVal);
                    }
                    else if (!strcmp(currentKey, "Sales")) {
                        list->parts[itemIndex]->sales = atoi(currentVal);
                        free(currentVal);
                    }
                    else if (!strcmp(currentKey, "Revenue")) {
                        list->parts[itemIndex]->revenue = atoi(currentVal);
                        free(currentVal);
                    }
                    expectingVal = 0;
                }
                else {
                    currentKey = (char *)malloc(stringLength + 1);
                    memset(currentKey, 0, stringLength + 1);
                    memcpy(currentKey, begin, stringLength);
                }
                pos = pos + stringLength + 1;
            }
                break;
                
            case ',':
                add_to_list(list, new_Part(0, allocate_string("NONE"), allocate_string("NONE"), 0, 0));
                itemIndex += 1;
                break;
                
            case ':':
                expectingVal = 1;
                break;
                
            default:
                break;
        }
        
        ++ pos;
    }
}

void write_sales_list(const char *dataFilePath, SalesList list) {
    FILE *fp;
    
    fp = fopen(dataFilePath, "w");
    
    fprintf(fp, "{\n");
    for (unsigned register i = 0; i < list->numberOfParts; ++ i) {
        fprintf(fp, "    {\n");
        
        fprintf(fp, "        \"");
        fprintf(fp, "Number");
        fprintf(fp, "\": \"");
        fprintf(fp, "%d", list->parts[i]->partNum);
        fprintf(fp, "\"\n");
        
        fprintf(fp, "        \"");
        fprintf(fp, "Name");
        fprintf(fp, "\": \"");
        fprintf(fp, "%s", list->parts[i]->partName);
        fprintf(fp, "\"\n");
        
        fprintf(fp, "        \"");
        fprintf(fp, "Specification");
        fprintf(fp, "\": \"");
        fprintf(fp, "%s", list->parts[i]->specification);
        fprintf(fp, "\"\n");
        
        fprintf(fp, "        \"");
        fprintf(fp, "Price");
        fprintf(fp, "\": \"");
        fprintf(fp, "%d", list->parts[i]->price);
        fprintf(fp, "\"\n");
        
        fprintf(fp, "        \"");
        fprintf(fp, "Sales");
        fprintf(fp, "\": \"");
        fprintf(fp, "%d", list->parts[i]->sales);
        fprintf(fp, "\"\n");
        
        fprintf(fp, "        \"");
        fprintf(fp, "Revenue");
        fprintf(fp, "\": \"");
        fprintf(fp, "%d", list->parts[i]->revenue);
        fprintf(fp, "\"\n");
        
        fprintf(fp, "    }");
        if (i < list->numberOfParts - 1)
            fprintf(fp,",");
        fprintf(fp, "\n");
    }
    fprintf(fp, "}");

    fclose(fp);
}

void export_sales_list(const char *exportFilePath, SalesList list, const unsigned int specificIndex) {
    /*
     In:
     [parts]: pointer of array of (Part).
     [length]: length of that array.
     [specificIndex]:
     Out: none
     Description: write all fields of element in array of (Part).
     view data in form of table.
     I used print_string_with_blank function to get center-aligned table.
     Non-string variables are converted to string to be processed as an element of char * array.
     */
    
    if ((specificIndex > list->numberOfParts - 1) && !(specificIndex & (_LIST_LAST | _LIST_ALL)))
        return;
    
    FILE *fp;
    
    fp = fopen(exportFilePath, "w");
    
    // print first row
    fprintln_string_cells_with_token(fp, NULL, _COLUMN_NUM, "═", list->colomnSpaces, "╔", "╦", "╗");
    
    fprintln_string_cells_with_token(fp, list->colomnNames, _COLUMN_NUM, " ", list->colomnSpaces, "║", "║", "║");
    
    fprintln_string_cells_with_token(fp, NULL, _COLUMN_NUM, "═", list->colomnSpaces, "╠", "╬", "╣");
    
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
        
        // print all properties center-aligned, covered and divided by "|"
        fprintln_string_cells_with_token(fp, partProperties, _COLUMN_NUM, " ", list->colomnSpaces, "║", "║" ,"║");
    }
    
    /* optional thing to do when printing all */
    if (specificIndex == _LIST_ALL) {
        fprintln_string_cells_with_token(fp, NULL, _COLUMN_NUM, "═", list->colomnSpaces, "╠", "╬", "╣");
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
        fprintln_string_cells_with_token(fp, partProperties, _COLUMN_NUM, " ", list->colomnSpaces, "║", "║", "║");
        
        fprintln_string_cells_with_token(fp, NULL, _COLUMN_NUM, "═", list->colomnSpaces,"╚", "╩", "╝");
    }
    else {
        fprintln_string_cells_with_token(fp, NULL, _COLUMN_NUM, "═", list->colomnSpaces,"╚", "╩", "╝");
        
    }
    fclose(fp);
    
    printf("Exported to %s\n", exportFilePath);
}


//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//


