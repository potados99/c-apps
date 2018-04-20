//
//  linked_list.c
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#include "linked_list.h"

#pragma mark - List methods

void init_list(List *list) {
    list->head = NULL;
    return;
}

void append_list(List *list, time startTime, time reqTime, string todo) {
	if (isEmpty(list)) {
		list->head = create_node(startTime, reqTime, todo, NULL);
        return;
    }
    
    Node *lastNode = find_last_node(list);
    Node *newNode = create_node(startTime, reqTime, todo, NULL);

    lastNode->nextNode = newNode;
    return;
}

void insert_list(List *list, const int index, time startTime, time reqTime, string todo) {
    if (isEmpty(list))
        error(listEmpty[language]);
    
    if (index == 0) {
        list->head = create_node(startTime, reqTime, todo, list->head);
        return;
    }
    
    unsigned const int safeIndex = get_safe_index(list, index);
    Node *beforeNode = find_node(list, safeIndex - 1);
    Node *newNode = create_node(startTime, reqTime, todo, beforeNode->nextNode);

    beforeNode->nextNode = newNode;
    return;
}

time pop_list(List *list, const int index) {
    if (isEmpty(list))
        error(listEmpty[language]);
    
    if (index == 0) {
        Node *nextNode = list->head->nextNode;
        const int value = list->head->startTime;
        
        free(list->head);
        list->head = NULL;
        list->head = nextNode;
        
        return value;
    }
    
    Node *beforeNode = find_node(list, index - 1);
    Node *currentNode = beforeNode->nextNode;
    const int value = currentNode->startTime;
    
    beforeNode->nextNode = currentNode->nextNode;
    
    free(currentNode);
    currentNode = NULL;
    
    return value;
}

void print_node(List *list, time startTime, unsigned const short all) {
    if (isEmpty(list)) {
        printf("%s", listEmpty[language]);
        return;
    }
    
    Node *currentNode = list->head;
    
    printf("%s", columns[language]);
    unsigned short keepCondition = 0;

    while (currentNode != NULL) {
        
        if (all) {
            keepCondition = 1;
        }
        else {
            keepCondition = (currentNode->startTime == startTime) | (startTime == -1);
        }
        
        if (keepCondition) {
            string startTimeString = (char*)malloc(sizeof(char)*6);
            string reqTimeString = (char*)malloc(sizeof(char)*6);
            
            sprintf(startTimeString, "%d", currentNode->startTime);
            sprintf(reqTimeString, "%d", currentNode->reqTime);
            
            printf("%s:%s         ", slice_time(startTimeString, 1, 2), slice_time(startTimeString, 3, 4));
            printf("%s:%s       ", slice_time(reqTimeString, 1, 2), slice_time(reqTimeString, 3, 4));
            printf("%s\n", currentNode->todo);
        }
        currentNode = currentNode->nextNode;
        
    }
    printf("\n");
    
    return;
}


#pragma mark - List functions

int isEmpty(List *list) {
    return (list->head == NULL);
}

int get_length(List *list) {
    if (isEmpty(list))
        return 0;
    
    Node *currentNode = list->head;
    register unsigned int currentIndex = 1;
    
    while (currentNode->nextNode != NULL) {
        currentNode = currentNode->nextNode;
        currentIndex ++;
    }
    
    return currentIndex;
}

int get_safe_index(List *list, const int index) {
    unsigned const int length = get_length(list);
    unsigned int safeIndex = 0;
    
    if (index < 0) {
        if ((index * -1) > length)
            error(indexOut[language]);
        safeIndex = length + index;
    } else {
        if (index > length - 1)
            error(indexOut[language]);
        safeIndex = index;
    }
    
    return safeIndex;
}


#pragma mark - Node functions

Node *create_node(time startTime, time reqTime, string todo, Node *next) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    
    newNode->startTime = startTime;
    newNode->reqTime = reqTime;
    newNode->todo = todo;
    newNode->nextNode = next;
    
    return newNode;
}

Node *find_node(List *list, const int index) {
    if (isEmpty(list))
        error(listEmpty[language]);
    
    Node *currentNode = list->head;
    
    unsigned const int safeIndex = get_safe_index(list, index);
    register unsigned int i = 0;

    for (i = safeIndex; i != 0; i --) {
        currentNode = currentNode->nextNode;
        if (currentNode == NULL)
            error(nodeEmpty[language]);
    }
    
    return currentNode;
}

Node *find_last_node(List *list) {
    if (isEmpty(list))
        error(indexOut[language]);
    
    Node *currentNode = (Node *)malloc(sizeof(Node));
    
    currentNode = list->head;
    
    while (currentNode->nextNode != NULL)
        currentNode = currentNode->nextNode;
    
    return currentNode;
}

