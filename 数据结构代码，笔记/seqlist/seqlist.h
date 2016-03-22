#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>

struct _seqlist_ {
	int *data;
	int clen;
	int mlen;
};
typedef struct _seqlist_ list_t;

extern list_t *list_init(int len);
extern int list_destroy(list_t *list);
extern int list_insert(list_t *list, int value);
extern int list_show(list_t *list);
extern int list_delete(list_t *list, int target);
extern int list_modify_by_value(list_t *list, int old, int new);
extern int list_modify_by_local(list_t *list, int local, int value);
extern int *list_search(list_t *list, int target);
extern int list_reverse(list_t *list);
extern int list_sort(list_t *list);

#endif	/* __SEQLST_H__ */
