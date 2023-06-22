#include "monty.h"
/**
 * push - function that push an unteger to the stack
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *p;
	int i = 0, number;

	if (global[1][0] == 0)
		global[1][0] = 'a';
	if (global[1][0] == '-')
		i++;
	for (; global[1][i] != '\0'; i++)
	{
		if (isdigit(global[1][i]) == 0)
		{
			free_stack(stack);
			free(global[0]);
			free(global[1]);
			free(global[2]);
			free(global);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	number = atoi(global[1]);
	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
		error_malloc(stack, NULL, NULL, NULL);
	new->n = number;
	new->next = NULL;
	if (*stack == NULL)
		new->prev = NULL;
	else
	{
		new->prev = *stack;
		p = *stack;
		p->next = new;
	}
	*stack = new;
}
