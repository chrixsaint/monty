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
	MontyNode_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
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
	MontyNode_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
