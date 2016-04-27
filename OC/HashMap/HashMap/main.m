//
//  main.m
//  HashMap
//
//  Created by 谢荣盛 on 16/4/21.
//  Copyright © 2016年 yezi. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "HashMap.h"
#include "Object.h"
#include "MyDate.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Hashmap map = hashmap_init();
        MyDate *newStudent;
        
        Student student1 = {21,"王尼玛"};
        newStudent = StudensNew(student1);
        hashmap_put(map,"wang",(Object *)newStudent);
        OBJECT_RELEASE(newStudent);
        
        Student student = StudensGet((MyDate *)hashmap_get(map,"wang"));
        printf("age:%d name:%s\n",student.age,student.name);
        
        hashmap_remove(map,"wang");
        hashmap_free(map);

    }
    return 0;
}