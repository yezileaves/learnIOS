//
//  HashMap.c
//  HashMap
//
//  Created by 谢荣盛 on 16/4/21.
//  Copyright © 2016年 yezi. All rights reserved.
//

#include "HashMap.h"

//计算hash值，把每个字母对应的assicii值相加
int hashCode(char *pStr) {
    int i,h = 0;
    int size = (int)strlen(pStr);
    
    if (size == 0)
        return 0;
    else {
        for (i = 0;i < size; i++) {
            h += *pStr++;
        }
        return h;
    }
}

//通过哈西值计算出该把数据放在数组哪个位置
int indexFor(int h,int length) {
    return h % (length -1);
}

//把数据通过尾插法放在相应的链表中，并注意使用引用计数来管理内存；
void addEntry(Hashmap this,char *k,AnyPointer v,int hashcode,int i)
{
    Entry item = malloc(sizeof(struct _entry));
    Entry e = this->table + i;
    
    do {
        if (e->next == NULL) {
            item->hash = hashcode;
            item->key = k;
            item->value = v;
            item->next = NULL;
            
            e->next = item;
            break;
        }
    } while((e = e->next) != NULL);
    
    this->size++;
    
    OBJECT_RETAIN(v);
}

//通过key的哈西值，把数据放在hashmap中，如果key值一样就替换原来的数据；
AnyPointer hashmap_put(Hashmap this,char *k,AnyPointer v) {
    int hashcode,i;
    Entry e;
    AnyPointer oldValue;
    //计算字符串哈西值
    hashcode = hashCode(k);
    //把哈西值转换为数组下角标
    i = indexFor(hashcode,this->capacity);
    //查找是否已经有key值，如果有了就更新数据
    for (e = this->table + i,e = e->next;e != NULL;e = e->next) {
        if ((e->hash == hashcode) && (e->key == k || strcmp(e->key,k) == 0)) {
            oldValue = e->value;
            e->value = v;
            
            return oldValue;
        }
    }
    //添加数据
    addEntry(this ,k,v,hashcode,i);
    return NULL;
}

//通过key值获取到再hashmap中的数据
AnyPointer hashmap_get(Hashmap this,char *k) {
    int hashcode,i;
    Entry e;
    hashcode = hashCode(k);
    i = indexFor(hashcode,this->capacity);
    
    for (e = this->table + i,e = e->next;e != NULL;e = e->next) {
        if (e->hash == hashcode && (e->key == k || strcmp(e->key,k) == 0)) {
            return e->value;
        }
        
    }
    printf("没有对应的key\n");
    return NULL;
}

//初始化hashmap规定数组空间大小为16；
Hashmap hashmap_init() {
    int i;
    Hashmap map = malloc(sizeof(struct _hashmap));
    map->size = 0;
    map->capacity = 16;
    map->table = malloc(sizeof(struct _entry) * map->capacity);
    for (i = 0;i < map->capacity;i++) {
        (map->table + i)->next = NULL;
    }
    return map;
}

//移除数据，并注意使用引用计数进行内存管理
void hashmap_remove(Hashmap this,char *k) {
    int hashcode,i;
    Entry e,preE;
    hashcode = hashCode(k);
    i = indexFor(hashcode,this->capacity);
    
    for (e = this->table + i,preE = e,e = e->next;e != NULL;preE = e,e = e->next) {
        if (e->hash == hashcode && (e->key == k || strcmp(e->key,k) == 0)) {
/*老师感觉这里引用计数是不是用得有问题啊，我这里如果用完free，后面又
 *free（e）是不是有点问题啊？
*/
            OBJECT_RELEASE(hashmap_get(this, k));
            if (e->next == NULL) {
                preE->next = NULL;
            }else {
                preE->next = e->next;
            }
            e->next = NULL;
            this->size--;
            free(e);
            //第二次修改，只要找到要删除的key就跳出循环，防止出现指针使用不当
            break;
        }
    }
    if(e == NULL) {
        printf("没有找到相应的key\n");
    }
}

//释放整个hashmap;
void hashmap_free(Hashmap this) {
    int i;
    Entry e,item;
    for (i = 0;i < this->capacity;i++) {
//        for (e = this->table + i,e = e->next;e != NULL;e = e->next;) {
//            item = e;
//            free(item);
//        }
        //把for循环改成while循环，并且修正了指针free了又使用的情况
        e = this->table + i,e = e->next;
        while (e != NULL) {
            item = e;
            e = e->next;
            free(item);
        }
    }
    
    this->size = 0;
    this->capacity = 0;
    free(this->table);
    free(this);
}


