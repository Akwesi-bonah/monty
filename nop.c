#include "monty.h"
/**
 * nop - The opcode nop doesn’t do anything.
 * @stack: a double linked list
 * @line_number: number of line in code to print error message.
 **/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
