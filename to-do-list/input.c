//
//  input.c
//  to-do-list
//
//  Created by MacBoogy on 2018. 4. 10..
//  Copyright © 2018년 potados. All rights reserved.
//

#include "input.h"

time get_input_time(unsigned const short limitHour) {
    time time = 0;
    char buffer[100];
    memset(buffer, 0, sizeof(char)*100);
    
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer)-1] = 0;
    
    string pTimeString = (char *)malloc(strlen(buffer)+1);
    strcpy(pTimeString, buffer);

    time = convert_time_format(pTimeString, NULL, NULL);

    return time;
}

string get_input_string() {
    char buffer[100];
    //memset(buffer, 0, sizeof(char)*100);
    
    fgets(buffer, 200, stdin);
    buffer[strlen(buffer)-1] = 0;

    string pTodoString = (char *)malloc(strlen(buffer)*2 + 1);
    strcpy(pTodoString, buffer);

    return pTodoString;
}

