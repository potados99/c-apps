//
//  Part.h
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//

#ifndef Part_h
#define Part_h

#include <stdio.h>
#include <stdlib.h>
#include "ioutil.h"

/* private */
///
/// struct _Part
/// Purpose: to store properties of part
///
typedef struct _Part{
    int partNum;
    char *partName;
    char *specification;
    int price;
    int sales;
    int revenue;
} _Part;

/* public */
///
/// Part
/// Purpose: to use as a reference of struct _Part
///
typedef _Part * Part;

Part new_Part(int partNum,
              char *partName,
              char *specification,
              int price,
              int sales);

#endif /* Part_h */

//
//  Author
//  ID: 201701562
//  Name: Byeong Jun Song
//
