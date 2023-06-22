#include "monty.h"


/**
 * monty_mod - Computes the rest of the division of the second top element by the top element
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number where the opcode is encountered
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	 monty_mod(stack, line_number);
}

