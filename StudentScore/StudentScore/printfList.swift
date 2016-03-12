//
//  printfList.swift
//  StudentScore
//
//  Created by 谢荣盛 on 16/3/12.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation
//格式实在是难看，结构体成员太长，没办法只能再封装一个新的循环打印数组的函数，老师有什么好办法吗？给点意见，这样的代码太难看了
func printfList(studentList:Array<Student>){
    for index in 0...9{
        print("\(studentList[index].name)的平均分是：\(Double(studentList[index].scoreEnglish+studentList[index].scoreMath)/2.0)，数学：\(studentList[index].scoreMath)，英语：\(studentList[index].scoreEnglish)")
    }
}