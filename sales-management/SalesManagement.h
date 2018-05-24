//
//  SalesManagement.h
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
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

SalesList new_SalesList(void);

void add_to_sales_list(SalesList list, Part part);

void start_main_loop(SalesList list);

void start_edit_loop(SalesList list);

void display_main_menu(void);

void display_edit_menu(void);

void add_new_part_from_input(SalesList list);

void print_parts(Part *parts, const unsigned int length, const unsigned int specificIndex);

void print_sales_list(SalesList list);


#endif /* SalesManagement_h */
