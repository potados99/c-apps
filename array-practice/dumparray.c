//
//  dumparray.c
//  rand-test
//
//  Created by POTADOS on 2018. 4. 18..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "dumparray.h"

void dump_array(void *array, unsigned const short length) {
    register unsigned short i;
    for (i = 0; i < length; i ++) {
        printf("%02X ", *(unsigned char *)(array + i));
    }
    printf("\n");
}
