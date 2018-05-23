//
//  attachstring.h
//  string-practice
//
//  Created by POTADOS on 2018. 5. 16..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef attachstring_h
#define attachstring_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void attach_string_test(void);
void attach_string(char **dest, const char *src);
void catch_input(char *buffer, const int maxLength);
char *get_new_string(const int length);

#endif /* attach string_h */
