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
	int i = 0;
	int found = 0;
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (!opcode || *opcode == '#' || opcode[0] == '#')
	{
		return (0);
	}
	col.arg = strtok(NULL, " \t\n");
	while (opcodes[i].opcode != NULL && opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			found = 1;
			break;
		}
		i++;
	}
	if (found == 0)
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
	tmp_stack *current = *stack;
	tmp_stack *tmp = NULL; /* Initialize tmp to NULL */

	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL; /*Set the top of the stack to NULL */
}
