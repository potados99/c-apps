//
//  student.h
//  sort
//
//  Created by POTADOS on 2018. 5. 23..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef student_h
#define student_h

#include <stdio.h>

#define _SMALL_BUFFER_SIZE 16
#define _BIG_BUFFER_SIZE 32

typedef struct _student {
    char name[_SMALL_BUFFER_SIZE];
    int ID;
    char address[_BIG_BUFFER_SIZE];
    char contact[_SMALL_BUFFER_SIZE];
    
} student;

void print_students(student *students, const unsigned int length);

#endif /* student_h */
