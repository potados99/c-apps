//
//  main.c
//  sort
//
//  Created by POTADOS on 2018. 5. 23..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "student.h"

int main(int argc, const char * argv[]) {
    student a = { "BJ", 20171562, "", "" };
    student b = { "MH", 20171592, "", "" };
    student c = { "JY", 20171563, "", "" };
    student d = { "JB", 20171561, "", "" };
    student e = { "DK", 20171599, "", "" };
    student f = { "SB", 20171551, "", "" };

    student testersForSelectionSort[6] = {a, b, c, d, e, f};
    student testersForInsertionSort[6] = {a, b, c, d, e, f};
    student testersForBubbleSort[6] = {a, b, c, d, e, f};

    puts("Initial state");
    print_students(testersForSelectionSort, 6);
    
    puts("Test: selection sort");
    selection_sort(testersForSelectionSort, 6);
    print_students(testersForSelectionSort, 6);
    
    puts("Test: insertion sort");
    insertion_sort(testersForInsertionSort, 6);
    print_students(testersForInsertionSort, 6);
    
    puts("Test: bubble sort");
    bubble_sort(testersForBubbleSort, 6);
    print_students(testersForBubbleSort, 6);
    
    return 0;
}
