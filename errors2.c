#include "monty.h"

int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);

/**
 * pop_error - Prints pop error messages for empty stacks.
 * @line_number: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int line_number)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int line_number)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int line_number, char *op)
{
fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
return (EXIT_FAILURE);
}
