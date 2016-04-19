//
//  Array.h
//  DynamicArray
//
//  Created by 谢荣盛 on 16/3/24.
//  Copyright © 2016年 yezi. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <stdio.h>
#include "Object.h"

typedef Object* AnyPointer;

typedef struct Array_ {
    int length_;
    int capacity_;
    AnyPointer *values_;
}Array;

Array *ArrayCreate();
int ArrayGetLength(Array *arr);
void ArrayAdd(Array *arr,AnyPointer value);
void ArrayRemoveAt(Array *arr,int index);
AnyPointer ArrayGet(Array *arr,int index);
void ArrayDestroy(Array *arr);
void ArrayQuery(Array *arr,int index);
void ArrayInsert(Array *arr,AnyPointer value,int index);
void ArrayChange(Array *arr,AnyPointer value,int index);
void ArrayPrintf();

#endif /* Array_h */
