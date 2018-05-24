//
//  ioutil.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "ioutil.h"

///
/// get_input_string
/// Purpose: to get a dynamic-allocated string from user input
///
char *get_input_string() {
    char buffer[_BUFFER_SIZE];
    rewind(stdin);
    fgets(buffer, _BUFFER_SIZE - 1, stdin);
    rewind(stdin);

    buffer[strlen(buffer) - 1] = '\0';
    
    char *string = (char *)malloc(sizeof(char) * strlen(buffer));
    strcpy(string, buffer);
    
    return string;
}

int get_input_number() {
    char buffer[_BUFFER_SIZE];
    rewind(stdin);
    fgets(buffer, _BUFFER_SIZE - 1, stdin);
    rewind(stdin);

    return atoi(buffer);
}

///
/// print_string_with_blank
/// Purpose: to print string center-aligned in a cell, divied by '|' character
/// Description: unless the length of string does not over the size of that cell, the size of cell doesn't change
///
void print_string_with_blank(char **string, int count , int * spaces) {
    for (int i = 0; i < count; ++ i) {
        printf("|");
        print_blank((spaces[i] - (int)strlen(string[i]) - 1) / 2);
        printf("%s", string[i]);
        print_blank((spaces[i] - (int)strlen(string[i])) / 2);
    }   printf("|\n");
}

///
/// print_divider
/// Purpose: to print a line to divide rows
/// Description: print equal symbol for (count of spaces) times
///
void print_divider(int *spaces) {
    int count = 0;
    for (unsigned register int i = 0; i < _COLUMN_NUM; ++ i) {
        count += spaces[i];
    }
    for (unsigned register int i = 0; i < count + 1; ++ i) {
        printf("=");
    } printf("\n");
}

///
/// print_black
/// Purpose: just to print blank character for (length) times
///
void print_blank(const unsigned int length) {
    for (unsigned register int i = 0; i < length; ++ i)
        printf(" ");
}

///
/// itos
/// Purpose: to convert integer to string
///
void itos(char *str, int i) {
    sprintf(str, "%d", i);
}

void wait_for_enter() {
    rewind(stdin);
    printf("\nPress enter.\n");
    while(getchar() != 10);/* CR */
    rewind(stdin);
}
