#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @top: ponter
 * @n: number
 */
void add(stack_t **top, unsigned int n)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", n);
		fclose(bus.file);
		free(bus.buff);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n += (*top)->n;
	pop(top, n); 
}