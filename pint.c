#include "monty.h"
/**
 * pint - function that prints first element of the stack
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		free_stack(stack);
		free(global[0]);
		free(global[1]);
		free(global[2]);
		free(global);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
