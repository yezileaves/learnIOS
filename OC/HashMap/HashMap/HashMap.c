//
//  HashMap.c
//  HashMap
//
//  Created by 谢荣盛 on 16/4/21.
//  Copyright © 2016年 yezi. All rights reserved.
//

#include "HashMap.h"

int hashCode(char *pStr) {
    int i,h = 0;
    int size = (int)strlen(pStr);
    
    if (size == 0)
        return 0;
    else {
        for (i = 0;i < size; i++) {
            //h = 31 * h + *pStr++;
            h += *pStr++;
        }
        return h;
    }
}

int indexFor(int h,int length) {
    return h % (length -1);
}

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

void hashmap_put(Hashmap this,char *k,AnyPointer v) {
    int hashcode,i;
    Entry e;
    AnyPointer oldValue;
    hashcode = hashCode(k);
    i = indexFor(hashcode,this->capacity);
    printf("hashcode:%d i:%d\n",hashcode,i);
    for (e = this->table + i,e = e->next;e != NULL;e = e->next) {
        if ((e->hash == hashcode) && (e->key == k || strcmp(e->key,k) == 0)) {
            oldValue = e->value;
            e->value = v;
            
            //return oldValue;
        }
    }
    addEntry(this ,k,v,hashcode,i);
    //return NULL;
}
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

void hashmap_remove(Hashmap this,char *k) {
    int hashcode,i;
    Entry e,preE;
    hashcode = hashCode(k);
    i = indexFor(hashcode,this->capacity);
    for (e = this->table + i,preE = e,e = e->next;e != NULL;preE = e,e = e->next) {
        if (e->hash == hashcode && (e->key == k || strcmp(e->key,k) == 0)) {
            OBJECT_RELEASE(hashmap_get(this, k));
            if (e->next == NULL) {
                preE->next = NULL;
            }else {
                preE->next = e->next;
            }
            e->next = NULL;
            this->size--;
            free(e);
        }
    }
}

void hashmap_free(Hashmap this) {
    int i;
    Entry e,item;
    for (i = 0;i < this->capacity;i++) {
        for (e = this->table + i,e = e->next;e != NULL;e = e->next) {
            item = e;
            free(item);
        }
    }
    
    this->size = 0;
    this->capacity = 0;
    free(this->table);
    free(this);
}


