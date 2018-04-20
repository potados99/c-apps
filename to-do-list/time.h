//
//  time.h
//  to-do-list
//
//  Created by MacBoogy on 2018. 4. 10..
//  Copyright © 2018년 potados. All rights reserved.
//

#ifndef time_h
#define time_h

#define ERROR 65535

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "sys/types.h"
#include "regex.h"

time convert_time_format(const char *rawInput, unsigned short *hour, unsigned short *minute);

#endif /* time_h */
