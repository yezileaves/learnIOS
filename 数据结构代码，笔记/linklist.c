#include <stdio.h>
#include <stdlib.h>

struct _list_node_ {
	int data;
	struct _list_node_ *next;
};
typedef struct _list_node_ lnode_t;

struct _link_list_ {
	lnode_t *head;
	int clen;
	int mlen;
};
typedef struct _link_list_ list_t;

list_t *list_init(int len);
int list_destroy(list_t *list);
int list_insert(list_t *list, int value);
lnode_t *list_create_node(int value);
int list_show(list_t *list);
int list_delete(list_t *list, int target);
int list_modify(list_t *list, int old, int new);
lnode_t *list_search(list_t *list, int target);
int list_reverse(list_t *list);

int main()
{
	list_t *list;
	int value = 10;
	lnode_t *ret;
	
	list = list_init(10);

	while (0 == list_insert(list, value))
		value++;
	
	list_show(list);
#if 0	
	list_delete(list, 100);

	list_modify(list, 100, 250);
	
	ret = list_search(list, 100);
	if (ret == NULL)
		puts("no found");
	else
		printf("SEARCH: %d\n", ret->data);
#endif

	list_reverse(list);
	list_show(list);
#if 0
	list_sort();
#endif
	list_destroy(list);
}

list_t *list_init(int len)
{
	list_t *list;
	
	list = malloc(sizeof(list_t));
	list->head = list_create_node(0);
	list->clen = 0;
	list->mlen = len;

	return list;
}

int list_destroy(list_t *list)
{
	lnode_t *p = list->head;
	lnode_t *tmp;

	while (NULL != p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(list);

	return 0;
}

int list_insert(list_t *list, int value)
{
	lnode_t *new;

	if (list->clen >= list->mlen)
		return -1;

#if 1
	if (list->head->next == NULL) {
		list->head->next = list_create_node(value);
	} else {
		new = list_create_node(value);
		new->next = list->head->next;
		list->head->next = new;
	}
#else
	new = list_create_node(value);
	new->next = list->head->next;
	list->head->next = new;

#endif
	list->clen++;

	return 0;
}

lnode_t *list_create_node(int value)
{
	lnode_t *node;

	node = malloc(sizeof(lnode_t));
	node->data = value;
	node->next = NULL;

	return node;
}

int list_show(list_t *list)
{
	lnode_t *p = list->head->next;

	printf("Clen: %d\tMlen:%d\n", list->clen, list->mlen);
	while (p != NULL) {
		printf("%5d", p->data);
		p = p->next;
	}
	putchar('\n');

	return 0;
}

int list_delete(list_t *list, int target)
{
	lnode_t *p = list->head;
	lnode_t *tmp;

	if (list->clen <= 0)
		return -1;

	while (NULL != p->next) {
		if (p->next->data == target)
			break;
		p = p->next;
	}
	if (p->next == NULL)
		return -1;

	tmp = p->next;
	p->next = tmp->next;
	free(tmp);

	list->clen--;

	return 0;
}

int list_modify(list_t *list, int old, int new)
{
	lnode_t *p = list->head->next;

	while (NULL != p && p->data != old)
		p = p->next;
	if (NULL == p)
		return -1;

	p->data = new;

	return 0;
}

lnode_t *list_search(list_t *list, int target)
{
	lnode_t *p = list->head->next;

	while (NULL != p && p->data != target)
		p = p->next;
	return p;
}

int list_reverse(list_t *list)
{
	lnode_t *p = list->head->next;
	lnode_t *tmp;

	list->head->next = NULL;
	while (NULL != p) {
		tmp = p;
		p = p->next;

		tmp->next = list->head->next;
		list->head->next = tmp;
	}

	return 0;
}
