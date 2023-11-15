#include "monty.h"

/**
 * funcnCaller - Executes an opcode on a stack.
 *
 * @line: The line containing the opcode to execute.
 * @line_number: The line number of the opcode in the input file.
 * @stack: A pointer to the top of the stack.
 * Return: 0 if the opcode is a comment or if the line is empty, 1 otherwise.
 */
int funcnCaller(char *line, unsigned int line_number, tmp_stack **stack)
{
	instruction_t opcodes[] = {
		{"opcodePush", opcodePush},
		{"prntAll", prntAll},
		{"topPrinter", topPrinter},
		{"remove_top", remove_top},
		{"exchange", exchange},
		{"sum", sum},
		{"redundant", redundant},
		{"subtrakt", subtrakt},
		{"multply", multply},
		{"div", divider},
		{"mod", computeMod},
		{NULL, NULL}
	};
	int find = 0;
	int aii = 0;
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (!opcode || *opcode == '#' || opcode[0] == '#')
	{
		return (0);
	}
	col.arg = strtok(NULL, " \t\n");
	while (opcodes[aii].opcode != NULL && opcode != NULL)
	{
		if (strcmp(opcode, opcodes[aii].opcode) == 0)
		{
			opcodes[aii].f(stack, line_number);
			find = 1;
			break;
		}
		aii++;
	}
	if (find == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
* clearStack - Frees all the nodes of a stack.
* @stack: Pointer to the top of the stack.
*
* This function frees all the nodes of a stack,
* starting from the top of the stack.
*/

void clearStack(tmp_stack **stack)
{
	tmp_stack *tmporal = NULL;
	tmp_stack *current = *stack;
	/* Initialize tmporal to NULL */

	while (!current)
	{
		tmporal = current;
		current = current->next;
		free(tmporal);
	}
	*stack = NULL;
	/*Set the top of the stack to NULL */
}
