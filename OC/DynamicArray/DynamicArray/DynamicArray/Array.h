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

typedef void* AnyPointer;

typedef struct Array_ {
    int length_;
    int capacity_;
    AnyPointer *values_;
}Array;

Array *ArrayCreate();
int ArrayGetLength(Array *arr);
void ArrayAdd(Array *arr,AnyPointer value);
AnyPointer ArrayGet(Array *arr,int index);
void ArrayDestroy(Array *arr);

#endif /* Array_h */
