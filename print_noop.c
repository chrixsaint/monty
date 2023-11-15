#include "monty.h"

/**
 * topPrinter - Prints the value at the top of the stack,
 * followed by a new line.
 *
 * @top: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 * This function prints the value at the top of the stack.
 * If the stack is empty, it prints an error message
 * and exits with EXIT_FAILURE.
 */

void topPrinter(tmp_stack **top, unsigned int line_number)
{

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(col.file);
		free(col.line);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*top)->n);
	}

}


/**
 * redundant - Does nothing.
 *
 * @top: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 * This opcode does nothing.
 * Return: Void.
 */

void redundant(tmp_stack **top, unsigned int line_number)
{
	/*(void) cast expression*/
	(void)top;
	(void)line_number;

}
