#include <stdio.h>
#include <stdlib.h>

#define STACK_DEBUG 1

struct _stack_node_ {
	int data;
	struct _stack_node_ *next;
};
typedef struct _stack_node_ snode_t;

struct _link_stack_ {
	snode_t *top;
	int clen;
	int mlen;
};
typedef struct _link_stack_ stack_t;

stack_t *stack_init(int len);
snode_t *stack_create_node(int value);
int stack_destroy(stack_t *stack);
int stack_push(stack_t *stack, int value);
int stack_pop(stack_t *stack, int *value);

#if STACK_DEBUG
void _stack_debug_(stack_t *stack);
#endif

int main()
{
	stack_t *stack;
	int value;
	
	stack = stack_init(10);

	puts("Push:");
	value = 10;
	while (0 == stack_push(stack, value))
		printf("%5d", value++);
	putchar('\n');

	_stack_debug_(stack);
	
	puts("Pop:");
	while (0 == stack_pop(stack, &value))
		printf("%5d", value);
	putchar('\n');
	
	_stack_debug_(stack);

	stack_destroy(stack);

	return 0;
}

stack_t *stack_init(int len)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	stack->top = stack_create_node(0);
	stack->clen = 0;
	stack->mlen = len;

	return stack;
}

snode_t *stack_create_node(int value)
{
	snode_t *node;

	node = malloc(sizeof(snode_t));
	node->data = value;
	node->next = NULL;

	return node;
}

int stack_destroy(stack_t *stack)
{
	snode_t *p = stack->top;
	snode_t *tmp;

	while (NULL != p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(stack);

	return 0;
}

int stack_push(stack_t *stack, int value)
{
	snode_t *new;

	if (stack->clen >= stack->mlen)
		return -1;
	
	new = stack_create_node(value);
	new->next = stack->top->next;
	stack->top->next = new;

	stack->clen++;

	return 0;
}

int stack_pop(stack_t *stack, int *value)
{
	snode_t *p = stack->top->next;

	if (stack->clen <= 0)
		return -1;

	*value = p->data;
	stack->top->next = p->next;
	free(p);

	stack->clen--;

	return 0;
}

#if STACK_DEBUG	
void _stack_debug_(stack_t *stack)
{
	snode_t *p = stack->top->next;

	printf("Clen: %d\tMlen: %d\tTop->next: %p\n", 
			stack->clen, stack->mlen, stack->top->next);
	while (NULL != p) {
		printf("%5d", p->data);
		p = p->next;
	}
	putchar('\n');
}
#endif	/* STACK_DEBUG */

