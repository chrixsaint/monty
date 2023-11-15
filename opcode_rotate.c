#include "monty.h"

/**
 * opcodePush - Adds a new element to the top of the stack.
 *
 * @top: A pointer to the top of the stack.
 * @line_number: The line number of the instruction being executed.
 * This function adds a new element to the top of the stack.
 * The value to be pushed is extracted from the global variable
 * `col.arg`, which is expected to contain a valid integer.
 * If `col.arg` is NULL, empty, or not a valid integer, it prints
 * an error message and exits with EXIT_FAILURE.
 */

void opcodePush(tmp_stack **top, unsigned int line_number)
{
	int value;
	char *endptr;

	if (col.arg == NULL || *col.arg == '\0' || isspace(*col.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		clearStack(top);
		free(col.line);
		fclose(col.file);
		exit(EXIT_FAILURE);
	}
	value = strtol(col.arg, &endptr, 10);

	if (*endptr != '\0' || endptr == col.arg ||
	 value > INT_MAX || value < INT_MIN)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		clearStack(top);
		free(col.line);
		if (col.file != NULL)
			fclose(col.file);
		exit(EXIT_FAILURE);
	}
		stakPusher(top, value);
}


/**
 * prntAll - Prints all the values on the stack, from top to bottom.
 *
 * @head: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 * This function prints all the values on the stack,
 * starting from the top and moving towards the bottom.
 * If the stack is empty, the function returns without
 * printing anything.
 */
void prntAll(tmp_stack **head, unsigned int line_number)
{
	tmp_stack *hc;
	(void)line_number;
	
	hc = NULL;
	hc = *head;
	if (!hc)
	{
		return;
	}
	while (hc)
	{
		printf("%d\n", hc->n);
		hc = hc->next;
	}
}
