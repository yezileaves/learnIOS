//
//  HashMap.h
//  HashMap
//
//  Created by 谢荣盛 on 16/4/21.
//  Copyright © 2016年 yezi. All rights reserved.
//

#ifndef HashMap_h
#define HashMap_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Object.h"

typedef Object* AnyPointer;

typedef struct _entry {
    int hash;
    char *key;
    AnyPointer value;
    struct _entry *next;
} *Entry;

typedef struct _hashmap {
    int size;
    int capacity;
    Entry table;
} *Hashmap;

Hashmap hashmap_init();
void hashmap_put(Hashmap this,char *k,AnyPointer v);
AnyPointer hashmap_get(Hashmap this,char *k);
void hashmap_remove(Hashmap this,char *k);
void hashmap_free(Hashmap this);


#endif /* HashMap_h */
