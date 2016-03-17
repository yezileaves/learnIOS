//
//  NSStringExtension.swift
//  NSStringSplit
//
//  Created by 谢荣盛 on 16/3/16.
//  Copyright © 2016年 yezi. All rights reserved.
//

//老师为什么我的String类型的字符串可以直接放在NSString的数组中啊。都不用转换有点奇怪啊。

import Foundation

extension NSString {
    func split (splitCh:String) -> Array<NSString> {
        var result = [NSString]()
        var string:String = ""
        //现在也没有学到OC所以先把NSString转为String来处理
        let selfStr = self as String
        //计算用作分隔字符串的分隔符字符或字符串的长度
        let splLength = splitCh.characters.count
        //计算字符串的长度
        let strLength = selfStr.characters.count

        var i = 0
        var j = 0
        //while循环，一个一个字符进行对比
        while (i < strLength){
            //if判断，把字符串的字符和分隔字符串的第一个字符相等则为真
            if selfStr[selfStr.startIndex.advancedBy(i)] ==
                splitCh[splitCh.startIndex.advancedBy(0)] {
                //for循环 继续往下对比只要有一个和分隔字符串中的不一样就跳出循环。说明不能从此分割
                for j = 1;j < splLength;j++ {
                    if selfStr[selfStr.startIndex.advancedBy(i + j)] !=
                        splitCh[splitCh.startIndex.advancedBy(j)] {
                        break
                    }
                }
                //判断是否是分隔点。是就把分隔了的字符串保存在数组中。并且把字符串中的字符移除，方便继续拼接
                if j >= splLength {
                    result.append(string)
                    string.removeAll()
                    i += splLength - 1;
                }
                /*如果不是分隔就把当前字符拼接在字符串后面，相当于是一个一个复制字符到新的字符串中，找到分隔点，
                    这个由一个一个字符拼接出来的字符串就相当于分隔出来的字符串*/
                else {
                    string.append(selfStr[selfStr.startIndex.advancedBy(i)])
                }
            }
            //字符如果和分隔字符串的第一个字符都不相等，就直接复制下来拼接到新的字符串上。
            else {
                string.append(selfStr[selfStr.startIndex.advancedBy(i)])
            }
            i++
        }
        //剩下的字符组成的字符串也是分割的另一部分
        result.append(string)
        return result
    }
}