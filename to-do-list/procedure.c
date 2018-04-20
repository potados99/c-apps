//
//  procedure.c
//  to-do-list
//
//  Created by MacBoogy on 2018. 4. 10..
//  Copyright © 2018년 potados. All rights reserved.
//

#include "procedure.h"

void write_list(List *list) {
    
    time startTime = 0;
    time reqTime = 0;
    string todo = NULL;
    
    printf("%s", inputStartTime[language]);
    startTime = get_input_time(0);
    
    while (startTime != -1) {
        printf("%s", inputReqTime[language]);
        reqTime = get_input_time(0);
        printf("%s", inputTodo[language]);
        todo = get_input_string();
        
        append_list(list, startTime, reqTime, todo);
        
        printf("\n");
        printf("%s", inputStartTime[language]);
        startTime = get_input_time(0);
    }
    
    print_node(list, 0, 1);
    startTime = 0;
    
    printf("%s %s", search[language], inputStartTime[language]);
    startTime = get_input_time(0);
    
    while (1) {
        print_node(list, startTime, 0);
        printf("%s %s", search[language], inputStartTime[language]);
        startTime = get_input_time(0);
    }
}

void search_list(List *list) {
    
}
