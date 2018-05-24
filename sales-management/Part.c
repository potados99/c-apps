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
              int sales) {
    
    Part newPart = (Part)malloc(sizeof(_Part));
    newPart->partNum = partNum;
    newPart->partName = partName;
    newPart->specification = specification;
    newPart->price = price;
    newPart->sales = sales;
    newPart->revenue = price * sales;
    
    return newPart;
}


