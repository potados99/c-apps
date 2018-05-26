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

#define LIST_ALL 0x01000000
#define LIST_LAST 0x10000000

typedef struct _SalesList {
    Part *parts;
    int numberOfParts;
} _SalesList;
typedef _SalesList * SalesList;

/* private */
void _display_main_menu(void);
void _display_edit_menu(void);
void _print_parts(Part *parts, const unsigned int length, const unsigned int specificIndex);

/* public */
SalesList new_SalesList(void);
void destructor(SalesList list);
void start_main_loop(SalesList list);
void start_edit_loop(SalesList list);
void create_new_part_from_input(SalesList list);
void add_to_list(SalesList list, Part part);
void print_sales_list(SalesList list);

#endif /* SalesManagement_h */

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
