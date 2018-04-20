//
//  routine.c
//  Set_calculation
//
//  Created by B.J.Song on 2018. 3. 25..
//  Copyright © 2018년 B.J.Song. All rights reserved.
//

#include "routine.h"
#include "locale.h"
#include "array.h"
#include "util.h"
#include "menu.h"
#include "calculation.h"

void intro() {
    printf("==================\n");
    printf("201701562 %s\n", myName[language]);
    printf("==================\n\n");
}

void outro() {
    printf("\n%s\n", exiting[language]);
}

Arr make_set_A() {
    Arr Arr_A;

    printf("%s", creatingSetA[language]);
    printf(" (%s: Enter)\n", exitApp[language]);
    
    Arr_A = user_input_array();
    sort_array(Arr_A);
    
    printf("\n");
    
    return Arr_A;
}

Arr make_set_B() {
    Arr Arr_B;
    
    printf("%s", creatingSetB[language]);
    printf(" (%s: Enter)\n", exitApp[language]);
    
    Arr_B = user_input_array();
    sort_array(Arr_B);
    
    printf("\n");
    
    return Arr_B;
}

void show_sets(Arr Array_A, Arr Array_B) {
    printf("A = ");
    print_array(Array_A);
    printf("\nB = ");
    print_array(Array_B);
    printf("\n\n");
}

void loop_operation(Arr Array_A, Arr Array_B) {
    int selection = 0;
    Arr Array;
    char *operator;
    
    display_menu();
    while ((selection = get_selection()) != 4) {
        
        switch (selection) {
            case 1:
                Array = operate_union(Array_A, Array_B);                
                operator = "⋃";
                break;
            case 2:
                Array = operate_intersection(Array_A, Array_B);
                operator = "⋂";
                break;
            case 3:
                Array = operate_difference(Array_A, Array_B);
                operator = "-";
                break;
                
            default:
                printf("%s\n\n", wrongNumber[language]);
                display_menu();
                continue;
                break;
        }
        
        printf("\n\n");
        printf("A = ");
        print_array(Array_A);
        
        printf("\nB = ");
        print_array(Array_B);
        
        printf("\n\nA %s B = ", operator);
        print_array(Array);
        free(Array.array);
        
        printf("\n\n");
        display_menu();
        
    }
}
