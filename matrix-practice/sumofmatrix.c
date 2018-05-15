//
//  sumofmatrix.c
//  C20180508
//
//  Created by POTADOS on 2018. 5. 8..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "sumofmatrix.h"

void do_practice_3() {
    int **a = get_matrix(3, 3, FILL_RANDOM);
    int **b = get_matrix(3, 3, FILL_RANDOM);
    int **sum = get_matrix(3, 3, FILL_NONE);
    
    add_matrix(a, b, sum, 3, 3);
    
    print_matrix(a, 3, 3);
    puts("");
    print_matrix(b, 3, 3);
    puts("");
    print_matrix(sum, 3, 3);
}

void add_matrix(int **a, int **b, int **sum, int row_size, int column_size) {
    register unsigned i, j;
    
    for (i = 0; i < row_size; i ++) {
        for (j = 0; j < column_size; j ++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

