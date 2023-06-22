#include "monty.h"
/**
 * _getopc - function that push an unteger to the stack
 * @fd: file to process
 * @stack: a double linked list
 * Return: the opcode and the argument
 */
char **_getopc(int fd, stack_t **stack)
{
	int i = 0, size = 100, fl = 1, inw = 0, cont = 0, com = 1;
	char *opc = NULL, *arg = NULL, *end = NULL;
	char c = 0;

	opc = malloc(size);
	arg = malloc(size);
	end = malloc(1);
	global = (char **)malloc(sizeof(char **) * 3);
	if (opc == NULL || arg == NULL || end == NULL || global == NULL)
		error_malloc(stack, opc, arg, end);
	end[0] = '0';
	for (; i < size; opc[i] = 0, arg[i] = 0, i++)
		;
	for (global[0] = opc, global[1] = arg, global[2] = end, i = 0; fl; i++)
	{
		read(fd, &c, 1);
		if (c == '\n' || c == EOF || c == 0)
		{
			if (c == EOF || c == 0)
				end[0] = '1';
			return (global);
		}
		if (c == ' ' || c == '\t')
		{
			i = -1;
			if (inw)
				inw = 0, cont++;
		}
		else
			inw = 1;
		if (inw && cont == 0 && c == '#' && i == 0)
			com = 0;
		if (inw && cont == 0 && com)
			opc[i] = c;
		if (inw && cont == 1 && com)
			arg[i] = c;
	}
	return (global);
}
