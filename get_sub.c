#include "monty.h"

/**
 * get_sub - function that subtracts the top element from the second top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 *
 * Description: The result is stored in the second top element of the stack,
 *              and the top element is removed.
 * Return: void
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;
	second->n -= first->n;
	*stack = second;
	(*stack)->prev = NULL;
	free(first);
}

