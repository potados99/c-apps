//
//  ioutil.h
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef ioutil_h
#define ioutil_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _BUFFER_SIZE 64
#define _SMALL_BUFFER_SIZE 16
#define _COLUMN_NUM 7

#define True 1
#define False 0

typedef int bool;

char *get_input_string(void);

int get_input_number(void);

void print_string_with_blank(char **string, int count , int * spaces);

void print_divider(int *spaces);

void print_blank(const unsigned int length);

void itos(char * str, int i);

void wait_for_enter(void);

#endif /* ioutil_h */
