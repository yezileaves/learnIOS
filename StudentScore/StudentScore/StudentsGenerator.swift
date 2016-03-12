//
//  StudentsGenerator.swift
//  StudentScore
//
//  Created by 谢荣盛 on 16/3/12.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation
//构造一个学生结构体，包涵姓名，英语成绩，数学成绩。还有一个给一个默认值的构造函数init
struct Student {
    var         name:String
    var scoreEnglish:Int
    var    scoreMath:Int
    
    init(name:String="叶尼玛",scoreEnglish:Int=99,scoreMath:Int=99){
        self.name = name
        self.scoreEnglish = scoreEnglish
        self.scoreMath = scoreMath
    }
}