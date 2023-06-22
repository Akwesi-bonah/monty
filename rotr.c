#include "monty.h"
/**
 * rotr -rotates the stack to the top.
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *p = NULL, *new = NULL, *aux = NULL;
	int i = 0;
	(void)line_number;

	if (*stack == NULL)
		return;
	if ((*stack)->prev == NULL)
		return;
	p = *stack;
	while (p->prev != NULL)
		p = p->prev;
	i = p->n;
	aux = p->next;
	free(p);
	aux->prev = NULL;
	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
		error_malloc(stack, NULL, NULL, NULL);
	new->n = i;
	new->next = NULL;
	new->prev = *stack;
	p = *stack;
	p->next = new;
	*stack = new;
}
