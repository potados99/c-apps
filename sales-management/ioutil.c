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

    while (strlen(buffer) == 1) {
        printf("**Enter proper value: ");
        rewind(stdin);
        fgets(buffer, _BUFFER_SIZE - 1, stdin);
        rewind(stdin);
    }
    buffer[strlen(buffer) - 1] = '\0';
    
    char *string = (char *)malloc(sizeof(char) * strlen(buffer));
    strcpy(string, buffer);
    
    return string;
}

int get_input_number() {
    char buffer[_BUFFER_SIZE];
    rewind(stdin);
    fgets(buffer, _BUFFER_SIZE - 1, stdin);
    
    while (strlen(buffer) == 1) {
        printf("**Enter proper value: ");
        rewind(stdin);
        fgets(buffer, _BUFFER_SIZE - 1, stdin);
        rewind(stdin);
    }
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
void int_to_string(char *_dest, const int num) {
    sprintf(_dest, "%d", num);
}

void int_to_string_with_comma(char *_dest, const int num) {
    char buffer[_SMALL_BUFFER_SIZE];
    sprintf(buffer, "%d", num);
    
    /*
     1 2 , 3 4 5 , 6 7 8 (8 digits)
     
     val    1   2   3   4   5   6   7   8
     index  0   1   2   3   4   5   6   7
     i      0   1
     j              2   3   4   5   6   7
     comma n   n   y   n   n   y
     
     if ((j % 3) == (strlen(buffer) % 3))
     */
    
    unsigned int index = 0;
    unsigned int length = (unsigned int)strlen(buffer);
    unsigned int rest = length % 3;
    bool noFirstComma = False;
    if (! rest)
        noFirstComma = True;
    
    for (register unsigned int i = 0; i < rest; ++ i) {
        _dest[index ++] = buffer[i];
    }
    
    for (register unsigned int j = rest; j < length; ++ j) {
        if ((j % 3) == (rest))
            if (!(j == rest) || !noFirstComma)
                _dest[index ++] = ',';
            // do nothing when it is first turn and noFirstComma is True
        _dest[index ++] = buffer[j];
    }
    _dest[index] = '\0';
    
}

void wait_for_enter() {
    rewind(stdin);
    printf("\nPress enter.\n");
    while(getchar() != 10);/* CR */
    rewind(stdin);
}
