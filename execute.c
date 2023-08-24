#include "monty.h"

/**
 * execute - execute opcode
 * @buff: pinter
 * @stack: head linked list
 * @n: unsigned int
 * @file: pointer
 *
 * Return.: void
 */
int execute(char *buff, stack_t **stack, unsigned int n, FILE *file)
{
	instruction_t op[] = {
		{"push", push},
		/**{"pall", pall},*/
		      /**{NULL, NULL},*/
	};
			/**{"pint", pint}, {"pop", pop}, {"swap", swap},
			{"add", add}, {"nop", nop}};*/
	unsigned int i;
	char *line;

	line = strtok(buff, " \n\t");
	if (line && line[0] == '#')
		return 0;
	bus.arg = strtok(NULL, " \n\t");
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if(strcmp(line, op[i].opcode) == 0)
		{
			op[i].f(stack, n);
			return 0;
		}
	}
	if (line && op[i].opcode == NULL)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", n, line);
	fclose(file);
	free(buff);
	free_stack(*stack);
}
	return(1);
}
