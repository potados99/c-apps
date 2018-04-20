//
//  main.c
//  Set_calculation
//
//  201701562 송병준
//
//  Source code on GitHub https://github.com/potados99/set-operation.git
//
//  Created by B.J.Song on 2018. 3. 25..
//  Copyright © 2018년 B.J.Song. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "routine.h"
#include "locale.h"

#define ENG 0
#define KOR 1

int main(int argc, char *argv[]) {
    language = KOR;
    
    Arr A;
    Arr B;
    
    intro();
    
    A = make_set_A();
    B = make_set_B();
    
    show_sets(A, B);
    
    loop_operation(A, B);
    
    outro();
    
    free(A.array);
    free(B.array);
    
    return 0;
}

