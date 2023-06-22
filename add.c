#include "monty.h"
/**
 * add - function that add the first 2 elements on a stack
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *f, *s;
	int l = 0;

	l = stack_len(stack);
	if (l < 2)
	{
		free_stack(stack);
		free(global[0]);
		free(global[1]);
		free(global[2]);
		free(global);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	f = *stack;
	s = f->prev;
	s->n += f->n;
	*stack = s;
	free(f);
}
