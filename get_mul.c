#include "monty.h"

/**
 * _mul - Multiplies the second top element of the stack
 *        with the top element of the stack.
 *
 * @stack: Pointer to the head of the linked list.
 * @line_number: Line number.
 */
void _mul(stack_t **stack, unsigned int line_number)
(
stack_t *top = *stack;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

*stack = (*stack)->next;
(*stack)->n *= top->n;
(*stack)->prev = NULL;

free(top);
}

