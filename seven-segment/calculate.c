//
//  calculate.c
//  BCD-display
//
//  Created by POTADOS on 2018. 5. 6..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "calculate.h"

uint32 *dec_to_BDCs(uint32 decNum) {
    
    // get number of digits
    uint32 length = 0;
    uint32 digitWeight = 1;
    while ((signed)(decNum - digitWeight) >= 0) {
        length += 1;
        digitWeight *= 10;
    }
    
    // seperate each digits
    uint32 *BCDs = (uint32 *)malloc(sizeof(uint32) * length + 1);
    BCDs[0] = length + 1; /* index 0 contains length including index 0 */

    register unsigned i;
    for (i = 1; i < length + 1; i ++) {
        digitWeight /= 10;
        BCDs[i] = (decNum / digitWeight);
        decNum %= digitWeight;
    }

    return BCDs;
}

uint32 *BCDs_to_segments(uint32 *BCDs) {
    uint32 *segments = (uint32 *)malloc(sizeof(uint32) * BCDs[0]);
    segments[0] = BCDs[0];
    
    register unsigned i;
    for (i = 1; i < BCDs[0]; i ++) {

        switch (BCDs[i]) {
            case (0 | 0 | 0 | 0):
                segments[i] = SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F;
                break;
                
            case (0 | 0 | 0 | 1):
                segments[i] = SEGMENT_B | SEGMENT_C;
                break;
                
            case (0 | 0 | 2 | 0):
                segments[i] = SEGMENT_A | SEGMENT_B | SEGMENT_D | SEGMENT_E | SEGMENT_G;
                break;
                
            case (0 | 0 | 2 | 1):
                segments[i] = SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_G;
                break;
                
            case (0 | 4 | 0 | 0):
                segments[i] = SEGMENT_B | SEGMENT_C | SEGMENT_F | SEGMENT_G;
                break;
                
            case (0 | 4 | 0 | 1):
                segments[i] = SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_F | SEGMENT_G;
                break;
                
            case (0 | 4 | 2 | 0):
                segments[i] = SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G;
                break;
                
            case (0 | 4 | 2 | 1):
                segments[i] = SEGMENT_A | SEGMENT_B | SEGMENT_C;
                break;
                
            case (8 | 0 | 0 | 0):
                segments[i] = SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G;
                break;
                
            case (8 | 0 | 0 | 1):
                segments[i] = SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F | SEGMENT_G;
                break;
                
            default:
                fprintf(stderr, "Number over 10");
                exit(1);
                break;
        }
    }

    return segments;
}
