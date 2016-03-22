#include "queue.h"

queue_t *queue_init(int len)
{
	queue_t *que;

	que = malloc(sizeof(queue_t));
	que->head = queue_create_node(0);
	que->tail = que->head;
	que->clen = 0;
	que->mlen = len;

	return que;
}

int queue_destroy(queue_t *que)
{
	qnode_t *p = que->head;
	qnode_t *tmp;
	
	while (NULL != p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(que);

	return 0;
}

qnode_t *queue_create_node(qdata_t value)
{
	qnode_t *node;

	node = malloc(sizeof(qnode_t));
	node->data = value;
	node->next = NULL;

	return node;
}

int queue_enque(queue_t *que, qdata_t value)
{
	qnode_t *new;

	if (que->clen >= que->mlen)
		return -1;
	
	new = queue_create_node(value);
	que->tail->next = new;
	que->tail = new;

	que->clen++;

	return 0;
}

int queue_deque(queue_t *que, qdata_t *value)
{
	qnode_t *p = que->head;

	if (que->clen <= 0)
		return -1;

	que->head = p->next;
	free(p);

	*value = que->head->data;
	que->clen--;

	return 0;
}

int queue_getlen(queue_t *que)
{
	return que->clen;
}

int queue_isfull(queue_t *que)
{
	return que->clen >= que->mlen;
}

int queue_isempty(queue_t *que)
{
	return que->clen <= 0;
}

#if QUEUE_DEBUG
void _queue_debug_(queue_t *que)
{
	qnode_t *p = que->head->next;

	puts("----------- QUEUE_DEBUG -----------");
	printf("Clen: %d\tMlen:%d\tHead: %p\tTail: %p\n",
			que->clen, que->mlen, que->head, que->tail);
	while (NULL != p) {
		printf("%5d", p->data);
		p = p->next;
	}
	putchar('\n');
}
#endif
