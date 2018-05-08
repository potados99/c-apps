//
//  symmetricmatrix.h
//  C20180508
//
//  Created by POTADOS on 2018. 5. 8..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef symmetricmatrix_h
#define symmetricmatrix_h

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define SQUARE_SIZE 5

void do_assignment(void);

void symmetry_diagonal(int **original, int **symmetry, int row_size, int column_size);
void symmetry_left_right(int **original, int **symmetry, int row_size, int column_size);
void symmetry_up_down(int **original, int **symmetry, int row_size, int column_size);
void symmetry_opposite_diagonal(int **original, int **symmetry, int row_size, int column_size);

void error(const char *message);

#endif /* symmetricmatrix_h */
