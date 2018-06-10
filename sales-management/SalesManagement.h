//
//  SalesManagement.h
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//

#ifndef SalesManagement_h
#define SalesManagement_h

#include <stdio.h>
#include <stdlib.h>
#include "Part.h"
#include "ioutil.h"
#include "linkedStack.h"

#define _LIST_ALL 0x01000000
#define _LIST_LAST 0x10000000

#define _MAIN_MENU_WIDTH 25
#define _EDIT_MENU_WIDTH 25

typedef struct _SalesList {
    Part *parts;
    const char **colomnNames;
    const int *colomnSpaces;
    int numberOfParts;
} _SalesList;
typedef _SalesList * SalesList;

/* private */
void _display_main_menu(void);
void _display_edit_menu(void);

/* public */
SalesList new_SalesList(const char **columnNames, const int *columnSpaces);
void clear_list(SalesList list);
void destructor(SalesList list);
void start_main_loop(const char *dataFilePath, const char *exportFilePath, SalesList list);
void start_edit_loop(SalesList list);
void create_new_part_from_input(SalesList list);
void add_to_list(SalesList list, Part part);
void print_sales_list(SalesList list, const unsigned int specificIndex);
void read_sales_list(const char *dataFilePath, SalesList list);
void write_sales_list(const char *dataFilePath, SalesList list);
void export_sales_list(const char *exportFilePath, SalesList list, const unsigned int specificIndex);

#endif /* SalesManagement_h */

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
