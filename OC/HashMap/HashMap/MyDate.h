//
//  MyDate.h
//  HashMap
//
//  Created by 谢荣盛 on 16/4/27.
//  Copyright © 2016年 yezi. All rights reserved.
//

#ifndef MyDate_h
#define MyDate_h

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

#endif /* MyDate_h */
