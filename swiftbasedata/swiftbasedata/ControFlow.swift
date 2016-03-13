//
//  ControFlow.swift
//  swiftbasedata
//
//  Created by 谢荣盛 on 16/3/13.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

func controlFlow(){
//if else
    let score = 111
    if score > 100{
        print("奇迹")
    }else if score >= 90{
        print("优秀")
    }else if score >= 80{
        print("良好")
    }else if score >= 70{
        print("可以")
    }else if score >= 60{
        print("及格")
    }else{
        print("不及格")
    }
//    print("hello func")
//switch case
    switch score{
    case 90...100:
        print("优秀")
    case 80..<90:
        print("良好")
    case 70..<80:
        print("可以")
    case 60..<70:
        print("及格")
    case 0..<60:
        print("不及格")
    default:
        print("奇迹")
        
    }

}