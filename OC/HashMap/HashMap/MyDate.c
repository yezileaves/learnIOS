//
//  MyDate.c
//  HashMap
//
//  Created by 谢荣盛 on 16/4/27.
//  Copyright © 2016年 yezi. All rights reserved.
//

#include "MyDate.h"
#include <stdlib.h>
#include "Object.h"

//申请成员空间函数
MyDate* StudensNew(Student student) {
    MyDate *ins = malloc(sizeof(MyDate));
    ObjectRetain((Object *)ins);
    ins->student.age = student.age;
    ins->student.name = student.name;
    return ins;
    
}

//封装获取成员值
Student StudensGet(MyDate *ins) {
    return ins->student;
}