//
//  main.swift
//  CreateGirl
//
//  Created by 谢荣盛 on 16/3/15.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

//循环生成，打印。每次生成的名字和年龄都不一样。

for number in 0 ..< 1000 {
    var girlFriend = GirlFriend()
    print("name:\(girlFriend.name),\t age:\(girlFriend.age)")
    
}