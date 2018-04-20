//
//  calculation.c
//  Set_calculation
//
//  operate_difference improvement inspired by Mihddy
//
//  Created by B.J.Song on 2018. 3. 25..
//  Copyright © 2018년 B.J.Song. All rights reserved.
//

#include "calculation.h"
#include "array.h"
#include "util.h"

Arr operate_union(Arr A, Arr B) {
    Arr Array;
    
    Array = copy_array(A);
    
    int i = 0;
    for (i = 0; i <= B.size - 1; i ++) {
        if (! check_that_exists(Array, B.array[i])) {
            Array = append_array(Array, B.array[i]);
        }
    }
    
    sort_array(Array);

    return Array;
}

Arr operate_intersection(Arr A, Arr B) {
    Arr Array;
    Array = init_array(0);

    int i = 0;
    int j = 0;
    for (i = 0; i <= A.size - 1; i ++) {
        for (j = 0; j <= B.size - 1; j ++) {
            if (A.array[i] == B.array[j])
                Array = append_array(Array, A.array[i]);
        }
    }

    sort_array(Array);

    return Array;
}

Arr operate_difference(Arr A, Arr B) {
    Arr Array;
    Arr A_copy;
    Arr Intersection;
    
    Array = init_array(0);
    A_copy = copy_array(A);
    Intersection = operate_intersection(A, B);
    
    int i = 0;
    for (i = 0; i <= A_copy.size - 1; i ++) {
        if (! (check_that_exists(Intersection, A_copy.array[i])))
            Array = append_array(Array, A_copy.array[i]);
    }

    sort_array(Array);

    return Array;
}

