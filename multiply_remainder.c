#include "monty.h"
/**
 * multply - Multiplies the second top element of
 * the stack with the top element.
 *
 * @top: Double pointer to the top of the stack.
 * @line_number: Line number being executed from the Monty file.
 * This function multiplies the second top element of
 * the stack with the top element and replaces the top
 * element with the result.
 * If the stack has fewer than two elements, or if either of
 * the top two elements is not an integer,
 * it prints an error message and exits with EXIT_FAILURE.
 */

void multply(tmp_stack **top, unsigned int line_number)
{
	int riset;
	tmp_stack *tmporal;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't multply, stack too short\n", line_number);
		fclose(col.file);
		free(col.line);
		exit(EXIT_FAILURE);
	}
		if (!intChecker((*top)->n) || !intChecker((*top)->next->n))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		fclose(col.file);
		free(col.line);
		exit(EXIT_FAILURE);
	}
	riset = (*top)->n * (*top)->next->n;
	tmporal = *top;
	*top = (*top)->next; /*new top is sec node*/
	(*top)->prev = NULL;
	(*top)->n = riset;
	free(tmporal);

}
/**
 * intChecker - Checks if a given number is an integer
 * @num: The number to check
 *
 * Return: 1 if the number is an integer, 0 otherwise
 */

int intChecker(int num)
{
	if (num == (int)num)
	{
		return (1);
	}
	else
		return (0);
}


/**
 * computeMod - Computes the remainder of the
 * second top element of the stack divided by the top element.
 *
 * @top: Double pointer to the top of the stack.
 * @line_number: Line number of the current operation.
 * This function computes the remainder of the second top
 * element of the stack divided by the top element and
 * replaces the top element with the result. If the stack
 * has fewer than two elements, or if the top element is zero,
 * it prints an error message and exits with EXIT_FAILURE.
 */

void computeMod(tmp_stack **top, unsigned int line_number)
{
	int riset;
	tmp_stack *tmporal;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
	riset = (*top)->next->n % (*top)->n;
	*top = (*top)->next;
	(*top)->n = riset;
	if (*top != NULL)
		(*top)->prev = NULL;
	free(tmporal);
}

