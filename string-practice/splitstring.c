//
//  splitstring.c
//  string-practice
//
//  Created by POTADOS on 2018. 4. 18..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "splitstring.h"

char **split(char *arr, const char token) {
    int n = 10;
    char **splited = (char **)malloc(sizeof(char *) * n);
   
    register unsigned short i;
    for (i = 0; i < n; i ++) {
        *(splited + i) = NULL;
    }
   
    printf("\n");
    
    char tmp[50] = "";
    char *dest = tmp;
    char *sour = arr;
    unsigned short index = 0;
    
    printf("Split by token \n");
    
    while (1) {
        if (*sour == token) {
            *dest = '\0';
            strcpy(*(splited + index ++), tmp);
            strcpy(tmp, "");
            dest = tmp;
            sour += 1;
        }
        else if (*sour == '\0') {
            *dest = '\0';
            strcpy(*(splited + index ++), tmp);
            break;
        }
        else {
            *dest = *sour;
            sour += 1;
            dest += 1;
        }
    }
    
    return splited;
}
