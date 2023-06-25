#include "monty.h"
/**
 * _rotr - reverse the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	aux = *stack;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *stack;
	aux->prev = NULL;
	(*stack)->prev = aux;
	*stack = aux;
}
