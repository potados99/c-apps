//
//  ioutil.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "ioutil.h"

///
/// itos
/// Purpose: to convert integer to string
///
void _int_to_string(char *dest, const int num) {
    sprintf(dest, "%d", num);
}

void _int_to_string_with_comma(char *dest, const int num) {
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
    int sum = 0;
    for (unsigned register int i = 0; i < count; ++ i) {
        sum += nums[i];
    }
    return sum;
}


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
void println_string_cells_with_token(const char **string, const int stringCount , const char token, const int *tokenLength, const char border) {
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



///
/// print_black
/// Purpose: just to print blank character for (length) times
///
void println_token(const char token, const unsigned int length) {
    print_token(token, length);
    puts("");
}

void print_token(const char token, const unsigned int length) {
    for (unsigned register int i = 0; i < length; ++ i)
        printf("%c", token);
}


void wait_for_enter() {
    rewind(stdin);
    printf("\nPress enter.\n");
    while(getchar() != 10);/* CR */
    rewind(stdin);
}
