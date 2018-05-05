//
//  calculate.h
//  BCD-display
//
//  Created by POTADOS on 2018. 5. 6..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef calculate_h
#define calculate_h

#include <stdio.h>
#include <stdlib.h>

#define SEGMENT_A 0x00000001
#define SEGMENT_B 0x00000010
#define SEGMENT_C 0x00000100
#define SEGMENT_D 0x00001000
#define SEGMENT_E 0x00010000
#define SEGMENT_F 0x00100000
#define SEGMENT_G 0x01000000

typedef unsigned int uint32;

uint32 *dec_to_BDCs(uint32 decNum);

uint32 *BCDs_to_segments(uint32 *BCDs);

#endif /* calculate_h */
