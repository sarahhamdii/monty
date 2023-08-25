#include "monty.h"

/**
 * pall - pall
 * @top: pointer
 * @n: number
 */

void pall(stack_t **top, unsigned int n)
{
	stack_t *head2;
	(void)n;

	head2 = *top;
	while (head2 != NULL)
	{
		fprintf(stdout, "%d\n", head2->n);
		head2 = head2->next;
	}

}
