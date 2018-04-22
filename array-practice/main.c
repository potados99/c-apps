//
//  main.c
//  rand-test
//
//  Created by POTADOS on 2018. 4. 18..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include <stdio.h>
#include "lotto.h"
#include "lookuptable.h"
#include "dumparray.h"
#include "splitstring.h"

#define LOTTO_NUM 6

int main(int argc, const char * argv[]) {
    register unsigned short i;

    // Practice 1
    int *arr = create_random_array(LOTTO_NUM);
    sort(arr, LOTTO_NUM);

    for (i = 0; i < LOTTO_NUM; i ++) {
        printf("%i\n", *(arr + i));
    }

    // Practice 2
    congratulations(*(arr + 0));

    // Practice 3
    int ari[] = {1, 2, 3, 4, 5};
    char arc[] = "Pointer";

    dump_array(ari, sizeof(ari));
    dump_array(arc, sizeof(arc));

    // Practice 4
    char **charArr;
    charArr = split("테스트 문자열 1번 테스트 문자열 두번째", ' ');

    for (i = 0; i < 10; i ++) {
        printf("%s\n", charArr[i]);
    }

    return 0;
}
