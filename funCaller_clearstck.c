#include "monty.h"

/**
 * funcnCaller - Executes the opcode.
 *
 * @content: Line content containing the opcode.
 * @stack: Head of the stack.
 * @counter: Line counter.
 * @file: Pointer to the Monty file.
 *
 * Return: 0 if the opcode is a comment or
 * if the line is empty, 1 otherwise.
 */
int funcnCaller(char *content, MontyNode_t **stack,
unsigned int counter, FILE *file)
{
	comand_t opst[] = {
				{"push",  opcodePush}, {"pall",   prntAll}, {"pint",   topPrinter},
				{"pop",  remove_top},
				{"swap", exchange},
				{"add", sum},
				{"nop",   redundant},
				{"sub", subtrakt},
				{"div",    divider},
				{"mul",  multply},
				{"mod",  computeMod},
				{"pchar", prnt_char},
				{"pstr", prnt_strng},
				{"rotl", left_rotatn},
				{"rotr", right_rotatn},
				{"queue", enqueue},
				{"stack", switch_stack},
				{NULL, NULL}
				};
	char *vc;
	unsigned int aii = 0;

	vc = strtok(content, " \n\t");
	if (vc && vc[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[aii].opcode && vc)
	{
		if (strcmp(vc, opst[aii].opcode) == 0)
		{	opst[aii].f(stack, counter);
			return (0);
		}
		aii++;
	}
	if (vc && opst[aii].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, vc);
		fclose(file);
		free(content);
		 clearStack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
 *  clearStack - Frees a doubly linked list.
 *
 * @head: Head of the stack.
 */
void  clearStack(MontyNode_t *head)
{
	MontyNode_t *xin;

	xin = head;
	while (head)
	{
		xin = head->next;
		free(head);
		head = xin;
	}
}
