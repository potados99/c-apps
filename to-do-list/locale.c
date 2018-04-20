//
//  locale.c
//  to-do-list
//
//  Created by MacBoogy on 2018. 4. 10..
//  Copyright © 2018년 potados. All rights reserved.
//

#include "locale.h"

int language = 0;

const char *columns[NUMBER_OF_LANGUAGE] = {
    "Start time    Req time    To do\n==============================\n",
    "시작 시간       소요 시간      할 일\n==============================\n"
};


const char *inputStartTime[NUMBER_OF_LANGUAGE] = {
    "Input start time: ", "시작 시간을 입력하세요: "
};

const char *inputReqTime[NUMBER_OF_LANGUAGE] = {
    "Input time required: ", "소요시간을 입력하세요: "
};

const char *inputTodo[NUMBER_OF_LANGUAGE] = {
    "Input to-do: ", "작업을 입력하세요: "
};

const char *search[NUMBER_OF_LANGUAGE] = {
    "[Search]", "[검색]"
};

const char *indexOut[NUMBER_OF_LANGUAGE] = {
    "Index out of range.\n", "인덱스 초과.\n"
};

const char *nodeEmpty[NUMBER_OF_LANGUAGE] = {
    "Node is empty.\n", "노드가 비어있습니다.\n"
};

const char *listEmpty[NUMBER_OF_LANGUAGE] = {
    "List is empty.\n", "리스트가 비어있습니다.\n"
};


