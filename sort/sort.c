//
//  bubblesort.c
//  sort
//
//  Created by POTADOS on 2018. 5. 23..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "sort.h"

void selection_sort(student *students, const unsigned int length) {
    for (int i = 0; i < length - 1; ++ i) {
        int minIndex = i;
        for (int j = i + 1; j < length; ++ j)
            if (students[j].ID < students[minIndex].ID)
                minIndex = j;
        
        swap(&students[i], &students[minIndex]);
    }
}

// Need to refactor. ugly
void insertion_sort(student *students, const unsigned int length) {
    int i, j;
    student remember;
    
    for (i = 1; i < length; ++ i) {
        j = i;
        remember = students[j];
        while (((-- j)>= 0) && (remember.ID < students[j].ID)) {
            students[j + 1] = students[j];
            students[j] = remember;
        }
    }
}

void bubble_sort(student *students, const unsigned int length) {
    for (int i = length - 1; i > 0; -- i)
        for (int j = 0; j < i; ++ j)
            if (students[j].ID > students[j + 1].ID)
                swap(&students[j], &students[j + 1]);
}

void swap(student *A, student *B) {
    student temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

