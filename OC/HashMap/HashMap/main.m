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
#include "MyData.h"

//参考之前写过的动态数组的引用计数方法，和数据的包装，还有之前的链表实现
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Hashmap map = hashmap_init();
        MyDate *newStudent;
        
        Student student1 = {21,"王尼玛"};
        newStudent = StudensNew(student1);
        hashmap_put(map,"wan",(Object *)newStudent);
        OBJECT_RELEASE(newStudent);
        
        //把添加的key，获取一下
        Student getStudent1 = StudensGet((MyDate *)hashmap_get(map,"wan"));
        printf("age:%d name:%s\n",getStudent1.age,getStudent1.name);
        
        //一样的key值不一样的value，就把之前的value更新
        Student student2 = {22,"老王"};
        newStudent = StudensNew(student2);
        hashmap_put(map,"wan",(Object *)newStudent);
        
        //把添加的一样的key，value不一样获取一下，看是否更改了
        Student getStudent2 = StudensGet((MyDate *)hashmap_get(map,"wan"));
        printf("age:%d name:%s\n",getStudent2.age,getStudent2.name);
        
        //再添加一个哈西值一样的key但是，key不一样，看看是否可以存储
        Student student3 = {23,"小王子"};
        newStudent = StudensNew(student3);
        hashmap_put(map,"anw",(Object *)newStudent);
        OBJECT_RELEASE(newStudent);
        
        //测试一下看看哈西值一样key不一样，能否获取到对应的值
        Student getStudent3 = StudensGet((MyDate *)hashmap_get(map,"anw"));
        printf("age:%d name:%s\n",getStudent3.age,getStudent3.name);
        
        //再添加一个不一样的key但是，key不一样，看看是否可以存储
        Student student4 = {24,"王子"};
        newStudent = StudensNew(student4);
        hashmap_put(map,"an",(Object *)newStudent);
        OBJECT_RELEASE(newStudent);
        
        //测试一下看看不一样key，能否获取到对应的值
        Student getStudent4 = StudensGet((MyDate *)hashmap_get(map,"an"));
        printf("age:%d name:%s\n",getStudent4.age,getStudent4.name);
        
        //测试看看删除一个不存在的key会怎么样
        hashmap_remove(map,"yezi");
        
        hashmap_remove(map, "wan");
        hashmap_remove(map, "anw");
        hashmap_remove(map, "an");
        
        hashmap_free(map);

    }
    return 0;
}
