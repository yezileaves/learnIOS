#include <stdio.h>
#include <stdlib.h>

struct _seqlist_ {
	int *data;
	int clen;
	int mlen;
};
typedef struct _seqlist_ list_t;

list_t *list_init(int len);
int list_destroy(list_t *list);
int list_insert(list_t *list, int value);
int list_show(list_t *list);

int main()
{
	list_t *list;
	int value;
	
	list = list_init(10);

	value = 10;
	while (0 == list_insert(list, value))
		value++;

	list_show(list);

	list_delete(list, 5);
	list_show(list);
#if 0
	list_modify();
	list_search();
	list_reverse();
	list_sort();
#endif
	list_destroy(list);

	return 0;
}

list_t *list_init(int len)
{
	list_t *list;

	list = malloc(sizeof(list_t));
	list->data = malloc(sizeof(int) * len);
	list->clen = 0;
	list->mlen = len;

	return list;
}

int list_destroy(list_t *list)
{
	free(list->data);
	free(list);

	return 0;
}

int list_insert(list_t *list, int value)
{
	if (list->clen >= list->mlen)
		return -1;
	
	list->data[list->clen++] = value;

	return 0;
}

int list_show(list_t *list)
{
	int i;

	printf("Clen: %d\tMlen: %d\n", list->clen, list->mlen);
	for (i = 0; i < list->clen; i++)
		printf("%3d", list->data[i]);
	putchar('\n');

	return 0;
}
