//
//  util.c
//  to-do-list
//
//  Created by MacBoogy on 2018. 4. 10..
//  Copyright © 2018년 potados. All rights reserved.
//

#include "util.h"

void error(const char *mes) {
    fprintf(stderr, "%s\n", mes);
    exit(1);
}

string slice_time(const string timeString, size_t start, size_t end) {
    char sliced[20];
    size_t i = 0;
    size_t j = 0;
    for (i = start; i <= end; ++i) {
        sliced[j++] = timeString[i];
    }
    sliced[j] = 0;
    
    string p = (char *)malloc(strlen(sliced)+1);
    strcpy(p, sliced);
    
    return p;
}
