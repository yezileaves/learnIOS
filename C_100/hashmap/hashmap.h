#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _entry {
	int hash;
	void *key;
	void *value;
	struct _entry *next;
} *Entry;

typedef struct _hashmap {
	int size;
	int capacity;
	Entry table;
} *Hashmap;

Hashmap hashmap_init();
void hashmap_put(Hashmap this,void *k,void *v);
void *hashmap_get(Hashmap this,void *k);
void hashmap_remove(Hashmap this,void *k);
void hashmap_free(Hashmap this);
