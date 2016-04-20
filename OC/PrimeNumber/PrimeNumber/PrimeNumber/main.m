//
//  main.m
//  PrimeNumber
//
//  Created by 谢荣盛 on 16/4/20.
//  Copyright © 2016年 yezi. All rights reserved.
//

#import <Foundation/Foundation.h>

#define NUMBER 1000000

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        //感觉程序运行的时间有点久啊，老师有啥好的算法能提高效率吗？
        //用两层循环实现这个功能，外层循环控制每一个一百万以内的数，每一个用来尝试计算
        //内存循环用来判断是否有能被2～i－1的数整除，只要能整除就跳出循环，不用计算后面
        //的提高效率
        int i,j;
        for (i = 1; i < NUMBER; i++) {
            for (j = 2; j < i; j++) {
                if (!(i%j))
                    break;
                if (i == j + 1)
                    printf("%d以内的质数有%d\n",NUMBER,i);
            }
            if (2 == i)
                printf("%d以内的质数有%d\n",NUMBER,i);
        }
    }
    return 0;
}
