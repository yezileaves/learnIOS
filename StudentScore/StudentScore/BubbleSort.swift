//
//  BubbleSort.swift
//  StudentScore
//
//  Created by 谢荣盛 on 16/3/12.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

//冒泡排序对传入的数组进行排序，通过对数组英语成绩与数学成绩的总和进行比较，就是对他们的平均成绩进行比较
//内层循环负责把最大的结构体放在最后，之后到此最大，如此最小的就冒上来了
func bubbleSort(var sortList:Array<Student>)->Array<Student>{
    var studentTemp = Student()
    for coutOut in 1...(sortList.count - 1){
        for coutIn in 1...(sortList.count-coutOut){
            if sortList[coutIn-1].average > sortList[coutIn].average{
                studentTemp = sortList[coutIn-1]
                sortList[coutIn-1] = sortList[coutIn]
                sortList[coutIn] = studentTemp
                }
            }
        }
    return sortList
}