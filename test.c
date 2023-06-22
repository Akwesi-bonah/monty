#include "monty.h"

char **global = NULL;

/**
 * main - process Monty languaje
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd = 0;
	unsigned int line = 0;
	char *fname = NULL;
	stack_t *st = NULL;
	stack_t **stack = &st;

	if (argc !=  2)
	{
		free_stack(stack);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fname = argv[1];
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line++;
		global = _getopc(fd, stack);
		sel_opcode(stack, line);
		free(global[0]), free(global[1]);
		if (global[2][0] != '0')
		{
			free(global[2]);
			break;
		}
		free(global[2]);
		free(global);
	}
	free(global);
	free_stack(stack);
	close(fd);
	return (0);
}
