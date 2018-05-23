//
//  student.c
//  sort
//
//  Created by POTADOS on 2018. 5. 23..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "student.h"

void print_students(student *students, const unsigned int length) {
    for (int i = 0; i < length; ++ i)
        printf("Name: %s, ID: %d\n", students[i].name, students[i].ID);
    puts("");
}

