//
//  calculate.c
//  BCD-display
//
//  Created by POTADOS on 2018. 5. 6..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "calculate.h"

uint8_t character;
uint16_t short_integer;
uint32_t integer;
uint64_t unsigned_long_long;
uintmax_t long_long_unsigned_int;
uintptr_t prt;

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
    uint32 A, B, C, D;
    
    register unsigned i;
    for (i = 1; i < BCDs[0]; i ++) {
        
        A = BCDs[i] & 8;
        B = BCDs[i] & 4;
        C = BCDs[i] & 2;
        D = BCDs[i] & 1;
        
        segments[i] += (A || ((!B)&&C) || (B&&D) || ((!B)&&(!D))) ? SEGMENT_A : 0;
        segments[i] += ((!B) || ((!C)&&(!D)) || (C&&D)) ? SEGMENT_B : 0;
        segments[i] += (B || (!C) || D) ? SEGMENT_C : 0;
        segments[i] += ((B&&(!C)&&D) || ((!B)&&(!D)) || ((!B)&&C) || (C&&(!D))) ? SEGMENT_D : 0;
        segments[i] += (((!B)&&(!D)) || (C&&(!D))) ? SEGMENT_E : 0;
        segments[i] += (((!C)&&(!D)) || (B&&(!C)) || (B&&(!D)) || A) ? SEGMENT_F : 0;
        segments[i] += (((!B)&&C) || (B&&(!C)) || A || (B&&(!D)) || (C&&(!D))) ? SEGMENT_G : 0;
    }
    
    return segments;
}



/*
 
 A 0001
 
 C 0010
 
 
 
 
 
 
 */
