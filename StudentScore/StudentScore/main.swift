//
//  main.swift
//  StudentScore
//
//  Created by 谢荣盛 on 16/3/12.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

var studentList = [Student]()

//为什么不能studentList[0]这样赋值呢老师？只能通过apend方法添加
studentList.append(Student())
studentList.append(Student(name: "王尼玛", scoreEnglish: 85, scoreMath: 99))
studentList.append(Student(name: "曹尼玛", scoreEnglish: 40, scoreMath: 60))
studentList.append(Student(name: "李尼玛", scoreEnglish: 84, scoreMath: 88))
studentList.append(Student(name: "谢尼玛", scoreEnglish: 74, scoreMath: 91))
studentList.append(Student(name: "覃尼玛", scoreEnglish: 66, scoreMath: 55))
studentList.append(Student(name: "赵尼玛", scoreEnglish: 86, scoreMath: 77))
studentList.append(Student(name: "钱尼玛", scoreEnglish: 56, scoreMath: 56))
studentList.append(Student(name: "孙尼玛", scoreEnglish: 79, scoreMath: 66))
studentList.append(Student(name: "雷尼玛", scoreEnglish: 89, scoreMath: 95))

//按平均分从低到高排序
studentList = bubbleSort(studentList)
//打印学生信息
//printfList(studentList)

for student in studentList{
    student.printfSelf()
}
