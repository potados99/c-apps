//
//  view.h
//  result-table
//
//  Created by POTADOS on 2018. 5. 1..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef view_h
#define view_h

#include <stdio.h>
#include "data.h"

void print_result(char (*title), char (**branches), int (*resultOfYear)[MONTHS], int (*average), int (*order));
void print_result_of_branch(char (*branch), char (**years), int (*result)[BRANCHES][MONTHS], const int branchIndex, int (*averageOfMonthsOfBranch), int (*averageOfYearsOfBranch));
void display_main_menu(void);
void display_sub_menu(void);
void pause_for_enter(void);

#endif /* view_h */
