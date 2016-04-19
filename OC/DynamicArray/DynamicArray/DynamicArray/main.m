//
//  main.m
//  DynamicArray
//
//  Created by 谢荣盛 on 16/3/24.
//  Copyright © 2016年 yezi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Array.h"
#include "Object.h"
#include "Mydate.h"
#include "string.h"

//整个工程分为四个部分，第一个部分为主函数，第二个部分为动态数组的实现和数组相关的操作，
//第三部分为内存管理，用引用计数实现，第四部分为数据的包装，以及一些操作。
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        //创建数组arr
        Array *arr = ArrayCreate();
        
        //创建学生结构体
        MyDate *intValue;
        Student student1 = {21, "王尼玛"};
        Student student2 = {22, "曹尼玛"};
        Student student3 = {25, "赵尼玛"};
        Student student4 = {18, "覃尼玛"};
        Student student5 = {19, "孙尼玛"};
        Student student6 = {20, "雷尼玛"};
        Student student7 = {23, "李尼玛"};
        Student student8 = {24, "蒙尼玛"};
        Student student9 = {17, "小王子"};
        Student student10 = {40, "老王子"};
        
        //数据包装并且把数据添加进数组里面，并且使用引用计数，实现准确的内存管理
        intValue = StudensNew(student1);
        ArrayAdd(arr, (Object*)intValue);
        OBJECT_RELEASE(intValue);
        
        intValue = StudensNew(student2);
        ArrayAdd(arr, (Object*)intValue);
        OBJECT_RELEASE(intValue);
        
        intValue = StudensNew(student3);
        ArrayAdd(arr, (Object*)intValue);
        OBJECT_RELEASE(intValue);
        
        intValue = StudensNew(student4);
        ArrayAdd(arr, (Object*)intValue);
        OBJECT_RELEASE(intValue);
        
        intValue = StudensNew(student5);
        ArrayAdd(arr, (Object*)intValue);
        OBJECT_RELEASE(intValue);
        
        intValue = StudensNew(student6);
        ArrayAdd(arr, (Object*)intValue);
        OBJECT_RELEASE(intValue);
        
        intValue = StudensNew(student7);
        ArrayAdd(arr, (Object*)intValue);
        OBJECT_RELEASE(intValue);
        
        intValue = StudensNew(student8);
        ArrayAdd(arr, (Object*)intValue);
        OBJECT_RELEASE(intValue);
        
        //使用for循环遍历一遍数组，把数组成员信息打印出来
        printf("打印了数组所有元素\n");
        ArrayPrintf(arr);
        
        //测试数组的删除功能并且在删除数组成员之后再次遍历数组
        printf("把位置3的赵尼玛删了\n");
        ArrayRemoveAt(arr, 2);
        ArrayPrintf(arr);
        
        //测试查询功能
        printf("查询位置2的是谁\n");
        ArrayQuery(arr,1);

        //测试插入功能，插入新的成员后再遍历一遍数组,注意引用计数需要释放一次
        printf("在位置6插入小王子\n");
        intValue = StudensNew(student9);
        ArrayInsert(arr,(Object*)intValue,5);
        OBJECT_RELEASE(intValue);
        ArrayPrintf(arr);
        
        //测试数组的更改功能，再遍历一遍数组
        printf("把位置6的小王子更改为老王子\n");
        intValue = StudensNew(student10);
        ArrayChange(arr,(Object*)intValue,5);
        ArrayPrintf(arr);
        
        //最后把数组销毁
        ArrayDestroy(arr);
        
        
    }
    return 0;
}
