//
//  routine.c
//  result-table
//
//
//  Created by POTADOS on 2018. 5. 1..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "routine.h"

void start_main_memu_loop(void) {
    int selected;
    display_main_menu();

    while ((selected = getchar() - 48) != 5) {
        printf("\n");
        rewind(stdin); /* flush */

        char **branches = get_branches();
        int (*result)[BRANCHES][MONTHS] = get_result();
        int (*resultAvg)[BRANCHES][MONTHS] = get_result_average(result);
        int *average;
        int *order;
        
        int exitFromSubMenu = 0;
        switch (selected) {
            case 1:
                average = get_average(BRANCH_DEPTH, MONTH_DEPTH, YEAR_DEPTH, YEAR2018, result);
                order = get_order_by_avg(average);
                print_result("2018년 실적별 통계", branches, result[YEAR2018], average, order);
                break;
            case 2:
                average = get_average(BRANCH_DEPTH, MONTH_DEPTH, YEAR_DEPTH, YEAR2018, result);
                order = get_order_by_none();
                print_result("2018년 지점별 통계", branches, result[YEAR2018], average, order);
                break;
            case 3:
                average = get_average(BRANCH_DEPTH, MONTH_DEPTH, YEAR_DEPTH, YEARAVG, resultAvg);
                order = get_order_by_avg(average);
                print_result("3년간 평균 실적별 통계", branches, resultAvg[YEARAVG], average, order);
                break;
            case 4:
                start_sub_menu_loop();
                printf("\n");
                exitFromSubMenu = 1;
                break;
            case 8:
                printf("권지용씨는 88년도에 태어났어요!\n");
                break;
            case 9:
                printf("저는 99년도에 태어났어요!\n");
                break;
                
            default:
                printf("잘못된 입력입니다.");
                break;
        }
        rewind(stdin); /* flush */

        if (! exitFromSubMenu)
            pause_for_enter();
        display_main_menu();
    }
    printf("\n종료합니다.\n");
}

void start_sub_menu_loop() {
    int selected;
    display_sub_menu();

    while((selected = getchar() - 48) != 5) {
        rewind(stdin); /* flush */
        printf("\n");

        char **branches = get_branches();
        char **years = get_years();
        int (*result)[BRANCHES][MONTHS] = get_result();
        int *averageOfMonth;
        int *averageOfYear;

        switch (selected) {
            case 1:
                averageOfMonth = get_average(MONTH_DEPTH, YEAR_DEPTH, BRANCH_DEPTH, GWANAK, result);
                averageOfYear = get_average(YEAR_DEPTH, MONTH_DEPTH, BRANCH_DEPTH, GWANAK, result);
                print_result_of_branch(branches[GWANAK], years, result, GWANAK, averageOfMonth, averageOfYear);
                break;
            case 2:
                averageOfMonth = get_average(MONTH_DEPTH, YEAR_DEPTH, BRANCH_DEPTH, GWANAK, result);
                averageOfYear = get_average(YEAR_DEPTH, MONTH_DEPTH, BRANCH_DEPTH, GWANAK, result);
                print_result_of_branch(branches[GWANAK], years, result, GWANAK, averageOfMonth, averageOfYear);
                break;
            case 3:
                averageOfMonth = get_average(MONTH_DEPTH, YEAR_DEPTH, BRANCH_DEPTH, GWANAK, result);
                averageOfYear = get_average(YEAR_DEPTH, MONTH_DEPTH, BRANCH_DEPTH, GWANAK, result);
                print_result_of_branch(branches[GWANAK], years, result, GWANAK, averageOfMonth, averageOfYear);
                break;
            case 4:
                averageOfMonth = get_average(MONTH_DEPTH, YEAR_DEPTH, BRANCH_DEPTH, GWANAK, result);
                averageOfYear = get_average(YEAR_DEPTH, MONTH_DEPTH, BRANCH_DEPTH, GWANAK, result);
                print_result_of_branch(branches[GWANAK], years, result, GWANAK, averageOfMonth, averageOfYear);
                break;
            case 9:
                printf("저는 주안에 살아요!\n");
                break;
            default:
                printf("잘못된 입력입니다.");
                break;
        }
        pause_for_enter();
        display_sub_menu();
    }
}
