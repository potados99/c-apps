//
//  array.c
//  Set_calculation
//
//  Created by B.J.Song on 2018. 3. 25..
//  Copyright © 2018년 B.J.Song. All rights reserved.
//

#include "array.h"
#include "util.h"
#include "locale.h"

Arr init_array(int size) {
    Arr Array;
    Array.size = size;
    Array.array = (int*) malloc(sizeof(int)*size);

    return Array;
}

Arr append_array(Arr Array, int element) {
    Array.array = (int*) realloc(Array.array, sizeof(int)*(Array.size + 1));
    Array.array[Array.size ++] = element;
    
    return Array;
}

Arr copy_array(Arr Array) {
    Arr Array_copy;
    Array_copy = init_array(0);
    
    int i = 0;
    for (i = 0; i <= Array.size - 1; i ++) {
        Array_copy = append_array(Array_copy, Array.array[i]);
    }
    
    return Array_copy;
}

Arr extend_array(Arr Array1, Arr Array2) {
    Arr Array;
    Array = init_array(0);
    
    int i = 0;
    for (i = 0; i <= Array1.size - 1; i ++) {
        Array = append_array(Array, Array1.array[i]);
    }
    for (i = 0; i <= Array2.size - 1; i ++) {
        Array = append_array(Array, Array2.array[i]);
    }
    
    return Array;
}

Arr user_input_array() {
    Arr Array;
    Array = init_array(0);
    char currentInput[100];
    
    printf(inputIntegerForIndex_d[language], Array.size);
    fgets(currentInput, 99, stdin);
    currentInput[strlen(currentInput) - 1] = '\0';
    
    while (currentInput[0]) {

        if (check_length_over(currentInput, 9)){
            printf("%s", inputTooLong[language]);
        }
        else if (check_not_int(currentInput)) {
            printf("%s", inputInteger[language]);
        }
        else if (check_that_exists(Array, atoi(currentInput))) {
            printf(d_alreadyExists[language], atoi(currentInput));
        }
        else {
            Array = append_array(Array, atoi(currentInput));
        }
        
        printf(inputIntegerForIndex_d[language], Array.size);
        fgets(currentInput, 99, stdin);
        currentInput[strlen(currentInput) - 1] = '\0';
    }
    
    return Array;
}

void sort_array(Arr Array){
    quickSort(Array.array, 0, Array.size - 1);
}

void print_array(Arr Array) {
    printf("{");
    int i = 0;
    for (i = 0; i <= Array.size - 1; i ++) {
        if (i == Array.size - 1) {
            printf("%d", Array.array[i]);
        } else {
            printf("%d, ", Array.array[i]);
        }
    }
    printf("}");
}
