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
#include "Mydate.h"

//封装申请动态数组空间函数
static AnyPointer *allocMemryByCapacity(Array *arr) {
    return malloc(sizeof(AnyPointer) * arr->capacity_);
}

//创建数组，一开始给数组大小为6，给小一点方便测试
Array *ArrayCreate() {
    Array *arr = malloc(sizeof(Array));
    arr->length_ = 0;
    arr->capacity_ = 6;
    arr->values_ = allocMemryByCapacity(arr);
    return arr;
}

//封装一个求数组当前长度的函数，方便调用
int ArrayGetLength(Array *arr) {
    return arr->length_;
}

//给数组添加新成员，在添加之前先判断数组是否满了，满了就从新申请一块两倍大小的空间，
//把之前的旧数组拷贝到新的数组上。这样就实现了动态调整数组大小的动态数组了
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
    
    OBJECT_RETAIN(value);
}

//根据下角标删除数组成员，在删除之前先用断言判断一下，需要删除的元素是否存在，还需要注意
//当删除的元素不是最后一个时，需要把之后的元素往前移动
void ArrayRemoveAt(Array *arr,int index) {
    assert(index >= 0 && index < arr->length_);
    
    OBJECT_RELEASE(ArrayGet(arr, index));
    
    arr->length_--;
    
    for (int i = index; i < arr->length_; i++) {
        arr->values_[i] = arr->values_[i + 1];
    }
}

//封装根据下角标获取数组成员函数，注意加上断言，防止访问越界
AnyPointer ArrayGet(Array *arr,int index) {
    assert(index >= 0 && index < arr->length_);
    return arr->values_[index];
}

//根据下角标查询数组成员函数，注意加上断言，防止访问越界
void ArrayQuery(Array *arr,int index) {
    assert(index >= 0 && index < arr->length_);
    printf("他是%s,%d岁\n",StudensGet((MyDate*)ArrayGet(arr, index)).name,
           StudensGet((MyDate*)ArrayGet(arr, index)).age);
}

//插入新的成员函数，注意加上断言，插入不能越界插，并且需要注意当数组满时，要能动态调整
//数组空间大小，插入时注意把后面的数组成员往后移
void ArrayInsert(Array *arr,AnyPointer value,int index) {
    assert( index >= 0 && index <= arr->length_);
    if (arr->length_ >= arr->capacity_) {
        arr->capacity_ *=2;
        AnyPointer *oldValues = arr->values_;
        arr->values_ = allocMemryByCapacity(arr);
        memcpy(arr->values_,oldValues,arr->length_ * sizeof(AnyPointer));
        free(oldValues);
    }
    
    for (int i = arr->length_ ;i >= index ;i--) {
        arr->values_[i + 1] = arr->values_[i];
    }
    
    arr->values_[index] = value;
    arr->length_++;
    
    OBJECT_RETAIN(value);
}

//根据下角标更改数组成员
void ArrayChange(Array *arr,AnyPointer value,int index) {
    assert(index >= 0 && index < arr->length_);
    
    arr->values_[index] = value;
    
}


//封装数组遍历函数
void ArrayPrintf(Array *arr) {
    for (int i = 0; i < ArrayGetLength(arr); i++) {
        printf("位置是：%d,名字是：%s,年龄是：%d\n",i + 1,
               StudensGet((MyDate*)ArrayGet(arr, i)).name,
               StudensGet((MyDate*)ArrayGet(arr, i)).age);
    }
}

//销毁数组
void ArrayDestroy(Array *arr) {
    free(arr->values_);
    free(arr);
}

