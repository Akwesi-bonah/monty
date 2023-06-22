#include "monty.h"
/**
 * pstr_t - function that prints the string on the stack
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 */
void pstr_t(stack_t **stack, unsigned int line_number)
{
	stack_t *p;
	(void)line_number;

	p = *stack;
	if (p == NULL)
	{
		putchar('\n');
		return;
	}
	while (p != NULL)
	{
		if (p->n < 1 || p->n > 127)
			break;
		printf("%c", (char)(p->n));
		p = p->prev;
	}
	putchar('\n');
}
