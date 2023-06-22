#include "monty.h"
/**
 * sel_opcode - Select the opcode to use.
 * @stack: type pointer node of data struct
 * @line: line of instructions
 * Return: Retunr the funtion
 */
int sel_opcode(stack_t **stack, unsigned int line)
{
	unsigned int l =  line;
	instruction_t op[] = {
		{ "push", push }, { "pall", pall}, { "pop", pop },
		{ "add", add }, { "nop", nop }, { "sub", sub },
		{ "pint", pint }, { "swap", swap },
		{ "mul", mul }, { "div", div_m }, { "pchar", _pchar},
		{ "mod", mod_m }, { "\n", nop }, { " ", nop },
		{ "/t", nop }, { "pstr", pstr_t},  { "rotl", rotl},
		{ "rotr", rotr}, { NULL, NULL },
	};
	int i = 0;

	if (stack == NULL || global[1] == NULL)
		return (0);
	for (; op[i].opcode != NULL; i++)
	{
		if (strcmp(global[0], op[i].opcode) == 0)
		{
			op[i].f(stack, line);
			break;
		}
	}
	if (op[i].opcode == NULL && global[0][0] != 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", l, global[0]);
		free_stack(stack);
		free(global[0]);
		free(global[1]);
		free(global[2]);
		free(global);
		exit(EXIT_FAILURE);
	}
	return (0);
}
