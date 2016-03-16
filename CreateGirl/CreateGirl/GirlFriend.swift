//
//  GirlFriend.swift
//  CreateGirl
//
//  Created by 谢荣盛 on 16/3/15.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

//使用结构体对女朋友进行定义，在给实例方法，用于生成随机年龄，和名字。还需要有个约会功能，就是一个方法。
//问题，为什么我不给name ＝ “”会报错呢？有点奇怪

struct GirlFriend {
    var name:String = ""
    var age:UInt32
    
    init(){
        let nameLong = UInt32(3) + arc4random_uniform(3)
        
        for _ in 0 ..< nameLong {
            let randomNumber = UInt32(65) + arc4random_uniform(26)
            name += String(Character(UnicodeScalar(randomNumber)))
        }
        
        age = UInt32(18) + arc4random_uniform(11)
    }
    func date(){
        print("have a date")
    }
}