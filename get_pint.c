#include "monty.h"

/**
 * monty_pint - Function that prints the top element on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where the instruction appears
 *
 * Description:
 *  - pint
 *
 * Return:
 *  - No explicit return value. Exits with EXIT_FAILURE on failure.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
