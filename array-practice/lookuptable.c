//
//  lookuptable.c
//  rand-test
//
//  Created by POTADOS on 2018. 4. 18..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "lookuptable.h"

char *message[] = {
    "Well done.\n",
    "Good job.\n",
    "You stupid.\n"
};

void congratulations(const short count) {
    printf("%s", *(message + count%3));
}

