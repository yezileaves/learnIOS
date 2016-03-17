//
//  main.swift
//  NSStringSplit
//
//  Created by 谢荣盛 on 16/3/16.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

var str:NSString = "yezi&&yezi&&leaves"
let result = str.split("&&")

for subStr in result {
    print(subStr)
}


