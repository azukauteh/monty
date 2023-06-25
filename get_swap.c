#include "monty.h"


/**
 * _swap - swaps the top two elements of the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	*stack = (*stack)->next;
	aux->next = (*stack)->next;
	aux->prev = *stack;
	(*stack)->next = aux;
	(*stack)->prev = NULL;
}
