//
//  main.m
//  DynamicArray
//
//  Created by 谢荣盛 on 16/3/24.
//  Copyright © 2016年 yezi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Array.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        Array *arr = ArrayCreate();
        for (int i = 0; i < 100; i++) {
            ArrayAdd(arr, "hello C");
        }
        
        for (int j = 0; j < ArrayGetLength(arr); j++) {
            printf("%s\n",ArrayGet(arr, j));
        }
        
        ArrayDestroy(arr);
    }
    return 0;
}
