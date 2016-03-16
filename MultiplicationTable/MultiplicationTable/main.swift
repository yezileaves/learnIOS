//
//  main.swift
//  MultiplicationTable
//
//  Created by 谢荣盛 on 16/3/12.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

//使用两个for循环实现九九乘法表：内层循环控制行数，外层循环控制列数，最终实现打印
//在swift中没有print打印是默认换行，为了使打印不换行，需要用参数terminator来控制
//只有在内层循环结束也就是一行打印完了才打印换行，顾在内层循环完了打印一个换行

//func multiplicationTable(){
//    for var mulOut in 1...9 {
//        for var mulIn in 1...mulOut{
//            print("\(mulIn)*\(mulOut)=\(mulIn*mulOut)",terminator:" ")
//        }
//        print("")
//    }
//}
//multiplicationTable()

//老师为什么我把mulOut和mulIn定义在函数中作为局部参数会报警告，提示我应该改为let但是我改了又会错；而我把它们不写成函数又不会有这种的问题？有点郁闷

for var mulOut in 1...9 {
    for var mulIn in 1...mulOut{
        print("\(mulIn)*\(mulOut)=\(mulIn*mulOut)\t",terminator:" ")
    }
    print("")
}