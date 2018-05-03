//
//  routine.c
//  result-table
//
//
//  Created by POTADOS on 2018. 5. 1..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "routine.h"

#define YEAR2018 2
#define GWANAK 0
#define GANGNAM 1
#define MYEONGDONG 2
#define DAELIM 3

void start_main_memu_loop(void) {
    int selected;
    display_main_menu();

    while ((selected = getchar() - 48) != 5) {
        printf("\n");
        rewind(stdin); /* flush */

        int exitFromSubMenu = 0;
        switch (selected) {
            case 1:
                print_result("2018년 실적별 통계", get_branches(), get_result()[YEAR2018], get_average(get_result()[YEAR2018]), get_order_by_avg(get_average(get_result()[YEAR2018])));
                break;
            case 2:
                print_result("2018년 지점별 통계", get_branches(), get_result()[YEAR2018], get_average(get_result()[YEAR2018]), get_order_by_none());
                break;
            case 3:
                print_result("3년간 평균 실적별 통계", get_branches(), get_result_average(get_result()), get_average(get_result_average(get_result())), get_order_by_avg(get_average(get_result_average(get_result()))));
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

        switch (selected) {
            case 1:
                print_result_of_branch(get_branches()[GWANAK], get_years(), get_result(), GWANAK, get_average_of_months_of_branch(get_result(), GWANAK), get_average_of_years_of_branch(get_result(), GWANAK));
                break;
            case 2:
                print_result_of_branch(get_branches()[GANGNAM], get_years(), get_result(), GANGNAM, get_average_of_months_of_branch(get_result(), GANGNAM), get_average_of_years_of_branch(get_result(), GANGNAM));
                break;
            case 3:
                print_result_of_branch(get_branches()[MYEONGDONG], get_years(), get_result(), MYEONGDONG, get_average_of_months_of_branch(get_result(), MYEONGDONG), get_average_of_years_of_branch(get_result(), MYEONGDONG));
                break;
            case 4:
                print_result_of_branch(get_branches()[DAELIM], get_years(), get_result(), DAELIM, get_average_of_months_of_branch(get_result(), DAELIM), get_average_of_years_of_branch(get_result(), DAELIM));
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
