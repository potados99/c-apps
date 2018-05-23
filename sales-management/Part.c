//
//  Part.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#include "Part.h"

///
/// destructor
/// Purpose: to free allocated objects
///
void destructor(Part this) {
    free(this->partName);
    free(this->specification);
}

///
/// new_Part
/// Purpose: to return newly instanciated struct _Part * newPart
///
Part new_Part(int partNum,
              char *partName,
              char *specification,
              int price,
              int salesCount) {
    
    Part newPart = (Part)malloc(sizeof(_Part));
    newPart->partNum = partNum;
    newPart->partName = partName;
    newPart->specification = specification;
    newPart->price = price;
    newPart->salesCount = salesCount;
    
    return newPart;
}

///
/// print_sales
/// Purpose: to display sales data in form of table
/// Description: I used print_string_with_blank function to get center-aligned table.
///             Non-string variables are converted to string to be processed as an element of char * array.
///
void print_sales(Part *parts, const unsigned int length) {
    char *colomnNames[5] = {"NUM", "NAME", "SPEC", "PRICE", "SALES"};
    int spaces[5] = {9, 17, 20, 12, 10};
    
    print_string_with_blank(colomnNames, 5, spaces); /* print top row in center-aligned form */
    print_divider(spaces); /* print a row for division */
    
    for (int i = 0; i < length; ++ i) {
        /* buffers to contain the converted variables */
        char num[_SMALL_BUFFER_SIZE];
        char price[_SMALL_BUFFER_SIZE];
        char sales[_SMALL_BUFFER_SIZE];
        
        /* int to string */
        itos(num, parts[i]->partNum);
        itos(price, parts[i]->price);
        itos(sales, parts[i]->salesCount);

        char *partProperties[5] = { num, parts[i]->partName, parts[i]->specification, price, sales };
        
        print_string_with_blank(partProperties, 5, spaces);
    }
}


