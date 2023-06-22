#include "monty.h"
/**
 * stack_len - function that Returns:the length of a stack
 * @stack: a double linked list
 * Return:the length of a stack
 */
int stack_len(stack_t **stack)
{
	stack_t *p = NULL;
	int len = 0;

	p = *stack;
	while (p != NULL)
	{
		len++;
		p = p->prev;
	}
	return (len);
}
