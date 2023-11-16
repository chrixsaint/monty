#include "monty.h"
struct_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for the Monty interpreter.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success, or EXIT_FAILURE on failure.
 */

int main(int argc, char *argv[])
{
	ssize_t read_line = 1;
	MontyNode_t *stack = NULL;
	char *content;
	FILE *file;
	size_t lentt = 0;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &lentt, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			funcnCaller(content, &stack, counter, file);
		}
		free(content);
	}
	 clearStack(stack);
	fclose(file);
return (0);
}
