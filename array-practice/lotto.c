//
//  lotto.c
//  rand-test
//
//  Created by POTADOS on 2018. 4. 18..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "lotto.h"

int *create_random_array(const int length) {
    int *randomArray = (int *)malloc(sizeof(int)*length);
    
    srand((unsigned int)time(NULL));
    
    register unsigned short i, j;
    for (i = 0; i < length; i ++) {
        *(randomArray + i) = rand() % 45 + 1;
        for (j = 0; j < i; j ++) {
            if (*(randomArray + i) == *(randomArray + j)) {
                i -= 1;
                break;
            }
        }
    }
    
    return randomArray;
}

void sort(int *arr, const int n) {
    register unsigned short i, j, indexMin;
    short temp;
    
    for (i = 0; i < n - 1; i ++) {
        indexMin = i;
        for (j = i + 1; j < n; j ++) {
            if (*(arr + j) < *(arr + indexMin)) {
                indexMin = j;
            }
        }
        temp = *(arr + indexMin);
        *(arr + indexMin) = *(arr + i);
        *(arr + i) = temp;
    }

    
}

