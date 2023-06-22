#include "monty.h"

/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = (*stack)->next;

while (tmp)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
(void)line_number;
}

