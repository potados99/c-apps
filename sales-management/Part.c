//
//  Part.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#include "Part.h"

void destructor(Part this) {
    free(this->partName);
    free(this->specification);
    
}

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

void print_sales(Part *parts, const unsigned int length) {
    char *colomnNames[5] = {"NUM", "NAME", "SPEC", "PRICE", "SALES"};
    int spaces[5] = {9, 17, 20, 12, 10};
    
    print_string_with_blank(colomnNames, 5, spaces);
    print_divider(spaces);
    
    for (int i = 0; i < length; ++ i) {
        char num[_SMALL_BUFFER_SIZE];
        char price[_SMALL_BUFFER_SIZE];
        char sales[_SMALL_BUFFER_SIZE];
        
        itos(num, parts[i]->partNum);
        itos(price, parts[i]->price);
        itos(sales, parts[i]->salesCount);

        char *partProperties[5] = { num, parts[i]->partName, parts[i]->specification, price, sales };
        
        print_string_with_blank(partProperties, 5, spaces);
    }
}


