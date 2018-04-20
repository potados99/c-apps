//
//  time.c
//  to-do-list
//
//  Created by MacBoogy on 2018. 4. 10..
//  Copyright © 2018년 potados. All rights reserved.
//

#include "time.h"

time convert_time_format(const char *rawInput, unsigned short *phour, unsigned short *pminute) {
    
    const char *pattern = "^([0-9]{0,2})([ ]*:?[ ]*|[ ]*)([0-9]{0,2})$";
    char rawCopy[strlen(rawInput) + 1];
    strcpy(rawCopy, rawInput);
    
    size_t maxGroups = 4;
    regex_t regexCompiled;
    regmatch_t groupArray[maxGroups];
    
    regcomp(&regexCompiled, pattern, REG_EXTENDED);
    
    if (regexec(&regexCompiled, rawInput, maxGroups, groupArray, 0))
        return -1;
    
    rawCopy[groupArray[3].rm_eo] = 0;
    unsigned short minute = atoi(rawCopy + groupArray[3].rm_so);
    if (pminute != NULL)
        *pminute = minute;
    
    rawCopy[groupArray[1].rm_eo] = 0;
    unsigned short hour = atoi(rawCopy + groupArray[1].rm_so);
    if (phour != NULL)
        *phour = hour;
    
    unsigned short time = 10000 + 100 * hour + minute;
    
    regfree(&regexCompiled);
    
    return time;
    
}
