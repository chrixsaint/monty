#include "monty.h"

/**
 * switch_stack - Sets the stack mode.
 *
 * @head: Pointer to the head of the stack (unused).
 * @counter: Line number of the current operation (unused).
 * This function sets the stack mode, indicating that
 * the Monty interpreter should operate in stack mode.
 * The parameters `head` and `counter` are marked as unused
 * since they are not utilized in the function.
 */
void switch_stack(MontyNode_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}


/**
 * enqueue - Sets the queue mode.
 *
 * @head: Pointer to the head of the stack (unused).
 * @counter: Line number of the current operation (unused).
 * This function sets the queue mode, indicating that
 * the Monty interpreter should operate in queue mode.
 * The parameters `head` and `counter` are marked
 * as unused since they are not utilized in the function.
 */

void enqueue(MontyNode_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - Adds a node to the tail of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @n: New value to be added to the stack.
 * This function adds a new node with the given value
 * to the tail of the stack. If the stack is empty,
 * the new node becomes the head of the stack.
 */

void addqueue(MontyNode_t **head, int n)
{
	MontyNode_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(MontyNode_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
