#include "monty.h"
/**
 * rotl - rotates the stack to the top.
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *p = NULL, *new = NULL;
	int n = 0;
	(void)line_number;

	if (*stack == NULL)
		return;
	if ((*stack)->prev == NULL)
		return;
	p = *stack;
	n = p->n;
	*stack = p->prev;
	free(p);
	p = *stack;
	while (p->prev != NULL)
		p = p->prev;
	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
		error_malloc(stack, NULL, NULL, NULL);
	new->prev = NULL;
	new->next = p;
	new->n = n;
	p->prev = new;
}
