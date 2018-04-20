//
//  routine.h
//  Set_calculation
//
//  Created by B.J.Song on 2018. 3. 25..
//  Copyright © 2018년 B.J.Song. All rights reserved.
//

#ifndef routine_h
#define routine_h

#include <stdio.h>
#include "datatype.h"

void intro(void);

void outro(void);

Arr make_set_A(void);

Arr make_set_B(void);

void show_sets(Arr Array_A, Arr Array_B);

void loop_operation(Arr Array_A, Arr Array_B);

#endif /* routine_h */
