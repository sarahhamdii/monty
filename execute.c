#include "monty.h"

/**
 * execute - execute opcode
 * @buff: pinter
 * @stack: head linked list
 * @n: unsigned int
 * @file: pointer
 *
 * Return: 1
 */
int execute(char *buff, stack_t **stack, unsigned int n, FILE *file)
{
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL},
	};
	unsigned int i = 0;
	char *line;

	line = strtok(buff, " \n\t");
	if (line && line[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	if (bus.arg && bus.arg[strlen(bus.arg) - 1] == '$')
		bus.arg[strlen(bus.arg) - 1] = '\0';
	while (op[i].opcode && line)
	{
		if (strcmp(line, op[i].opcode) == 0)
		{
			op[i].f(stack, n);
			return (0);
		}
		i++;
	}
	if (line && op[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", n, line);
		fclose(file);
		free(buff);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
