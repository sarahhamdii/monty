#include "monty.h"

/**
 *
 *
 *
 */
void push(stack_t **top, unsigned int n)
{
	int i = 0;
	stack_t *head, *temp;

	if(!bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", n);
		fclose(bus.file);
		free(bus.buff);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	if (bus.arg[0] == '-')
		i++;
	while (bus.arg[i] != '\0')
	{
		if (bus.arg[i] < 48 || bus.arg[i]< 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", n);
			fclose(bus.file);
			free(bus.buff), free_stack(*top);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	head->next = NULL;
	head->n = atoi(bus.arg);
	if(!(*top))
		*top = head, (*top)->next = NULL, (*top)->prev = NULL;
	else
	{
		temp = (*top);
		head->prev = temp;
		temp->next = head;
		(*top) = head;
	}
}
