#include "monty.h"

/**
 * subtrakt - Subtracts the top element of the stack from
 * the second top element.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function subtracts the top element of the stack
 * from the second top element. It modifies the stack accordingly,
 * and the result is stored at the second top element
 */

void subtrakt(MontyNode_t **head, unsigned int counter)
{
	int zux, list;
	MontyNode_t *xin;

	xin = *head;
	for (list = 0; xin != NULL; list++)
	{
		xin = xin->next;
	}
	if (list < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	xin = *head;
	zux = xin->next->n - xin->n;
	xin->next->n = zux;
	*head = xin->next;
	free(xin);
}


/**
 *    divider - Divides the second top element of the stack by the top element.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function divides the second top element of the stack
 * by the top element. It modifies the stack accordingly,
 * and the result is stored at the second top element.
 * Handles division by zero and stack length checks
 */
void    divider(MontyNode_t **head, unsigned int counter)
{
	MontyNode_t *hc;
	int lentt = 0, xin;

	hc = *head;
	while (hc)
	{
		hc = hc->next;
		lentt++;
	}
	if (lentt < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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
	xin = hc->next->n / hc->n;
	hc->next->n = xin;
	*head = hc->next;
	free(hc);
}
