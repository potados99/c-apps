//
//  main.c
//  to-do-list
//
//  Created by potados on 2018. 4. 10..
//  Copyright © 2018 potados. All rights reserved.
//

#include <stdio.h>
#include "procedure.h"

int main(int argc, const char * argv[]) {
    
    language = 1;
    
    List myList;
    init_list(&myList);
    
    write_list(&myList);
    
    return 0;
    
}
