//
//  Optional.swift
//  swiftbasedata
//
//  Created by 谢荣盛 on 16/3/13.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

func optional(){
//可选类型 好处是可以在操作和访问空的时候，程序不挂掉；
    var s:Optional<String> = nil
    s = "hello"
    let s1:String? = "yezileaves"
    let index = s1?.startIndex.advancedBy(3)
    let subString = s1?.substringToIndex(index!)
    print(index)
    print(subString)
    
//封包wrap 拆包unwrap
    print(s)
    print(s!)
    let s2:ImplicitlyUnwrappedOptional<String> = "yezileaves"
    //let s3:String! = "yezileaves"
    
    let index2 = s2.startIndex.advancedBy(3)
    let subString2 = s2.substringToIndex(index2)
    
    print(subString2)
    
}