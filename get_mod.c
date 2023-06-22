#include "monty.h"



/**
 * monty_mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_op_tok_error(short_stack_error(line_number, "mod"));
return;
}
if ((*stack)->next->n == 0)
{
set_op_tok_error(div_error(line_number));
return;
}
(*stack)->next->next->n %= (*stack)->next->n;
monty_pop(stack, line_number);
}

