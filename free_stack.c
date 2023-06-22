#include "monty.h"
/**
 * free_stack - frees a double linked list.
 * @head: a double linked list
 **/
void free_stack(stack_t **head)
{
	stack_t *cpy = NULL;
	stack_t *aux = NULL;

	if (*head == NULL)
		return;
	cpy = *head;
	while (cpy)
	{
		aux = cpy->prev;
		free(cpy);
		cpy = aux;
	}
}
