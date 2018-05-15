//
//  symmetricmatrix.c
//  C20180508
//
//  Created by POTADOS on 2018. 5. 8..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "symmetricmatrix.h"

void do_assignment() {
    int **matrix = get_matrix(SQUARE_SIZE, SQUARE_SIZE, FILL_RANDOM);
    int **symmetry = get_matrix(SQUARE_SIZE, SQUARE_SIZE, FILL_NONE);
    
    puts("Original matrix");
    print_matrix(matrix, SQUARE_SIZE, SQUARE_SIZE);
    
    puts("\nDiagonal symmetric matrix");
    symmetry_diagonal(matrix, symmetry, SQUARE_SIZE, SQUARE_SIZE);
    print_matrix(symmetry, SQUARE_SIZE, SQUARE_SIZE);
    
    puts("\nUp-down symmetric matrix");
    symmetry_up_down(matrix, symmetry, SQUARE_SIZE, SQUARE_SIZE);
    print_matrix(symmetry, SQUARE_SIZE, SQUARE_SIZE);
    
    puts("\nLeft-right symmetric matrix");
    symmetry_left_right(matrix, symmetry, SQUARE_SIZE, SQUARE_SIZE);
    print_matrix(symmetry, SQUARE_SIZE, SQUARE_SIZE);
    
    puts("\nOpposite-Diagonal symmetric matrix");
    symmetry_opposite_diagonal(matrix, symmetry, SQUARE_SIZE, SQUARE_SIZE);
    print_matrix(symmetry, SQUARE_SIZE, SQUARE_SIZE);
    
}

void symmetry_diagonal(int **original, int **symmetry, int row_size, int column_size) {
    if (row_size != column_size)
        error("not square");
    
    register unsigned i, j;
    for (i = 0; i < row_size; i ++) {
        for (j = 0; j < column_size; j ++) {
            symmetry[i][j] = original[j][i];
        }
    }
}

void symmetry_left_right(int **original, int **symmetry, int row_size, int column_size) {
    if ((column_size / 2) * 2 == column_size)
        error("column size is even");
    
    register unsigned i, j;
    for (i = 0; i < row_size; i ++) {
        for (j = 0; j < column_size; j ++) {
            symmetry[i][j] = original[i][column_size - 1 - j];
        }
    }
}

void symmetry_up_down(int **original, int **symmetry, int row_size, int column_size) {
    if ((row_size / 2) * 2 == row_size)
        error("row size is even");
    
    register unsigned i, j;
    for (i = 0; i < row_size; i ++) {
        for (j = 0; j < column_size; j ++) {
            symmetry[i][j] = original[row_size - 1 - i][j];
        }
    }
}

void symmetry_opposite_diagonal(int **original, int **symmetry, int row_size, int column_size) {
    if (row_size != column_size)
        error("not square");
    
    register unsigned i, j;
    for (i = 0; i < row_size; i ++) {
        for (j = 0; j < column_size; j ++) {
            symmetry[i][j] = original[column_size - 1 -j][row_size - 1 -i];
        }
    }
}

void error(const char *message) {
    fprintf(stderr, "%s", message);
}
