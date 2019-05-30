//
//  linkedStack.h
//  linked-stack
//
//  Created by POTADOS on 2018. 6. 10..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#ifndef linkedStack_h
#define linkedStack_h

#include <stdio.h>
#include <stdlib.h>

typedef char StackElement;

typedef struct _StackNode {
    StackElement data;
    struct _StackNode *link;
    
} _StackNode;
typedef _StackNode* StackNode;

typedef struct Stack {
    StackNode top;
    
} _Stack;
typedef _Stack* Stack;

Stack new_Stack(void);

void Stack_push(Stack self, StackElement data);
StackElement Stack_pop(Stack self);
int Stack_size(Stack self);

StackNode newNode(StackElement data, StackNode link);

#endif /* linkedStack_h */

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
