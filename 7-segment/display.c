//
//  display.c
//  BCD-display
//
//  Created by POTADOS on 2018. 5. 6..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "display.h"

void display(uint32 *segments) {
    uint32 segmentData;
    
    register unsigned i;
    for (i = 1; i < segments[0]; i ++) {
        segmentData = segments[i];
        
        if (segmentData & SEGMENT_A) {
            printf(" -\n");
        } else {
            printf("  \n");
        }
        
        if (segmentData & SEGMENT_F) {
            printf("|");
        } else {
            printf(" ");
        }
        
        if (segmentData & SEGMENT_B) {
            printf(" |\n");
        } else {
            printf("  \n");
        }
        
        if (segmentData & SEGMENT_G) {
            printf(" -\n");
        } else {
            printf("  \n");
        }
        
        if (segmentData & SEGMENT_E) {
            printf("|");
        } else {
            printf(" ");
        }
        
        if (segmentData & SEGMENT_C) {
            printf(" |\n");
        } else {
            printf("  \n");
        }
        
        if (segmentData & SEGMENT_D) {
            printf(" -\n");
        } else {
            printf("  \n");
        }
        
        
        printf("\n");
    }
}

void display_horizontal(uint32 *segments) {
    register unsigned i;
    for (i = 1; i < segments[0]; i ++) {
        if (segments[i] & SEGMENT_A) {
            printf(" -");
        } else {
            printf("  ");
        }
        
        printf("     ");
    }
    printf("\n");

    for (i = 1; i < segments[0]; i ++) {
        if (segments[i] & SEGMENT_F) {
            printf("|");
        } else {
            printf(" ");
        }
        
        if (segments[i] & SEGMENT_B) {
            printf(" |");
        } else {
            printf("  ");
        }
        
        printf("    ");
    }
    printf("\n");

    for (i = 1; i < segments[0]; i ++) {
        if (segments[i] & SEGMENT_G) {
            printf(" -");
        } else {
            printf("  ");
        }
        
        printf("     ");
    }
    printf("\n");

    for (i = 1; i < segments[0]; i ++) {
        if (segments[i] & SEGMENT_E) {
            printf("|");
        } else {
            printf(" ");
        }
        
        if (segments[i] & SEGMENT_C) {
            printf(" |");
        } else {
            printf("  ");
        }
        
        printf("    ");
    }
    printf("\n");

    for (i = 1; i < segments[0]; i ++) {
        if (segments[i] & SEGMENT_D) {
            printf(" -");
        } else {
            printf("  ");
        }

        printf("     ");
    }
    printf("\n");

}

