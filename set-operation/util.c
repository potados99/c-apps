//
//  util.c
//  Set_calculation
//
//  quickSort source code from <https://ko.wikipedia.org/wiki/퀵_정렬>
//
//  check_not_int inspired by Mihddy and HamBP
//
//  Created by B.J.Song on 2018. 3. 25..
//  Copyright © 2018년 B.J.Song. All rights reserved.
//

#include "util.h"

int check_that_exists(Arr Array, int element) {
    int exist = 0;
    int i = 0;
    for (i = 0; i <= Array.size - 1; i ++) {
        if (Array.array[i] == element)
            exist = 1;
    }
    return exist;
}

int check_not_int(char string[]) {
    int i = 0;
    for (i = 0; i <= string[i]; i ++) {
        if (!(string[i] >= '0' && string[i] <= '9')) /* character exists */
            return 1;
    }
    return 0;
}

int check_length_over(char *string, int len) {
    return ((strlen(string) > len));
}

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp;
    do {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i<= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i<= j);
    
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    
    if (i < right)
        quickSort(arr, i, right);
}

