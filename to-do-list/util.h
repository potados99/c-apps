//
//  util.h
//  to-do-list
//
//  Created by MacBoogy on 2018. 4. 10..
//  Copyright © 2018년 potados. All rights reserved.
//

#ifndef util_h
#define util_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

void error(const char *mes);
string slice_time(const string timeString, size_t start, size_t end);

#endif /* util_h */
