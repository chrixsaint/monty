#include "monty.h"


/**
 * stakPusher - Pushes a new element onto the stack.
 *
 * @top: A pointer to the top of the stack.
 * @value: The value to be pushed onto the stack.
 * This function creates a new node with the given value and adds
 * it to the top of the stack. If the stack is not empty,
 * it adjusts the pointers accordingly.
 */
void stakPusher(tmp_stack **top, int value)
{
	tmp_stack *new_node;

	new_node = malloc(sizeof(tmp_stack));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL; /*added*/
	if (*top)
	{
		new_node->next = *top;
		(*top)->prev = new_node;
	}
	*top = new_node;
}

/**
 * remove_top - Removes the top element of the stack.
 *
 * @top: A pointer to the top of the stack.
 * @line_number: The line number of the instruction being executed.
 * This function removes the top element of the stack.
 * If the stack is empty, it prints an error message,
 * frees memory, and exits with EXIT_FAILURE.
 */
void remove_top(tmp_stack **top, unsigned int line_number)
{
	tmp_stack *tmporal;

	if (!*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(col.line);
		fclose(col.file);
		clearStack(top);
		exit(EXIT_FAILURE);
	}
	tmporal = *top;
	*top = tmporal->next;
	if (*top)
	{
		(*top)->prev = NULL;
	}
	free(tmporal);
}

