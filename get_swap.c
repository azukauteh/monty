#include "monty.h"
/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{

stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}
