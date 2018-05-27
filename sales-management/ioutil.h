//
//  ioutil.h
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//

#ifndef ioutil_h
#define ioutil_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _BUFFER_SIZE 64
#define _SMALL_BUFFER_SIZE 16
#define _COLUMN_NUM 7

#define STRING_FLOW_DIRECTION_RIGHT 1
#define STRING_FLOW_DIRECTION_LEFT 2

#define True 1
#define False 0

typedef int bool;

/* private */
void _int_to_string(char * dest, const int num);
void _int_to_string_with_comma(char *dest, const int num);
int _get_sum(const int *nums, const int count);

/* public */
char *get_input_string(void);
int get_input_number(void);

char *allocate_string(const char *buffer);

void println_string_cells_with_token(const char **string,
                                     const int stringCount ,
                                     const char token,
                                     const int *tokenLengths,
                                     const char border);

void println_string_with_token(const char *string,
                               const char token,
                               const int tokenLength,
                               const char border);

void print_string_with_token(const char *string,
                             const char token,
                             const int tokenLength,
                             const char border);

void println_token(const char token, const unsigned int length);
void print_token(const char token, const unsigned int length);

void wait_for_enter(void);

void print_moving_string(const char *string, const int flowDirection, const int speed, const int boxLength, const char boxBorderLeft, const char boxBorderRight);

#endif /* ioutil_h */

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
