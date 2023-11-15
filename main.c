#include "monty.h"
col_t col = {NULL, NULL, NULL};
/**
* main - Entry point of the Monty interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
* Return: 0 on success, or EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
	ssize_t readNum;
	unsigned int numbaLine = 0;
	tmp_stack *stack = NULL;
	FILE *file;
	size_t lentt = 0;
	char *line = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	col.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((readNum = getline(&line, &lentt, file)) != -1)
	{
		numbaLine++;
		if (funcnCaller(line, numbaLine, &stack) == 0)
			continue;
	}
	clearStack(&stack);
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
	return (0);
}
