#include "monty.h"
/**
 * pall - function that prints the stack
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p;
	(void)line_number;

	p = *stack;
	while (p != NULL)
	{
		printf("%i\n", p->n);
		p = p->prev;
	}
}
