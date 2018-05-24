//
//  main.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#include "SalesManagement.h"

/*
 [Basic concept]
 Specification
 - What is this program: A sales management program
 - What does this program do: Save, process and display data of each product
 
 Implementation
 - How to handle the data:  - store properties of product in a struct (struct _Part).
                            - store pointers of those structs in array (struct _Part * [] or struct _Part **).
                            - store the name of pointer array in a struct (struct _SalesList).
                            - and also store the length of the array in the struct.
                            - allocate size of struct _SalesList and catch the address.
                            - carry that. access the real value using the pointer.
 
 - How to divide codes into functions:
 
 
 
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
 
 
 
 
*/









int main(int argc, const char * argv[]) {
    
    SalesList myList = new_SalesList();

    add_to_sales_list(myList, new_Part(1001, "Hard disk", "NONE", 135000, 0));
    add_to_sales_list(myList, new_Part(1002, "CPU", "NONE", 235000, 0));
    add_to_sales_list(myList, new_Part(1003, "Main board", "NONE", 122000, 0));
    add_to_sales_list(myList, new_Part(1004, "Monitor", "NONE", 260000, 0));
    add_to_sales_list(myList, new_Part(1005, "DVD-RW", "NONE", 73500, 0));
    
    start_main_loop(myList);
    
    return 0;
}
