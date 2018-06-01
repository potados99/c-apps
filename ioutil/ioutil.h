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

#ifndef ioutil_h
#define ioutil_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined __APPLE__ || defined __unix__
#include <unistd.h>
#define _sleep(x) usleep(1000 * (x));

#elif defined __WIN32__ || defined _MSC_VER
#include <windows.h>
#define _sleep(x) Sleep(x);
#endif

#define _BUFFER_SIZE 64
#define _SMALL_BUFFER_SIZE 16

#define INT_INPUT_ERROR -2147483648

#define STRING_FLOW_DIRECTION_RIGHT 1
#define STRING_FLOW_DIRECTION_LEFT 2

#define STRING_FLOW_SPEED_SLOW 5
#define STRING_FLOW_SPEED_MID 10
#define STRING_FLOW_SPEED_FAST 20

#define WITH_BOX 1
#define WITHOUT_BOX 0

#define BOX_CORNER_TOP_LEFT "╔"
#define BOX_CORNER_TOP_RIGHT "╗"
#define BOX_CORNER_BOTTOM_LEFT "╚"
#define BOX_CORNER_BOTTOM_RIGHT "╝"

#define BOX_EDGE_HORIZONTAL "═"
#define BOX_EDGE_VERTICAL "║"

#define BOX_INTER_HORIZONTAL_TOP "╩"
#define BOX_INTER_HORIZONTAL_DOWN "╦"

#define BOX_INTER_VERTICAL_LEFT "╣"
#define BOX_INTER_VERTICAL_RIGHT "╠"

#define BOX_INTER_CROSS "╬"

#define True 1
#define False 0

typedef int bool;

/* private */
void _int_to_string(char * dest, const int num);
void _int_to_string_with_comma(char *dest, const int num);
int _get_sum(const int *nums, const int count);

/* public */
char *get_input_string(const char *output, const int withBox);
int get_input_number(const char *output, const int withBox);

void print_input_box(const int length);
void clear_console(void);

char *allocate_string(const char *buffer);
char **allocate_strings(const char **buffer, const int stringCount);

void println_string_cells_with_token(const char **string,
                                     const int stringCount,
                                     const char *token,
                                     const int *tokenLengths,
                                     const char *leftBorder,
                                     const char *centerBorder,
                                     const char *rightBorder);

void println_string_with_token(const char *string,
                               const char *token,
                               const int tokenLength,
                               const char *leftBorder,
                               const char *rightBorder);

void print_string_with_token(const char *string,
                             const char *token,
                             const int tokenLength,
                             const char *leftBorder,
                             const char *rightBorder);

void println_token(const char *token, const unsigned int length);
void print_token(const char *token, const unsigned int length);

void wait_for_enter(void);

void print_moving_string(const char *string, const int flowDirection, const int speed, const int boxLength, const char emptySpaceToken, const char boxBorderLeft, const char boxBorderRight);

void gotoxy(int x, int y);
void movexy(int x, int y);

#endif /* ioutil_h */
