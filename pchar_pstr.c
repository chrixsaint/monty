#include "monty.h"

/**
 * prnt_char - Prints the character at the top
 * of the stack, followed by a new line.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function prints the ASCII character at the top of the stack.
 * If the stack is empty or the value is out of the
 * ASCII range, it prints an error message and exits.
 */

void prnt_char(MontyNode_t **head, unsigned int counter)
{
	MontyNode_t *hc;

	hc = *head;
	if (hc == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	if (hc->n > 127 || hc->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", hc->n);
}


/**
 * prnt_strng - Prints the string starting at the
 * top of the stack, followed by a new line.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function prints the string starting from the
 * top of the stack until reaching a non-printable character
 * or the end of the stack. It then prints a new line.
 */

void prnt_strng(MontyNode_t **head, unsigned int counter)
{
	MontyNode_t *hc;
	(void)counter;

	hc = *head;
	while (hc)
	{
		if (hc->n > 127 || hc->n <= 0)
			break;
		printf("%c", hc->n);
		hc = hc->next;
	}
	printf("\n");
}
