#include "monty.h"

/**
 * monty_mul - function that multiplies the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number where the command appears
 *
 * Description: Multiplies the second top element of the
 * stack with the top element.
 * Return: void
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;
	second->n *= first->n;
	*stack = second;
	(*stack)->prev = NULL;
	free(first);
}


