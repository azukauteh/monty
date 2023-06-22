#include "monty.h"

/**
 * monty_add - function that adds the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number where the command appears
 *
 * Description: Adds the second top element of the stack to the top element.
 * Return: void
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;
	second->n += first->n;
	*stack = second;
	(*stack)->prev = NULL;
	free(first);
}

