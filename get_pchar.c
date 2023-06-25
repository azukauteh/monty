#include "monty.h"

/**
 * _pchar - Prints the char value of the top element.
 *
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

if ((*stack)->n < 0 || (*stack)->n >= 128)
{
fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

printf("%c\n", (*stack)->n);
}

