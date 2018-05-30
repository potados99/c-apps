//
//  main.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//

#include "SalesManagement.h"
#include "Part.h"
#include "ioutil.h"

/*
 [Basic concept]
 Specification
 - What is this program: A sales management program
 - What does this program do: Save, process and display data of each product
 
 [Implementation]
 - How to handle the data:  - store properties of product in a struct (struct _Part).
                            - store pointers of those structs in array (struct _Part * [] or struct _Part **).
                            - store the name of pointer array in a struct (struct _SalesList).
                            - and also store the length of the array in the struct.
                            - allocate size of struct _SalesList and catch the address.
                            - carry that. access the real value using the pointer.
 
 - How to group functions:  group by relavant data so that
                            a data type and functions that handle the data are in one file.
                            organize files hierarchically.
                            avoid Cross-reference.
 
 [Source]
 main.c :               instanciate SalesList and start loop with that
 
 SalesManagement.h :    define 'struct _SalesList' which conatins
                        - array of 'struct _Part' type pointer(struct _Part *)
                        - number of that array
 
                        define 'struct _SalesList *' with 'SalesList' to
                        - handle object of that type by reference
                        - avoid making overhead when passing list by value
 
                        define routines and functions required to
                        initiate and run the app
 
 Part.h :               define 'struct _Part' which contaions
                        properties of each part
                        define 'struct _Part' with 'Part' to
                        handle them with pointer
 
 ioutil.h :             define some helper functions used to
                        - get inputs from stdin
                        - print string in a cell of table with
                          horizontally center-aligned form
                        - ask for user input until 'Enter' is pressed
 
 [Notes]
 - No non ascii character to avoid encoding issue in VS
*/

static inline void intro() {
#if defined __WIN32__ || defined _MSC_VER
    puts("\n> Programming assignment #3");
    puts("> Sales-management\n");
    rewind(stdout);
    _sleep(1000*0.4);
    puts("> Author info:");
    puts("> ID: 201701562");
    puts("> Name: Byeong Jun Song\n");
    rewind(stdout);
    _sleep(1000*0.4);
    print_moving_string("Loading", STRING_FLOW_DIRECTION_LEFT, STRING_FLOW_SPEED_SLOW, _MAIN_MENU_WIDTH, ' ', '[', ']');
#else
    puts("\n> Programming assignment #3");
    puts("> Sales-management\n");
    print_moving_string("Loading", STRING_FLOW_DIRECTION_LEFT, STRING_FLOW_SPEED_MID, _MAIN_MENU_WIDTH, ' ', '[', ']');
#endif
}

static inline void outro() {
#if defined __WIN32__ || defined _MSC_VER
    puts("Program ended.");
    getchar();
    puts("Disposing console.");
#endif
}

int main(int argc, const char * argv[]) {
    clear_console();
    intro();
    clear_console();

    static const char *colomnNames[_COLUMN_NUM] = {
        "Index",
        "Number",
        "Name",
        "Specification",
        "Price",
        "Sales",
        "Revenue"
    };
    
    static const int columnSpaces[_COLUMN_NUM] = {
        8,  // index
        11, // number
        17, // name
        20, // specification
        12, // price
        10, // sales
        15  // revenue
    };

    SalesList myList = new_SalesList(colomnNames, columnSpaces);

    add_to_list(myList, new_Part(1001, allocate_string("Hard disk"), allocate_string("NONE"), 135000, 0));
    add_to_list(myList, new_Part(1002, allocate_string("CPU"), allocate_string("NONE"), 235000, 0));
    add_to_list(myList, new_Part(1003, allocate_string("Main board"), allocate_string("NONE"), 122000, 0));
    add_to_list(myList, new_Part(1004, allocate_string("Monitor"), allocate_string("NONE"), 260000, 0));
    add_to_list(myList, new_Part(1005, allocate_string("DVD-RW"), allocate_string("NONE"), 73500, 0));

    start_main_loop(myList);
    
    destructor(myList);
    
    outro();
    
    return 0;
}

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
