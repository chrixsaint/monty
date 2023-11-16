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

	MontyNode_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(MontyNode_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
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
	MontyNode_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
