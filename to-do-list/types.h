//
//  types.h
//  to-do-list
//
//  Created by MacBoogy on 2018. 4. 10..
//  Copyright © 2018년 potados. All rights reserved.
//

#ifndef types_h
#define types_h

#include <stdio.h>

#pragma mark - Structures

typedef short time;
typedef char *string;

typedef struct Node {
    time startTime;
    time reqTime;
    string todo;
    struct Node * nextNode;
}Node;

typedef struct List {
    Node * head;
}List;

#endif /* types_h */
