#include "monty.h"

/**
 *   topPrinter - Prints the value at the top of the stack,
 * followed by a new line.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function prints the integer value at the top of the stack.
 * If the stack is empty, it prints an error message and exits.
 */
void   topPrinter(MontyNode_t **head, unsigned int counter)
{
	if (!*head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


/**
 *   redundant - Does nothing.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function does nothing and is used as a placeholder.
 * It takes the stack head and line number as parameters but
 * does not perform any operation.
 */
void   redundant(MontyNode_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
