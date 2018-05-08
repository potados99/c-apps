//
//  matrix.h
//  C20180508
//
//  Created by POTADOS on 2018. 5. 8..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef matrix_h
#define matrix_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define FILL_RANDOM 1
#define EMPTY 0

int **get_matrix(int rows, int columns, int fillRandom);

void print_matrix(int **matrix, int row_size, int columns_size);

#endif /* matrix_h */
