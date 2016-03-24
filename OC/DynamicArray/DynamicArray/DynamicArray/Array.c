//
//  Array.c
//  DynamicArray
//
//  Created by 谢荣盛 on 16/3/24.
//  Copyright © 2016年 yezi. All rights reserved.
//

#include "Array.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static AnyPointer *allocMemryByCapacity(Array *arr) {
    return malloc(sizeof(AnyPointer) * arr->capacity_);
}

Array *ArrayCreate() {
    Array *arr = malloc(sizeof(Array));
    arr->length_ = 0;
    arr->capacity_ = 32;
    arr->values_ = allocMemryByCapacity(arr);
    return arr;
}

int ArrayGetLength(Array *arr) {
    return arr->length_;
}

void ArrayAdd(Array *arr,AnyPointer value) {
    if (arr->length_ >= arr->capacity_) {
        arr->capacity_ *=2;
        AnyPointer *oldValues = arr->values_;
        arr->values_ = allocMemryByCapacity(arr);
        memcpy(arr->values_,oldValues,arr->length_ * sizeof(AnyPointer));
        free(oldValues);
    }
    arr->values_[arr->length_] = value;
    arr->length_++;
}

AnyPointer ArrayGet(Array *arr,int index) {
    assert(index >= 0 && index < arr->length_);
    return arr->values_[index];
}

void ArrayDestroy(Array *arr) {
    free(arr->values_);
    free(arr);
}

