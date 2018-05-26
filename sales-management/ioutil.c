//
//  ioutil.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018년 POTADOS. All rights reserved.
//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//

#include "ioutil.h"


void _int_to_string(char *dest, const int num) {
    /*
     In: [num]
     Out: [dest]
     Description: convert integer to string
     */
    
    sprintf(dest, "%d", num);
}

void _int_to_string_with_comma(char *dest, const int num) {
    /*
     In: [num]
     Out: [dest]
     Description: convert integer to string with comma inserted
     */
    
    /*
     state table:
     
     1 2 , 3 4 5 , 6 7 8 (8 digits)
     
     val    1   2   3   4   5   6   7   8
     index  0   1   2   3   4   5   6   7
     i      0   1
     j              2   3   4   5   6   7
     comma? n   n   y   n   n   y
     
     if ((j % 3) == (strlen(buffer) % 3))
        // insert comma before number
     */
    
    char buffer[_SMALL_BUFFER_SIZE];
    sprintf(buffer, "%d", num);
    
    unsigned int index = 0;
    unsigned int length = (unsigned int)strlen(buffer);
    unsigned int rest = length % 3;
    bool noFirstComma = False;
    if (! rest)
        noFirstComma = True;

    for (register unsigned int i = 0; i < rest; ++ i) {
        dest[index ++] = buffer[i];
    }
    
    for (register unsigned int j = rest; j < length; ++ j) {
        if ((j % 3) == (rest))
            if (!(j == rest) || !noFirstComma)
                dest[index ++] = ',';
        // do nothing when it is first turn and noFirstComma is True
        dest[index ++] = buffer[j];
    }
    dest[index] = '\0';
}

int _get_sum(const int *nums, const int count) {
    /*
     In: [num], [count]
     Out: [sum]
     Description: add every number in nums to sum
     */
    
    int sum = 0;
    for (unsigned register int i = 0; i < count; ++ i) {
        sum += nums[i];
    }
    return sum;
}


char *get_input_string() {
    /*
     In: none
     Out: [string]
     Description: get a dynamic-allocated string from user input.
     reject when it gets wrong input.
     */
    
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
    /*
     In: none
     Out: atoi(buffer)
     Description: get a number from user input.
     reject when it gets wrong input.
     */
    
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

char *allocate_string(const char *buffer) {
    /*
     In:
     [buffer]: array of char
     Out:
     [string]: pointer of allocated memmory
     Description: allocate memmory for string
     */
    char *string = (char *)malloc(sizeof(char) * strlen(buffer));
    strcpy(string, buffer);
    return string;
}

void println_string_cells_with_token(const char **string, const int stringCount , const char token, const int *tokenLength, const char border) {
    /*
     In:
     [string]: pointer of array of (char *) type string
     [stringCount]: number of string
     [token]: (char) type character. used to fill empty space
     [tokenLengths]: pointer of array of (int) type number.
     each element indicates the length of each cell
     [border]: (char) type character. printed at head and tail.
     Out: none
     Description: print strings in horizontal-oriented cells which are divided by [border].
     in each cell, string is center-aligned.
     empty space in the cell is filled with [token]
     */
    
    for (int i = 0; i < stringCount; ++ i) {
        printf("%c", border);
        
        if (string) {
            print_token(token, (tokenLength[i] - (int)strlen(string[i]) - 1) / 2);
            printf("%s", string[i]);
            print_token(token, (tokenLength[i] - (int)strlen(string[i])) / 2);
        }
        else {
            print_token('-', tokenLength[i]);
        }
        
    }   printf("%c\n", border);
}

void println_string_with_token(const char *string, const char token, const int tokenLength, const char border) {
    print_string_with_token(string, token, tokenLength, border);
    puts("");
}

void print_string_with_token(const char *string, const char token, const int tokenLength, const char border) {
    /*
     In:
     [string]: pointer of (char *) type string
     [token]: (char) type character. used to fill empty space
     [tokenLength]: pointer of (int) type number. the length of cell.
     [border]: (char) type character. printed at head and tail.
     Out: none
     Description: print string in a cell which is covered by [border].
     in that cell, string is center-aligned.
     empty space in the cell is filled with [token]
     */
    
    printf("%c", border);
    
    if (string) {
        print_token(token, (tokenLength - (int)strlen(string) - 1) / 2);
        printf("%s", string);
        print_token(token, (tokenLength - (int)strlen(string)) / 2);
    }
    else {
        print_token(token, tokenLength - 1);
    }
    
    printf("%c", border);
}

void println_token(const char token, const unsigned int length) {
    print_token(token, length);
    puts("");
}

void print_token(const char token, const unsigned int length) {
    /*
     In: [token], [length]
     Out: none
     Description: print [length] of tokens
     */
    
    for (unsigned register int i = 0; i < length; ++ i)
        printf("%c", token);
}


void wait_for_enter() {
    /*
     In: none
     Out: none
     Description: ask user for input until it gets '\n'
     */
    
    rewind(stdin);
    printf("\nPress enter.\n");
    while(getchar() != 10);/* CR */
    rewind(stdin);
}

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//