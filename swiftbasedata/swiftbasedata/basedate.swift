//
//  basedate.swift
//  swiftbasedata
//
//  Created by 谢荣盛 on 16/3/13.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation
func baseDate(){
//字符串，字符串连接
let s = "hello world"
var s2 = "yezileaves"
//print("String s:"+s+s2+"hah"+",\(s)神奇的swift\(10)")
//print(<#T##items: Any...##Any#>, separator: <#T##String#>, terminator: <#T##String#>)

//数组
var arr = [1,2,3,4,5,6,3.4,"swift"]
arr[3] = 5
arr.append(110)
arr.removeFirst()
arr.removeAtIndex(arr.startIndex)
//print(arr)
//空数组
var arr2 = [String]()
arr2.append("hello")
//print(arr2)

//字典
var dic = ["name":"yezi","age":11]
//dic.removeAtIndex(dic.startIndex)
dic["language"] = "swift"
//空字典
var dic2 = [String:NSObject]()
dic["work"] = "haha"
//print(dic["age"],dic["name"])
}