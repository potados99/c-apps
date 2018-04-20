//
//  menu.c
//  Set_calculation
//
//  Created by B.J.Song on 2018. 3. 25..
//  Copyright © 2018년 B.J.Song. All rights reserved.
//

#include "menu.h"
#include "locale.h"

void display_menu() {
    printf("        ---< ");
    printf("%s", setCalculation[language]);
    printf(" >---\n");
    printf("1.%s    ", unions[language]);
    printf("2.%s    ", intersections[language]);
    printf("3.%s    ", complement[language]);
    printf("4.%s    \n\n", exitApp[language]);
    printf("%s", chooseMenu[language]);
    printf(" > ");
}

int get_selection() {
    int selection = 0;
    fscanf(stdin, "%d", &selection);
    return selection;
}
