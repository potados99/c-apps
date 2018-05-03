//
//  view.c
//  result-table
//
//  Created by POTADOS on 2018. 5. 1..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "view.h"

void print_result(char (*title), char (**branches), int (*resultOfYear)[MONTHS], int (*average), int (*order)) {
    register unsigned short i = 0;
    register unsigned short j = 0;
    
    printf("    --< %s >--\n", title);
    printf(" 년도  1월   2월  3월   4월   5월  6월   평균 \n");

    for (i = 0; i < BRANCHES; i ++) {
        printf("%s  ", branches[order[i]]);
        for (j = 0; j < MONTHS; j ++) {
            printf("%d  " , resultOfYear[order[i]][j]);
            if (resultOfYear[order[i]][j] - 100 < 0)
                printf(" ");
        }
        printf("%d\n", average[order[i]]);
    }
}

void print_result_of_branch(char (*branch), char (**years), int (*result)[BRANCHES][MONTHS], const int branchIndex, int (*averageOfMonthsOfBranch), int (*averageOfYearsOfBranch)) {
    register unsigned short i = 0;
    register unsigned short j = 0;
    
    printf("    --< 3년간 상반기 실적(%s) >--\n", branch);
    printf("  년도  1월   2월  3월   4월   5월  6월   평균 \n");

    for (i = 0; i < YEARS; i ++) {
        printf("%s  ", years[i]);
        for (j = 0; j < MONTHS; j ++) {
            printf("%d  ", result[i][branchIndex][j]);
            if (result[i][branchIndex][j] - 100 < 0)
                printf(" ");
        }
        printf("%d\n", averageOfMonthsOfBranch[i]);
    }
    
    printf("  평균   ");
    for (i = 0; i < MONTHS; i ++) {
        printf("%d  ", averageOfYearsOfBranch[i]);
        if (averageOfYearsOfBranch[i] - 100 < 0)
            printf(" ");
    }
    printf("\n");
}

void display_main_menu() {
    printf("    --< 또또분식 상반기 매출 통계 >--\n");
    printf("1. 2018년 실적별 통계\n");
    printf("2. 2018년 지점별 통계\n");
    printf("3. 3년 평균 실적별 통계\n");
    printf("4. 지점별 실적 조회\n");
    printf("5. 종료\n");
    printf("> ");
}

void display_sub_menu() {
    printf("    --< 지점별 실적 통계 >--\n");
    printf("1. 관악점\n");
    printf("2. 강남점\n");
    printf("3. 명동점\n");
    printf("4. 대림점\n");
    printf("5. 처음으로\n");
    printf("> ");
}

void pause_for_enter() {
    printf("\n엔터 키를 누르세요.\n");
    while(getchar() != 10);/* CR */
    rewind(stdin);
}

