#include "monty.h"


/**
 * get_div - function that divides the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number where the command appears
 *
 * Description: Divides the second top element of the stack by the top element.
 * Return: void
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		first = *stack;
		second = first->next;
		second->n /= first->n;
		*stack = second;
		(*stack)->prev = NULL;
		free(first);
	}
}

