//
//  Part.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//

#include "Part.h"

Part new_Part(int partNum,
              char *partName,
              char *specification,
              int price,
              int sales) {
    
    Part newPart = (Part)malloc(sizeof(_Part)+1);
    newPart->partNum = partNum;
    newPart->partName = partName;
    newPart->specification = specification;
    newPart->price = price;
    newPart->sales = sales;
    newPart->revenue = price * sales;
    
    return newPart;
}

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
