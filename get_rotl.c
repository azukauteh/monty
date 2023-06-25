#include "monty.h"

/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 *
 * @stack: head of the linked list
 * @line_number: line number;
 * Return: no return
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	aux1 = (*stack)->next;
	aux2 = *stack;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = aux2;
	*stack = aux1;
}
