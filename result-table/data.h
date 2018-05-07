//
//  data.h
//  result-table
//
//  Created by POTADOS on 2018. 5. 1..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef data_h
#define data_h

#define YEARS 3
#define BRANCHES 4
#define MONTHS 6
#define POSSIBLE_MAX_LENGTH 6

#define YEAR_DEPTH 1
#define BRANCH_DEPTH 2
#define MONTH_DEPTH 3

#include <stdio.h>

char (**get_branches(void));
char (**get_years(void));
int (*get_result(void))[BRANCHES][MONTHS];
int (*get_result_average(int (*result)[BRANCHES][MONTHS]))[BRANCHES][MONTHS];

int (*get_average(int ofDepth, int throughDepth, int inDepth, int inIndex, int (*result)[BRANCHES][MONTHS]));

int (*get_order_by_avg(int (*average)));
int (*get_order_by_none(void));
int rounds(double num);

#endif /* data_h */
