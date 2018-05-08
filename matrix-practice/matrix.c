//
//  matrix.c
//  C20180508
//
//  Created by POTADOS on 2018. 5. 8..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "matrix.h"

int **get_matrix(int rows, int columns, int fillRandom) {
    /* init  */
    int **matrix = (int **)malloc(sizeof(int *) * rows);
    register unsigned i, j;
    for (i = 0; i < rows; i ++) {
        *(matrix + i) = (int *)malloc(sizeof(int) * columns);
    }
    
    if (fillRandom) {
        static int seed = 0;
        srand((unsigned)time(NULL) + (seed++));
        for (i = 0; i < rows; i ++) {
            for (j = 0; j < columns; j ++) {
                matrix[i][j] = rand() % 100 + 1;
            }
        }
    }
    
    return matrix;
}

void print_matrix(int **matrix, int row_size, int columns_size) {
    register unsigned i, j;
    for (i = 0; i < row_size; i ++) {
        for (j = 0; j < columns_size; j ++) {
            if ((matrix[i][j] - 10) < 0)
                printf(" ");
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
