#include "monty.h"

/**
 * _div - Divides the second element by the top element of the stack.
 *
 * @stack: Pointer to the head of the linked list.
 * @line_number: Line number.
 */
void _div(stack_t **stack, unsigned int line_number)
{
stack_t *top = *stack;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

*stack = (*stack)->next;
(*stack)->n /= top->n;
(*stack)->prev = NULL;

free(top);
}

