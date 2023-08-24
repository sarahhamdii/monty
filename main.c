#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - main code
 * @argc: number
 * @argv: array 
 *
 * Return: zero
 */
int main(int argc, char **argv)
{
	char buff[1024];
	char *line;
	FILE *file;
	/**ssize_t line_number = 1;*/
	stack_t *stack = NULL;
	unsigned int n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");		
	bus.file = file;
	if(!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		line = fgets(buff, sizeof(buff), file);
		bus.buff = buff;
		n++;
		if (line != NULL)
		{
			execute(line, &stack, n, file);
		}
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
