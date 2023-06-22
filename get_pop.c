#include "monty.h"

/**
 * monty_pop - function that pops the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number where the command appears
 *
 * Description: Removes the top element from the stack.
 * Return: void
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *first;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(first);
}

