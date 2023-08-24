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
	char *line = NULL;
	FILE *file;
	stack_t stack = NULL;
	unsigned int number = 0;

	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if(!file)
	{
		fprint(stderr, "Error: Can't open file %s\n, argv[1]");
		exit(EXIT_FAILURE);
	}
	while (line number > 0)
	{
		line number = fgets(&buff, 1024, file);
		bus.buff = buff;
		bff++;
		if (line number > 0)
		{
			execute(buff, &stack, number, file);
		}
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
