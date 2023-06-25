#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}

