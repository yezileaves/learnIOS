#include <stdio.h>
#include "seqlist.h"

int main()
{
	list_t *list;
	int value;

	list = list_init(10);

	for (value = 0; value < 10; value++)
		list_insert(list, value);

	list_show(list);
	
	list_destroy(list);

	return 0;
}
