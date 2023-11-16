#include "monty.h"

/**
 * exchange - Swaps the top two elements of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function swaps the top two elements of the stack.
 * It modifies the stack accordingly, and no values are returned.
 * Handles stack length checks.
 */
void exchange(MontyNode_t **head, unsigned int counter)
{
	int  xin, lentt;
	MontyNode_t *hc;

	lentt = 0;
	hc = *head;
	while (hc)
	{
		hc = hc->next;
		lentt++;
	}
	if (lentt < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	hc = *head;
	xin = hc->n;
	hc->n = hc->next->n;
	hc->next->n = xin;
}


/**
 * sum - Adds the top two elements of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 *
 * Description:
 * This function adds the top two elements of the stack.
 * It modifies the stack accordingly, and the result
 * is stored at the second top element. Handles stack length checks.
 */
void sum(MontyNode_t **head, unsigned int counter)
{
	int xin, lentt;
	MontyNode_t *hc;

	lentt = 0;
	hc = *head;
	while (hc)
	{
		hc = hc->next;
		lentt++;
	}
	if (lentt < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	hc = *head;
	xin = hc->n + hc->next->n;
	hc->next->n = xin;
	*head = hc->next;
	free(hc);
}
