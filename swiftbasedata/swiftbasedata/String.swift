//
//  String.swift
//  swiftbasedata
//
//  Created by 谢荣盛 on 16/3/13.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

func string(){
    let s:NSString = "hello yezi"
    let swiftStr:String = s as String
    let ocStr:NSString = swiftStr as NSString
    print(ocStr)
//截取字符串
    let startIndex = swiftStr.startIndex
    let subString = swiftStr.substringFromIndex(startIndex.advancedBy(5))
    let subString2 = swiftStr.substringToIndex(startIndex.advancedBy(5))
    let subString3 = swiftStr.substringWithRange(startIndex.advancedBy(2)...startIndex.advancedBy(5))
    let subString4 = ocStr.substringWithRange(NSRange(location: 2, length: 3))
    print(subString,subString2,subString3,subString4)
    
//分割字符串
    let resulArr = swiftStr.characters.split(" ")
    for o in resulArr{
        print(String(o))
    }
    
//分析字符串
    let content = "hello {Xcode} yezi"
    var tmpStr:String = ""
    for ch in content.characters{
        switch ch{
        case "{":
            tmpStr.removeAll()
        case "}":
            print(tmpStr)
        default:
            tmpStr.append(ch)
        }
    }
    
//Emoji表情
    var smile = "😬📷"
    print(smile)
}