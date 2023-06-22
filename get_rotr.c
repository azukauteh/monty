#include "monty.h"

/**
 * monty_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
stack_t *top, *bottom;
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;
top = (*stack)->next;
bottom = (*stack)->next;
while (bottom->next != NULL)
bottom = bottom->next;
bottom->prev->next = NULL;
(*stack)->next = bottom;
bottom->prev = *stack;
bottom->next = top;
top->prev = bottom;
(void)line_number;
}
