//
//  StringExtension.swift
//  swiftbasedata
//
//  Created by 谢荣盛 on 16/3/16.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

extension String {
    func endWith(end:String) -> Bool {
        var result = true
        let rAll = self.characters.reverse()
        let rEnd = end.characters.reverse()
        
        for i in 0 ..< rEnd.count {
            if rAll[rAll.startIndex.advancedBy(i)] != rEnd[rEnd.startIndex.advancedBy(i)] {
                result = false
                break
            }
        }
        return result
    }
}

func stringExtension() {
    let str:String = "yezi.mp3"
    print(str.endWith(".mp3"))
}