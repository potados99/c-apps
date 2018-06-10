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

#define _DEAULT_EXPORT_FILE_NAME "part_report.txt"
#define _DEAULT_DATA_FILE_NAME "part.txt"


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
    system("chcp 65001");
    puts("\n> Programming assignment #4");
    puts("> Sales-management\n");
    rewind(stdout);
    _sleep(1000*0.4);
    puts("> Author info:");
    puts("> ID: 201701562");
    puts("> Name: Byeong Jun Song\n");
    rewind(stdout);
    _sleep(1000*0.4);
    print_moving_string("Loading", STRING_FLOW_DIRECTION_LEFT, STRING_FLOW_SPEED_MID, _MAIN_MENU_WIDTH, ' ', '[', ']');
#else
    puts("\n> Programming assignment #4");
    puts("> Sales-management\n");
    print_moving_string("Loading", STRING_FLOW_DIRECTION_LEFT, STRING_FLOW_SPEED_FAST, _MAIN_MENU_WIDTH, ' ', '[', ']');
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

    const char *dataFilePath;
    const char *exportFilePath;
    
    if (argc > 2) {
        dataFilePath = argv[1];
        exportFilePath = argv[2];
    }
    else if (argc > 1) {
        char cwdExport[128];
        getcwd(cwdExport, sizeof(cwdExport));
        
        dataFilePath = argv[1];
        exportFilePath = join_path((cwdExport), _DEAULT_EXPORT_FILE_NAME);
    }
    else {
        char cwdData[128];
        getcwd(cwdData, sizeof(cwdData));
        
        dataFilePath = join_path((cwdData), _DEAULT_DATA_FILE_NAME);
        
        char cwdExport[128];
        getcwd(cwdExport, sizeof(cwdExport));
        
        exportFilePath = join_path((cwdExport), _DEAULT_EXPORT_FILE_NAME);
    }
    
    start_main_loop(dataFilePath, exportFilePath, myList);
    
    destructor(myList);
    
    outro();
    
    return 0;
}

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
