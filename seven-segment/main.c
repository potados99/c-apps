//
//  main.c
//  BCD-display
//
//  Created by POTADOS on 2018. 5. 6..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include <stdio.h>
#include "display.h"

int main(int argc, const char * argv[]) {
    display_horizontal(BCDs_to_segments(dec_to_BDCs(123456789)));

    return 0;
}
