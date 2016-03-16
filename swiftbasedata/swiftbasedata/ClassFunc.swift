//
//  ClassFunc.swift
//  swiftbasedata
//
//  Created by 谢荣盛 on 16/3/16.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

func classFunc(){
    let s = Student(age: 16, name: "小花", gender: Gender.Female)
    let b = BoyStudent(age: 2, name: "yezi")
    b.sayHello()
    b.sayHello(s)
    s.eat()
//    s.age = 10
//    print(s.gender)
    
}