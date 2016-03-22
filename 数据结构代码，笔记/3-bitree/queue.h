#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "bitnode.h"

#define QUEUE_DEBUG	0

typedef btnode_t* qdata_t;
struct _que_node_ {
	qdata_t data;
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

extern qnode_t *queue_create_node(qdata_t value);
extern queue_t *queue_init(int len);
extern int queue_destroy(queue_t *que);
extern int queue_enque(queue_t *que, qdata_t value);
extern int queue_deque(queue_t *que, qdata_t *value);
extern int queue_getlen(queue_t *que);
extern int queue_isfull(queue_t *que);
extern int queue_isempty(queue_t *que);

#if QUEUE_DEBUG
extern void _queue_debug_(queue_t *que);
#endif

#endif 	/* __QUEUE_H__ */
