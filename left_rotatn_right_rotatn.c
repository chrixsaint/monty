#include "monty.h"

/**
 * left_rotatn - Rotates the stack to the top.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation (unused).
 * This function rotates the stack to the top by moving the
 * second element to the top. If the stack is empty or has
 * only one element, it does nothing. The parameter `counter`
 * is marked as unused since it is not utilized in the function.
 */
void left_rotatn(MontyNode_t **head,
__attribute__((unused)) unsigned int counter)
{
	MontyNode_t *temporal, *xin;

	temporal = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	xin = (*head)->next;
	xin->prev = NULL;
	while (temporal->next != NULL)
		temporal = temporal->next;
	temporal->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temporal;
	(*head) = xin;
}


/**
 * right_rotatn - Rotates the stack to the bottom.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation (unused).
 * This function rotates the stack to the bottom by moving the
 * last element to the top. If the stack is empty or has only
 * one element, it does nothing. The parameter `counter` is
 * marked as unused since it is not utilized in the function.
 */

void right_rotatn(MontyNode_t **head, __attribute__((unused))
unsigned int counter)
{
	MontyNode_t *cntrl_c;

	cntrl_c = *head;
	if (!*head || (*head)->next == NULL)
		return;
	while (cntrl_c->next)
		cntrl_c = cntrl_c->next;
	cntrl_c->next = *head;
	cntrl_c->prev->next = NULL;
	cntrl_c->prev = NULL;
	(*head)->prev = cntrl_c;
	(*head) = cntrl_c;
}
