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

#include <stdio.h>

char (**get_branches(void));
char (**get_years(void));
int (*get_result(void))[BRANCHES][MONTHS];
int (*get_result_average(int (*result)[BRANCHES][MONTHS]))[MONTHS];
int (*get_average(int (*resultOfYear)[MONTHS]));
int (*get_average_of_months_of_branch(int (*result)[BRANCHES][MONTHS], const int branchIndex));
int (*get_average_of_years_of_branch(int (*result)[BRANCHES][MONTHS], const int branchIndex));
int (*get_order_by_avg(int (*average)));
int (*get_order_by_none(void));
int rounds(double num);

#endif /* data_h */
