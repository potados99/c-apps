//
//  main.c
//  string-practice
//
//  Created by POTADOS on 2018. 5. 15..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "attachstring.h"

void attach_string_test() {
    char *string = get_new_string(1);
    char buffer[0x100];
    
    catch_input(buffer, 30);
    while (strcmp(buffer, "end")) {
        attach_string(&string, buffer);
        catch_input(buffer, 30);
    }
    puts(string);
    free(string);
    
    return;
}

void attach_string(char **dest, const char *src) {
    char *temp = realloc(*dest, sizeof(char) * (strlen(*dest) + strlen(src)));
    if (!temp) exit(-1);
    *dest = temp;
    
    strcat(*dest, src);
    strcat(*dest, " ");
}

void catch_input(char *buffer, const int maxLength) {
    printf("Input memo: ");
    fgets(buffer, maxLength, stdin);
    buffer[strlen(buffer) - 1] = '\0';
}

char *get_new_string(const int length) {
    char *string = (char *)malloc(sizeof(char) * length);
    return string;
}
