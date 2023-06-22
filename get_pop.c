#include "monty.h"

/**
 * monty_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
stack_t *next = NULL;
if ((*stack)->next == NULL)
{
set_op_tok_error(pop_error(line_number));
return;
}
next = (*stack)->next->next;
free((*stack)->next);
if (next)
next->prev = *stack;
(*stack)->next = next;
}
