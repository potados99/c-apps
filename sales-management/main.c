//
//  main.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#include "SalesManagement.h"

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
