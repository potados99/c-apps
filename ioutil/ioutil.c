/*--
 ioutil
 
 Copyright (C) 2018 Byeong Jun Song
 potados99@gmail.com
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
 --*/

#include "ioutil.h"

void _int_to_string(char *dest, const int num) {
    snprintf(dest, _SMALL_BUFFER_SIZE, "%d", num);
}

void _int_to_string_with_comma(char *dest, const int num) {
    char buffer[_SMALL_BUFFER_SIZE];
    snprintf(buffer, _SMALL_BUFFER_SIZE, "%d", num);
    
    unsigned int index = 0;
    unsigned int length = (unsigned int)strlen(buffer);
    unsigned int rest = length % 3;
    bool noFirstComma = False;
    if (! rest)
        noFirstComma = True;

    for (register unsigned int i = 0; i < rest; ++ i) {
        dest[index ++] = buffer[i];
    }
    
    for (register unsigned int j = rest; j < length; ++ j) {
        if ((j % 3) == (rest))
            if (!(j == rest) || !noFirstComma)
                dest[index ++] = ',';
        // do nothing when it is first turn and noFirstComma is True
        dest[index ++] = buffer[j];
    }
    dest[index] = '\0';
}

int _get_sum(const int *nums, const int count) {
    int sum = 0;
    for (unsigned register int i = 0; i < count; ++ i) {
        sum += nums[i];
    }
    return sum;
}


char *get_input_string() {
    char buffer[_BUFFER_SIZE];
    rewind(stdin);
    fgets(buffer, _BUFFER_SIZE - 1, stdin);
    rewind(stdin);

    while (strlen(buffer) == 1) {
        printf("**Enter proper value: ");
        rewind(stdin);
        fgets(buffer, _BUFFER_SIZE - 1, stdin);
        rewind(stdin);
    }
    buffer[strlen(buffer) - 1] = '\0';
    
    char *string = (char *)malloc(sizeof(char) * strlen(buffer)+1);
    strcpy(string, buffer);
    
    return string;
}

int get_input_number() {
    char buffer[_BUFFER_SIZE];
    rewind(stdin);
    fgets(buffer, _BUFFER_SIZE - 1, stdin);
    
    while (strlen(buffer) == 1) {
        printf("**Enter proper value: ");
        rewind(stdin);
        fgets(buffer, _BUFFER_SIZE - 1, stdin);
        rewind(stdin);
    }
    rewind(stdin);

    return atoi(buffer);
}

char *allocate_string(const char *buffer) {
    char *string = (char *)malloc(sizeof(char) * strlen(buffer)+1);
    strcpy(string, buffer);
    return string;
}

void println_string_cells_with_token(const char **string, const int stringCount , const char token, const int *tokenLength, const char border) {
    for (int i = 0; i < stringCount; ++ i) {
        printf("%c", border);
        
        if (string) {
            print_token(token, (tokenLength[i] - (int)strlen(string[i]) - 1) / 2);
            printf("%s", string[i]);
            print_token(token, (tokenLength[i] - (int)strlen(string[i])) / 2);
        }
        else {
            print_token('-', tokenLength[i]);
        }
        
    }   printf("%c\n", border);
}

void println_string_with_token(const char *string, const char token, const int tokenLength, const char border) {
    print_string_with_token(string, token, tokenLength, border);
    puts("");
}

void print_string_with_token(const char *string, const char token, const int tokenLength, const char border) {
    printf("%c", border);
    
    if (string) {
        print_token(token, (tokenLength - (int)strlen(string) - 1) / 2);
        printf("%s", string);
        print_token(token, (tokenLength - (int)strlen(string)) / 2);
    }
    else {
        print_token(token, tokenLength - 1);
    }
    
    printf("%c", border);
}

void println_token(const char token, const unsigned int length) {
    print_token(token, length);
    puts("");
}

void print_token(const char token, const unsigned int length) {
    for (unsigned register int i = 0; i < length; ++ i)
        printf("%c", token);
}


void wait_for_enter() {
    rewind(stdin);
    printf("\nPress enter.\n");
    while(getchar() != 10);/* CR */
    rewind(stdin);
}

void print_moving_string(const char *string, const int flowDirection, const int speed, const int boxLength, const char emptySpaceToken, const char boxBorderLeft, const char boxBorderRight) {
    for (register unsigned int frame = 0; frame < (boxLength + strlen(string)); ++ frame) {
        rewind(stdout);
        printf("\r");
        rewind(stdout);
        _sleep(1000 / speed);
        
        printf("%c", boxBorderLeft);

        unsigned int lastCharacterPosition = 0;
        unsigned int beforSpaceLength = 0;
        unsigned int stringBegin = 0;
        unsigned int stringEnd = 0;
        unsigned int afterSpaceLength = 0;
        
        if (flowDirection == STRING_FLOW_DIRECTION_RIGHT) {
            lastCharacterPosition = frame;
        } else {
            // default: flow_direction_left
            lastCharacterPosition = boxLength + (unsigned int)strlen(string) - frame - 1;
        }
        
        if (lastCharacterPosition >= strlen(string)) {
            beforSpaceLength = lastCharacterPosition - (unsigned int)strlen(string);
            stringBegin = 0;
        } else {
            beforSpaceLength = 0;
            stringBegin = (unsigned int)strlen(string) - lastCharacterPosition;
        }
        
        if (lastCharacterPosition < boxLength) {
            stringEnd = (unsigned int)strlen(string);
            afterSpaceLength = (boxLength - lastCharacterPosition) - 1;
        } else {
            stringEnd = (unsigned int)strlen(string) - (lastCharacterPosition - boxLength) - 1;
            afterSpaceLength = 0;
        }
        
        for (register unsigned int k = 0; k < beforSpaceLength; ++ k)
            printf("%c", emptySpaceToken);
        
        for (register unsigned int j = stringBegin; j < stringEnd; ++ j)
            printf("%c", string[j]);
        
        for (register unsigned int k = 0; k < afterSpaceLength; ++ k)
            printf("%c", emptySpaceToken);
        
        printf("%c", boxBorderRight);
    }
    
    printf("\r");
    for (register unsigned int i = 0; i <= boxLength; ++ i)
        printf("%c", ' ');
    printf("\r");
    rewind(stdout);
    _sleep(1000 * 0.2);
}
