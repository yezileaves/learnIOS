//
//  Class.swift
//  swiftbasedata
//
//  Created by 谢荣盛 on 16/3/16.
//  Copyright © 2016年 yezi. All rights reserved.
//

import Foundation

public enum Gender:String {
    case Male = "男"
    case Female = "女"
}

public class Student :Human{
    private var _age:Int
    private var _name:String
    private var _gender:Gender
    
    init(age:Int,name:String,gender:Gender = Gender.Female){
        _age = age
        _name = name
        _gender = gender
    }
    public func sayHello() {
        print("\(_name) say hello")
    }
    //方法重载
    public func sayHello(to:Student) {
        print("\(_name) say hello to \(to.name)")
    }
//    public func getAge()->Int{
//        return _age
//    }
//    public func getName()->String{
//        return _name
//    }
    public var age:Int{
        get{
            print("正在获取age值")
            return _age
        }
        set {
            _age = newValue
        }
    }
    public var name:String{
        get {
            print("正在获取name值")
            return _name
        }
        set {
            _name = newValue
        }
    }
    public var gender:Gender{
        get {
            return _gender
        }
    }
    public func eat() {
        print("\(_name) eat")
    }
    
}

class BoyStudent: Student {
    init(age: Int, name: String) {
        super.init(age: age, name: name ,gender: Gender.Male)
    }
    //方法重写
    override func sayHello() {
        super.sayHello()
        
        print("Boy \(name) say hello")
    }
    //
}
