#include "monty.h"

/**
 * subtrakt - Subtracts the top element of the stack from
 * the second top element.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function subtracts the top element of the stack
 * from the second top element. It modifies the stack accordingly,
 * and the result is stored at the second top element.
 */

void subtrakt(MontyNode_t **head, unsigned int counter)
{
	MontyNode_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}


/**
 *    divider - Divides the second top element of the stack by the top element.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function divides the second top element of the stack
 * by the top element. It modifies the stack accordingly,
 * and the result is stored at the second top element.
 * Handles division by zero and stack length checks.
 */
void    divider(MontyNode_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
