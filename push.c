#include "monty.h"

/**
 *
 *
 *
 *
void push(stack_t **top, unsigned int n)
{
	int i = 0, sign = 0;
	int parsed_value = atoi(bus.arg);
	stack_t *head, *temp;

**	if(bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] < '0' || bus.arg[i] > '9')
				sign = 1;
		}
		if (sign == 1 || bus.arg[i-1] == '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", n);
			fclose(bus.file);
			free(bus.buff);
			free_stack(*top);
			exit(EXIT_FAILURE);
			}
	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	head->next = NULL;
	head->n = parsed_value;
	if(!(*top))
		*top = head, (*top)->next = NULL, (*top)->prev = NULL;
	else
	{
		temp = (*top);
		head->prev = temp;
		temp->next = head;
		(*top) = head;
	}
}*/

void push(stack_t **top, unsigned int n)
{
stack_t * new_node;
int parsed_value;

    if (bus.arg == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", n);
        fclose(bus.file);
        free(bus.buff);
        free_stack(*top);
        exit(EXIT_FAILURE);
    }

     parsed_value = atoi(bus.arg);
    if (parsed_value == 0 && bus.arg[0] != '0')
    {
        fprintf(stderr, "L%d: usage: push integer\n", n);
        fclose(bus.file);
        free(bus.buff);
        free_stack(*top);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = parsed_value;
    new_node->prev = NULL;
    new_node->next = *top;

    if (*top != NULL)
    {
        (*top)->prev = new_node;
    }

    *top = new_node;
}
