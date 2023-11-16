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
				{"rotr", f_rotr},
				{"queue", enqueue},
				{"stack", switch_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
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
	MontyNode_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
