//
//  IO.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "IO.h"

char *get_input_string(void) {
    char buffer[_BUFFER_SIZE];
    fgets(buffer, _BUFFER_SIZE - 1, stdin);
    
    char *string = (char *)malloc(sizeof(char) * strlen(buffer));
    strcpy(string, buffer);
    
    return string;
}

void print_string_with_blank(char **string, int count , int * spaces) {
    for (int i = 0; i < count; ++ i) {
        printf("|");
        print_blank((spaces[i] - (int)strlen(string[i])) / 2);
        printf("%s", string[i]);
        print_blank((spaces[i] - (int)strlen(string[i]) - 1) / 2);
    }   printf("|\n");

}

void print_divider(int *spaces) {
    int count = 0;
    for (unsigned register int i = 0; i < 5; ++ i) {
        count += spaces[i];
    }
    for (unsigned register int i = 0; i < count + 1; ++ i) {
        printf("=");
    } printf("\n");
}

void print_blank(const unsigned int length) {
    for (unsigned register int i = 0; i < length; ++ i)
        printf(" ");
}

void itos(char *str, int i) {
    sprintf(str, "%d", i);
}
