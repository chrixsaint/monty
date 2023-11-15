#include "monty.h"

/**
 * sum - sum the top two elements of the stack.
 *
 * @top: Double pointer to the top of the stack.
 * @line_number: Line number of the current operation.
 * This function adds the top two elements of the stack.
 * The result is then stored in the second node, and the
 * first node is removed. If the stack is too short,
 * it prints an error message and exits with EXIT_FAILURE.
 */

void sum(tmp_stack **top, unsigned int line_number)
{
	int res;
	tmp_stack *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sum, stack too short\n", line_number);
		free(col.line);
		fclose(col.file);
		clearStack(top);
		exit(EXIT_FAILURE);
	}
	res = (*top)->n + (*top)->next->n;
	tmp = *top;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = res;
	free(tmp);


}

/**
 * exchange - Swaps the top two elements of the stack.
 *
 * @top: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 * This function swaps the positions of the top
 * two elements of the stack. If the stack contains
 * less than two elements, it prints an error message
 * and exits with EXIT_FAILURE.
 */

void exchange(tmp_stack **top, unsigned int line_number)
{
	tmp_stack *tmp = *top;
	int data;


	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(col.line);
		fclose(col.file);
		clearStack(top);
		exit(EXIT_FAILURE);
	}
	tmp = *top;
	data = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = data;

}
