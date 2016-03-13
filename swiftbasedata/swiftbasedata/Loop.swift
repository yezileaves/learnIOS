//
//  Loop.swift
//  swiftbasedata
//
//  Created by 谢荣盛 on 16/3/13.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

func loop(){
//范围
    let l = 0..<100
    let l2 = Range<Int>(start: 0, end: 100)
    print(l2,l)

//forEach
    l2.forEach { (i:Int) -> () in
//        print(i)
    }
    
//for循环
    for i in l2{
        if i == 50{
//            break
            continue
        }
//        print(i)
    }
    
//while循环
    var i2 = 0
    while i2 < 100 {
//        print(i2)
        i2++
    }
    
//repeat while == do while
    var i3 = 0
    repeat{
        print("hello repeat while\(i3)")
        i3++
    }while i3 < 100
    
}