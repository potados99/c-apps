//
//  data.c
//  result-table
//
//  Created by POTADOS on 2018. 5. 1..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "data.h"

char (**get_branches(void)) {
    static char *branches[4] = { "관악점", "강남점", "명동점", "대림점" };
    return branches;
}

char (**get_years(void)) {
    static char *years[3] = { "2016년", "2017년", "2018년" };
    return years;
}

int (*get_result(void))[BRANCHES][MONTHS] {
    static int result[YEARS][BRANCHES][MONTHS] = {
        { /* 2016 */
            {85, 78, 54, 98, 76, 82},
            {83, 87, 78, 94, 70, 69},
            {79, 68, 96, 95, 87, 89},
            {89, 92, 94, 91, 89, 85}
        }, { /* 2017 */
            {86, 79, 72, 69, 59, 64},
            {78, 89, 67, 63, 80, 88},
            {68, 78, 80, 83, 87, 90},
            {90, 89, 84, 81, 86, 88}
        }, { /* 2018 */
            {70, 45, 100, 92, 150, 81}, /* 관악 */
            {88, 92, 77, 30, 52, 55}, /* 강남 */
            {50, 90, 88, 75, 77, 49}, /* 명동 */
            {120, 92, 80, 150, 130, 105} /* 대림 */
        }
    };
    return result;
}

int (*get_result_average(int (*result)[BRANCHES][MONTHS]))[BRANCHES][MONTHS] {
    static int avgResult[1][BRANCHES][MONTHS];
    
    unsigned short i = 0;
    unsigned short j = 0;
    unsigned short k = 0;
    unsigned count = 0;

    for (i = 0; i < BRANCHES; i ++) {
        for (j = 0; j < MONTHS; j ++) {
            count = 0;
            for (k = 0; k < YEARS; k ++) {
                count += result[k][i][j];
            }
            avgResult[0][i][j] = rounds(count/YEARS);
        }
    }
    return avgResult;
}

int (*get_average(int ofDepth, int throughDepth, int inDepth, int inIndex, int (*result)[BRANCHES][MONTHS])) {
    static int average[POSSIBLE_MAX_LENGTH];
     
    double total = 0;

    int first = 0;
    int second = 0;
    
    int firstRange = 0;
    int secondRange = 0;
    
    int *pfirst = NULL;
    int *psecond = NULL;
    int *pthird = NULL;

    switch (ofDepth) {
        case YEAR_DEPTH:
            pfirst = &first;
            firstRange = YEARS;
            break;
        case BRANCH_DEPTH:
            psecond = &first;
            firstRange = BRANCHES;
            break;
        case MONTH_DEPTH:
            pthird = &first;
            firstRange = MONTHS;
            break;
            
        default:
            break;
    }
    
    switch (throughDepth) {
        case YEAR_DEPTH:
            pfirst = &second;
            secondRange = YEARS;

            break;
        case MONTH_DEPTH:
            pthird = &second;
            secondRange = MONTHS;
            break;
            
        default:
            break;
    }
    
    switch (inDepth) {
        case YEAR_DEPTH:
            pfirst = &inIndex;

            break;
        case BRANCH_DEPTH:
            psecond = &inIndex;
            break;
            
        default:
            break;
    }
    
    for (first = 0; first < firstRange; first ++) {
        total = 0;
        for (second = 0; second < secondRange; second ++) {
            total += result[*pfirst][*psecond][*pthird];
            }
        average[first] = rounds(total/secondRange);
    }

    return average;
}

int (*get_order_by_avg(int (*average))) {
    static int order[BRANCHES];
    unsigned short i = 0;
    unsigned short j = 0;
    int index = 0;
    int prevMax = -1;
    int max = 0;
    for (i = 0; i < BRANCHES; i ++) {
        /* get index of max value */
        max = 0;
        for (j = 0; j < BRANCHES; j ++) {
            if ((prevMax > average[j]) || (prevMax == -1)) {
                if (max < average[j]) {
                    index = j;
                    max = average[j];
                }
            }
        }
        prevMax = max;
        order[i] = index;
    }
    return order;
}

int (*get_order_by_none(void)) {
    static int order[BRANCHES] = {0, 1, 2, 3};
    return order;
}

int rounds(double num) {
    return (num + 0.5);
}

