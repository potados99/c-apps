//
//  main.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#include "Part.h"

int main(int argc, const char * argv[]) {
    /* Part is a pointer of struct _Part */
    
    Part a = new_Part(1001, "Hard disk", "This", 135000, 0);
    Part b = new_Part(1002, "CPU", "is", 235000, 0);
    Part c = new_Part(1003, "Main board", "very", 122000, 0);
    Part d = new_Part(1004, "Monitor", "awesome.", 260000, 0);
    Part e = new_Part(1005, "DVD-RW", "Isn't it?", 73500, 0);

    /* Actually it is an array of pointer */
    Part parts[5] = { a, b, c, d, e };
    
    print_sales(parts, 5);
    
    return 0;
}
