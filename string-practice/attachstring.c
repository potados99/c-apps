//
//  main.c
//  string-attach
//
//  Created by POTADOS on 2018. 5. 15..
//  Copyright © 2018년 POTADOS. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char buffer[30];
    char *string = (char *)malloc(sizeof(char) * 1);
    
    printf("Input memo: ");
    fgets(buffer , 30, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    
    while (strcmp(buffer, "end")) {
        string = realloc(string, sizeof(char) * ( strlen(string) + strlen(buffer) ));
        strcat(string, buffer);
        strcat(string, " ");
        
        printf("Input memo: ");
        fgets(buffer , 30, stdin);
        buffer[strlen(buffer) - 1] = '\0';
    }
    
    printf("%s\n", string);
}






