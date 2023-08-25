#include "monty.h"

/**
 * free_stack - free
 * @head: pointer
 */

void free_stack(stack_t *head)
{
	stack_t *new;

	while (head != NULL)
	{
		new = head;
		head = head->next;
		free(new);
	}
}
