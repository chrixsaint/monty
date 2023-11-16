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
	MontyNode_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}


/**
 * f_rotr - Rotates the stack to the bottom.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number of the current operation (unused).
 * This function rotates the stack to the bottom by moving the
 * last element to the top. If the stack is empty or has only
 * one element, it does nothing. The parameter `counter` is
 * marked as unused since it is not utilized in the function.
 */

void f_rotr(MontyNode_t **head, __attribute__((unused)) unsigned int counter)
{
	MontyNode_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
