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
	int xin, size = 0;
	MontyNode_t *hc;

	hc = *head;
	while (hc)
	{
		hc = hc->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	hc = *head;
	xin = hc->next->n * hc->n;
	hc->next->n = xin;
	*head = hc->next;
	free(hc);
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
	int size, xin;
	MontyNode_t *hc;

	size = 0;
	hc = *head;
	while (hc)
	{
		hc = hc->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	hc = *head;
	if (hc->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	xin = hc->next->n % hc->n;
	hc->next->n = xin;
	*head = hc->next;
	free(hc);
}
