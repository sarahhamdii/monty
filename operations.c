#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @top: pointer
 * @n: number
 */
void pop(stack_t **top, unsigned int n)
{
	stack_t *head;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
	head = *top;
	*top = head->next;
	free(head);
}

/**
 * nop - doesn’t do anything
 * @top: pointer
 * @n: number
 */
void nop(stack_t **top, unsigned int n)
{
	(void) top;
	(void) n;
}

/**
 * swap - swaps the top two elements of the stack
 * @top: pointer
 * @n: number
 */
void swap(stack_t **top, unsigned int n)
{
	int temp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		fclose(bus.file);
		free(bus.buff);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = temp;
}
