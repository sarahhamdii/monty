#include "monty.h"

/**
 *
 *
 *
 */

void pall(stack_t **top, unsigned int n)
{
	stack_t *head2;
	(void)n;

	head2 = *top;
	if (head2 == NULL)
		return;
	while (head2)
	{
		printf("%d\n", head2->n);
		head2 = head2->next;
	}
}
