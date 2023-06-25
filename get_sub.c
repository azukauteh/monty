#include "monty.h"

/**
 * _sub - subtracts the top element from the second top element of the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _sub(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
free_vglo();
exit(EXIT_FAILURE);
}

(*stack)->next->n -= (*stack)->n;
_pop(stack, line_number);
}

