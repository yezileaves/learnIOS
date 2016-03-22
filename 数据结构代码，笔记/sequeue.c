#include <stdio.h>
#include <stdlib.h>

#define QUEUE_DEBUG	1

struct _sequeue_ {
	int *data;
	int head;
	int tail;
	int mlen;
};
typedef struct _sequeue_ queue_t;

queue_t *queue_init(int len);
int queue_destroy(queue_t *que);
int queue_enque(queue_t *que, int value);
int queue_deque(queue_t *que, int *value);
#if QUEUE_DEBUG
void _queue_debug_(queue_t *que);
#endif

int main()
{
	queue_t *que;
	int value;
	int i;
	
	que = queue_init(10);
	
	puts("EnQueue:");
	value = 10;
	while (0 == queue_enque(que, value))
		printf("%5d", value++);
	putchar('\n');

	_queue_debug_(que);

	puts("DeQueue:");
	for (i = 0; i < 5; i++) {
		queue_deque(que, &value);
		printf("%5d", value);
	}
	putchar('\n');
	
	_queue_debug_(que);

	value = 100;
	while (0 == queue_enque(que, value))
		value++;
	
	_queue_debug_(que);



	queue_destroy(que);
}

queue_t *queue_init(int len)
{
	queue_t *que;

	que = malloc(sizeof(queue_t));
	que->data = malloc(sizeof(int) * len);
	que->head = 0;
	que->tail = 0;
	que->mlen = len;

	return que;
}

int queue_destroy(queue_t *que)
{
	free(que->data);
	free(que);

	return 0;
}

int queue_enque(queue_t *que, int value)
{
	if ((que->tail + 1) % que->mlen == que->head)
		return -1;
	
	que->data[que->tail] = value;
	que->tail = (que->tail + 1) % que->mlen;

	return 0;
}

int queue_deque(queue_t *que, int *value)
{
	if (que->head == que->tail)
		return -1;

	*value = que->data[que->head];
	que->head = (que->head + 1) % que->mlen;

	return 0;
}

#if QUEUE_DEBUG
void _queue_debug_(queue_t *que)
{
	int i;

	printf("------------  Head: %d\tTail: %d\tMlen: %d ------------\n", 
			que->head, que->tail, que->mlen);
	for (i = 0; i < que->mlen; i++)
		printf("%5d", que->data[i]);
	putchar('\n');
}
#endif
