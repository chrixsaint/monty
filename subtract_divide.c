#include "monty.h"

/**
 * divider - Divide the second top element of the
 * stack by the top element.
 *
 * @top: Double pointer to the top of the stack.
 * @line_number: Line number of the current operation.
 * This function divides the second top element of the
 * stack by the top element. The result is then stored
 * in the second node, and the first node is removed.
 * If the stack is too short or if division
 * by zero is attempted, it prints an
 * appropriate error message and exits with EXIT_FAILURE.
 */
void divider(tmp_stack **top, unsigned int line_number)
{
	int riset;
	tmp_stack *tmporal;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(col.line);
		fclose(col.file);
		clearStack(top);
		exit(EXIT_FAILURE);

	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(col.line);
		fclose(col.file);
		clearStack(top);
		exit(EXIT_FAILURE);

	}
	tmporal = *top;
	riset = (*top)->next->n / (*top)->n;
	*top = (*top)->next;
	(*top)->n = riset;
	if (*top != NULL)
	{
		(*top)->prev = NULL;
	}
	free(tmporal);
}


/**
 * subtrakt - Subtract the top element of the stack from the
 * second top element.
 *
 * @top: Double pointer to the top of the stack.
 * @line_number: Line number of the current operation.
 * This function subtracts the second top element of the
 * stack from the top element. The result is then stored
 * in the second node, and the first node is removed.
 * If the stack is too short, it prints an
 * error message and exits with EXIT_FAILURE.
 */

void subtrakt(tmp_stack **top, unsigned int line_number)
{
	int riset;
	tmp_stack *tmporal;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(col.file);
		free(col.line);
		exit(EXIT_FAILURE);
	}
	riset = (*top)->n - (*top)->next->n; /*subtract*/
	tmporal = *top;
	*top = (*top)->next; /*new top is sec node*/
	(*top)->prev = NULL;
	(*top)->n = -(riset);
	free(tmporal);

}
