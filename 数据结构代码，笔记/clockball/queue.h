#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_DEBUG	1

struct _que_node_ {
	int data;
	struct _que_node_ *next;
};
typedef struct _que_node_ qnode_t;

struct _linkqueue_ {
	qnode_t *head;
	qnode_t *tail;
	int clen;
	int mlen;
};
typedef struct _linkqueue_ queue_t;

qnode_t *queue_create_node(int value);
queue_t *queue_init(int len);
int queue_destroy(queue_t *que);
int queue_enque(queue_t *que, int value);
int queue_deque(queue_t *que, int *value);
#if QUEUE_DEBUG
void _queue_debug_(queue_t *que);
#endif	/* QUEUE_DEBUG */

#endif /* __QUEUE_H__ */
