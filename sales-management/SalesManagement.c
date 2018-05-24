//
//  SalesManagement.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#include "SalesManagement.h"

SalesList new_SalesList(void) {
    SalesList list = (_SalesList *)malloc(sizeof(_SalesList));
    
    list->parts = (Part *)malloc(sizeof(Part) * 0);
    list->numberOfParts = 0;
    
    return list;
}


void create_new_part_from_input(SalesList list) {
    
    ///
    /// Purpose: to get a
    ///
    
    int partNumber;
    char *partName;
    char *specification;
    int price;
    int sales;
    
    printf("Enter part number: ");
    partNumber = get_input_number();
    
    printf("Enter part name: ");
    partName = get_input_string();
    
    printf("Enter specification: ");
    specification = get_input_string();
    
    printf("Enter price: ");
    price = get_input_number();
    
    printf("Enter sales: ");
    sales = get_input_number();
    
    Part newPart = new_Part(partNumber, partName, specification, price, sales);
    add_to_list(list, newPart);
    
    puts("\nAdded: ");
    print_parts(list->parts, list->numberOfParts, LIST_LAST);
}

void add_to_list(SalesList list, Part part) {
    list->parts = (Part *)realloc(list->parts, sizeof(Part) * (++ list->numberOfParts));
    list->parts[list->numberOfParts - 1] = part;
}


void start_main_loop(SalesList list) {
    display_main_menu();
    
	int selected = 0;
	rewind(stdin);

	while ((selected = getchar() - '0') != 4) {
		rewind(stdin);
        
        bool escapedFromEdit = False;
        
		switch (selected) {
			case 1:
                puts("");
				print_sales_list(list);
				break;
			case 2:
                puts("");
                create_new_part_from_input(list);
				break;
			case 3:
                puts("");
                print_sales_list(list);
                puts("");
                start_edit_loop(list);
                escapedFromEdit = True;
				break;
			default:
				break;
		}
        if (! escapedFromEdit )
            wait_for_enter();
        
        rewind(stdin);
        display_main_menu();
	}
	printf("Exiting program.\n");
}

void start_edit_loop(SalesList list) {
    int targetIndex = 0;
    printf("Enter the index of part you want to edit: ");
    
    while (((targetIndex = getchar() -'0') < 0) || (targetIndex >= list->numberOfParts))
        printf("Enter proper index!");
    
    puts("");
    print_parts(list->parts, list->numberOfParts, targetIndex);
    wait_for_enter();
    
    display_edit_menu();
    
    int selected = 0;
    Part part = list->parts[targetIndex];
    rewind(stdin);
    
    selected = getchar() - '0';
    int breakMe = 0;
    
    while (1) {
        rewind(stdin);
        
        breakMe = 0;
        puts("");
        switch (selected) {
            case 1:
                printf("Enter new product number: ");
                part->partNum = get_input_number();
                printf("The new product number of %s is %d\n\n", part->partName, part->partNum);
                print_parts(list->parts, list->numberOfParts, targetIndex);
                break;
            case 2:
                printf("Enter new product name: ");
                char *oldName = part->partName;
                part->partName = get_input_string();
                printf("The new product name of %s is %s\n\n", oldName, part->partName);
                print_parts(list->parts, list->numberOfParts, targetIndex);
                break;
            case 3:
                printf("Enter new specification: ");
                part->specification = get_input_string();
                printf("The new specification of %s is %s\n\n", part->partName, part->specification);
                print_parts(list->parts, list->numberOfParts, targetIndex);
                break;
            case 4:
                printf("Enter new price: ");
                part->price = get_input_number();
                printf("The new price of %s is %d\n\n", part->partName, part->price);
                print_parts(list->parts, list->numberOfParts, targetIndex);
                part->revenue = part->price * part->sales;
                break;
            case 5:
                printf("Enter new sales: ");
                part->sales = get_input_number();
                printf("The new sales of %s is %d\n\n", part->partName, part->sales);
                print_parts(list->parts, list->numberOfParts, targetIndex);
                part->revenue = part->price * part->sales;
                break;
            case 6:
                breakMe = 1;
                break;
                
            default:
                break;
        }
        if (breakMe)
            break;
        wait_for_enter();
        display_edit_menu();
        
        selected = getchar() - '0';
    }
}

void display_main_menu() {
	puts("==== Main menu ====");
	puts("1. Show sales data");
	puts("2. Add new part");
	puts("3. Edit part info");
	puts("4. Exit");
	puts("===================");
    printf("> ");
}

void display_edit_menu() {
    puts("==== To edit ====");
    puts("1. Product number");
    puts("2. Product name");
    puts("3. Specification");
    puts("4. Price");
    puts("5. Sales");
    puts("6. Back");
    puts("=================");
    printf("> ");
}


void print_sales_list(SalesList list) {
    print_parts(list->parts, list->numberOfParts, LIST_ALL);
}

void print_parts(Part *parts, const unsigned int length, const unsigned int specificIndex) {
    
    ///
    /// print_sales
    /// Purpose: to display sales data in form of table
    /// Description: I used print_string_with_blank function to get center-aligned table.
    ///             Non-string variables are converted to string to be processed as an element of char * array.
    ///
    
    if ((specificIndex > length - 1) && !(specificIndex & (LIST_LAST | LIST_ALL)))
        return;
    static char *colomnNames[_COLUMN_NUM] = {"Index", "Number", "Name", "Specification", "Price", "Sales", "Revenue"};
    static int spaces[_COLUMN_NUM] = {8, 11, 17, 20, 12, 10, 10};
    
    print_string_with_blank(colomnNames, _COLUMN_NUM, spaces); /* print top row in center-aligned form */
    print_divider(spaces); /* print a row for division */
    
    int begin = 0;
    int end = 0;
    
    if (specificIndex == LIST_ALL) {
        begin = 0;
        end = length;
    }
    else if (specificIndex == LIST_LAST) {
        begin = length - 1;
        end = length;
    }
     else {
        begin = specificIndex;
        end = specificIndex + 1;
    }
        
    for (int i = begin; i < end; ++ i) {
        
        /* buffers to contain the converted variables */
        char index[_SMALL_BUFFER_SIZE];
        char num[_SMALL_BUFFER_SIZE];
        char price[_SMALL_BUFFER_SIZE];
        char sales[_SMALL_BUFFER_SIZE];
        char revenue[_SMALL_BUFFER_SIZE];
        
        /* int to string */
        itos(index, i);
        itos(num, parts[i]->partNum);
        itos(price, parts[i]->price);
        itos(sales, parts[i]->sales);
        itos(revenue, parts[i]->revenue);
        
        char *partProperties[_COLUMN_NUM] = { index, num, parts[i]->partName, parts[i]->specification, price, sales, revenue };
        
        print_string_with_blank(partProperties, _COLUMN_NUM, spaces);
    }
}

