#include "monty.h"

/**
 *  remove_top - Removes the top element from the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function removes the top element from the stack.
 * If the stack is empty, it prints an error message and exits.
 */
void  remove_top(MontyNode_t **head, unsigned int counter)
{
	MontyNode_t *hc;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE);
	}
	hc = *head;
	*head = hc->next;
	free(hc);
}

/**
 *  opcodePush - Adds a node with a given integer value to the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation.
 * This function checks if a valid integer is provided
 * as an argument (bus.arg), and if so, it adds a new node
 * with the integer value to the stack. If the argument is not a
 * valid integer, it prints an error message and exits.
 */

void  opcodePush(MontyNode_t **head, unsigned int counter)
{
	int n, k, mark;

	k = 0, mark = 0;
	if (bus.arg)
	{
		if (bus.arg[0] == '-')
		{
			k++;
		}
		for (; bus.arg[k] != '\0'; k++)
		{
			if (bus.arg[k] > 57 || bus.arg[k] < 48)
				mark = 1; }
		if (mark == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			 clearStack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		 clearStack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		insertNode(head, n);
	else
	{
		addqueue(head, n);
	}
}
