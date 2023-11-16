#include "monty.h"

/**
 * insertNode - Adds a new node to the head of the stack.
 *
 * @head: A pointer to the head of the stack.
 * @n: The value to be added to the new node.
 * This function creates a new node with the given value and
 * adds it to the head of the stack. If the stack is not empty,
 * it adjusts the pointers accordingly.
 */
void insertNode(MontyNode_t **head, int n)
{

	MontyNode_t *fresh_node, *xin;

	xin = *head;
	fresh_node = malloc(sizeof(MontyNode_t));
	if (!fresh_node)
	{ printf("Error\n");
		exit(0); }
	if (xin)
		xin->prev = fresh_node;
	fresh_node->n = n;
	fresh_node->next = *head;
	fresh_node->prev = NULL;
	*head = fresh_node;
}


/**
 *   prntAll - Prints the values of the stack.
 *
 * @head: A pointer to the head of the stack.
 * @counter: Unused parameter.
 * This function prints all the values in the stack,
 * starting from the head. It ignores the 'counter'
 * parameter, which is there to match the function
 * signature required for opcode functions.
 */
void   prntAll(MontyNode_t **head, unsigned int counter)
{
	MontyNode_t *hc;
	(void)counter;

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
