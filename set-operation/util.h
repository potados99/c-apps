//
//  util.h
//  Set_calculation
//
//  quickSort source code from <https://ko.wikipedia.org/wiki/퀵_정렬>
//
//  Created by B.J.Song on 2018. 3. 25..
//  Copyright © 2018년 B.J.Song. All rights reserved.
//

#ifndef util_h
#define util_h

#include <stdlib.h>
#include <string.h>
#include "datatype.h"

int check_that_exists(Arr Array, int element);

int check_not_int(char string[]);

int check_length_over(char *string, int len);

void quickSort(int arr[], int left, int right);

#endif /* util_h */
