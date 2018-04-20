//
//  array.h
//  Set_calculation
//
//  Created by B.J.Song on 2018. 3. 25..
//  Copyright © 2018년 B.J.Song. All rights reserved.
//

#ifndef array_h
#define array_h

#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"

Arr init_array(int size);

Arr append_array(Arr Array, int element);

Arr copy_array(Arr Array);

Arr extend_array(Arr Array1, Arr Array2);

Arr user_input_array(void);

void sort_array(Arr Array);

void print_array(Arr Array);

#endif /* array_h */
