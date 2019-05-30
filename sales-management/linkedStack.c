//
//  linkedStack.c
//  linked-stack
//
//  Created by POTADOS on 2018. 6. 10..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#include "linkedStack.h"

Stack new_Stack() {
    Stack myStack = (Stack)malloc(sizeof(_Stack));
    myStack->top = NULL;
    
    return myStack;
}


void Stack_push(Stack self, StackElement data) {
    self->top = newNode(data, self->top);
}

StackElement Stack_pop(Stack self) {
    if (! self->top) {
        fprintf(stderr, "Stack is empty.\n");
        exit(1);
    }
    StackNode willBePoped = self->top;
    StackElement value = self->top->data;
    self->top = self->top->link;
    
    free(willBePoped);
    return value;
}

int Stack_size(Stack self) {
    if (! self->top)
        return 0;
    
    int count = 1;
    StackNode currentNode = self->top;
    while (currentNode->link) {
        currentNode = currentNode->link;
        count += 1;
    }
    return count;
}

StackNode newNode(StackElement data, StackNode link) {
    StackNode newNode = (StackNode)malloc(sizeof(_StackNode));
    
    newNode->data = data;
    newNode->link = link;
    
    return newNode;
}

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
