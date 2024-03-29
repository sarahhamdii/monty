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
	stack_t *stack = NULL;
	unsigned int n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = fgets(buff, 1024, file);
		if (line == NULL)
			break;
		bus.buff = malloc(strlen(buff) + 1);
		if (bus.buff == NULL)
		{
			fprintf(stderr, "Memory allocation error\n");
			fclose(file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		strcpy(bus.buff, buff);
		n++;
		execute(line, &stack, n, file);
		free(bus.buff);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
