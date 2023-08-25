#include "monty.h"

/**
 *
 *
 *
 */

void pint(stack_t **top, unsigned int n)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		fclose(bus.file);
		free(bus.buff);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
