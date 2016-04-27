//
//  Object.c
//  HashMap
//
//  Created by 谢荣盛 on 16/4/27.
//  Copyright © 2016年 yezi. All rights reserved.
//

#include "Object.h"

#include "Object.h"
#include <stdlib.h>

//引用计数，增加计数
void ObjectRetain(Object *obj) {
    obj->retainCount_++;
}

//减少计数，当计数小于等于零时，释放对象
void ObjectRelease(Object *obj) {
    obj->retainCount_--;
    
    if (obj->retainCount_ <= 0) {
        free(obj);
        
        printf("The Object is released\n");
    }
}

//封装一个获取当前计数值函数
int ObjectRetainCount(Object *obj) {
    return obj->retainCount_;
}