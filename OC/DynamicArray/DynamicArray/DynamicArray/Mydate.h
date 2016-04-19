//
//  Mydate.h
//  DynamicArray
//
//  Created by 谢荣盛 on 16/3/25.
//  Copyright © 2016年 yezi. All rights reserved.
//

#ifndef Mydate_h
#define Mydate_h

#include <stdio.h>

typedef struct Student_ {
    int age;
    char *name;
}Student;

typedef struct MyDate_ {
    int retainCount_;
    Student student;
}MyDate;

MyDate* StudensNew(Student student);
Student StudensGet(MyDate *ins);

#endif /* Mydate_h */
