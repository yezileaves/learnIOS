#include "seqlist.h"

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
		printf("%5d", list->data[i]);
	putchar('\n');

	return 0;
}

int list_delete(list_t *list, int target)
{
	int i;

	if (list->clen <= 0)
		return -1;

	for (i = 0; i < list->clen; i++) {
		if (target == list->data[i])
			break;
	}
	if (i >= list->clen)
		return -1;

	while (i+1 < list->clen) {
		list->data[i] = list->data[i+1];
		i++;
	}

	list->clen--;

	return 0;
}

int list_modify_by_value(list_t *list, int old, int new)
{
	int i;
	
	for (i = 0; i < list->clen; i++) {
		if (old == list->data[i])
			break;
	}
	if (i >= list->clen)
		return -1;

	list->data[i] = new;

	return 0;
}

int list_modify_by_local(list_t *list, int local, int value)
{
	if (local < 0 || local >= list->clen)
		return -1;

	list->data[local] = value;

	return 0;
}

int *list_search(list_t *list, int target)
{
	int i;

	for (i = 0; i < list->clen; i++) {
		if (target == list->data[i])
			return &list->data[i];	//return list->data + i;
	}

	return NULL;
}

int list_reverse(list_t *list)
{
	int *h = list->data;
	int *t = list->data + list->clen - 1;
	int tmp;
	
	while (h < t) {
		tmp = *h;
		*h = *t;
		*t = tmp;
		h++;
		t--;
	}

	return 0;
}

int list_sort(list_t *list)
{
	int i,j;
	int tmp;
	int N = list->clen;
	int *data = list->data;

	for (i = 0; i < N -1; i++) {
		for (j = 0; j < N -1 - i; j++) {
			if (data[j] > data[j+1]) {
				tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	}

	return 0;
}
