#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

#define STACK_DEBUG	0

struct _seqstack_ {
	int *data;
	int top;
	int mlen;
};
typedef struct _seqstack_ stack_t;

stack_t *stack_init(int len);
int stack_destroy(stack_t *stack);
int stack_push(stack_t *stack, int value);
int stack_pop(stack_t *stack, int *value);
#if STACK_DEBUG
void _stack_debug_(stack_t *stack);
#endif	/* STACK_DEBUG */

#endif 	/* __STACK_H__ */
