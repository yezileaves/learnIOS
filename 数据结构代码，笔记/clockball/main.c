#include "queue.h"
#include "stack.h"
#include <stdio.h>

#define QUEUE_LEN	27
#define STK_LEN_M1	4
#define STK_LEN_M5	11
#define STK_LEN_H1	11

int check_queue(queue_t *que);

int main()
{
	queue_t *que;
	stack_t *m1;
	stack_t *m5;
	stack_t *h1;
	int ball;
	int tmp;
	int n;

	que = queue_init(QUEUE_LEN);
	m1 = stack_init(STK_LEN_M1);
	m5 = stack_init(STK_LEN_M5);
	h1 = stack_init(STK_LEN_H1);

	ball = 1;
	while (0 == queue_enque(que, ball))
		ball++;

	/* your code */
	n = 0;
	while (1) {
		queue_deque(que, &ball);

		if (0 == stack_push(m1, ball))
			continue;
		while (0 == stack_pop(m1, &tmp))
			queue_enque(que, tmp);

		if (0 == stack_push(m5, ball))
			continue;
		while (0 == stack_pop(m5, &tmp))
			queue_enque(que, tmp);

		if (0 == stack_push(h1, ball))
			continue;
		while (0 == stack_pop(h1, &tmp))
			queue_enque(que, tmp);

		queue_enque(que, ball);
		n++;

		if (0 == check_queue(que))
			break;
	}
	
	printf("%dD-%dH\n", n / 2, (n % 2) * 12);
	
	queue_destroy(que);
	stack_destroy(m1);
	stack_destroy(m5);
	stack_destroy(h1);

	return 0;
}

int check_queue(queue_t *que)
{
	qnode_t *p = que->head->next;

	while (p->next != NULL) {
		if (p->next->data < p->data)
			return -1;
		p = p->next;
	}

	return 0;
}
