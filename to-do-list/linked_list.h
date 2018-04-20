//
//  linked_list.h
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "locale.h"
#include "time.h"
#include "util.h"


#pragma mark - List methods

void init_list(List *list);
void append_list(List *list, time startTime, time reqTime, string todo);
void insert_list(List *list, const int index, time startTime, time reqTime, string todo);
time pop_list(List *list, const int index);
void print_node(List *list, time startTime, unsigned const short all);


#pragma mark - List functions

int isEmpty(List *list);
int get_length(List *list);
int get_safe_index(List *list, const int index);


#pragma mark - Node functions

Node *create_node(time startTime, time reqTime, string todo, Node *next);
Node *find_node(List *list, const int index);
Node *find_last_node(List *list);

#endif /* linked_list_h */
