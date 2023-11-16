#include "monty.h"

/**
 *  multply - Multiplies the top two elements of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function multiplies the second top element
 * of the stack with the top element. If the stack
 * has less than two elements, it prints an error message and exits.
 */

void  multply(MontyNode_t **head, unsigned int counter)
{
	MontyNode_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}


/**
 *  computeMod - Computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function calculates the remainder when dividing the
 * second top element by the top element.
 * If the stack has less than two elements or division
 * by zero occurs, it prints an error message and exits.
 */
void  computeMod(MontyNode_t **head, unsigned int counter)
{
	MontyNode_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
