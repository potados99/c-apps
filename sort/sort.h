//
//  bubblesort.h
//  sort
//
//  Created by POTADOS on 2018. 5. 23..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>
#include "student.h"

typedef int element;

void selection_sort(student *students, const unsigned int length);
void insertion_sort(student *students, const unsigned int length);
void bubble_sort(student *students, const unsigned int length);

void swap(student *A, student *B);

#endif /* sort_h */

