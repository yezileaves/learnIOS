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

int main()
{
	stack_t *stack;
	int value;
	
	stack = stack_init(10);
	
	value = 1;
	puts("Push:");
	while (0 ==	stack_push(stack, value))
		printf("%5d", value++);
	putchar('\n');
#if STACK_DEBUG
	_stack_debug_(stack);
#endif
	puts("Pop:");
	while (0 == stack_pop(stack, &value))
		printf("%5d", value);
	putchar('\n');
#if STACK_DEBUG
	_stack_debug_(stack);
#endif
	stack_destroy(stack);


	return 0;
}

stack_t *stack_init(int len)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	stack->data = malloc(sizeof(int) * len);
	stack->top = 0;
	stack->mlen = len;

	return stack;
}

int stack_destroy(stack_t *stack)
{
	free(stack->data);
	free(stack);

	return 0;
}

int stack_push(stack_t *stack, int value)
{
	if (stack->top >= stack->mlen)
		return -1;

	stack->data[stack->top] = value;
	stack->top++;

	return 0;
}

int stack_pop(stack_t *stack, int *value)
{
	if (stack->top <= 0)
		return -1;

	(stack->top)--;
	*value = stack->data[stack->top];

	return 0;
}

#if STACK_DEBUG
void _stack_debug_(stack_t *stack)
{
	int i;

	printf("Top: %d\tMlen: %d\n", stack->top, stack->mlen);
	for (i = 0; i < stack->top; i++)
		printf("%5d", stack->data[i]);
	putchar('\n');
}
#endif	/* STACK_DEBUG */
