#include "monty.h"
/**
 * pop - function that pops an unteger to the stack
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	p = *stack;
	if (stack == NULL || *stack == NULL)
	{
		free_stack(stack);
		free(global[0]);
		free(global[1]);
		free(global[2]);
		free(global);
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = p->prev;
	free(p);
}
