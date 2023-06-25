#include "monty.h"

/**
 * _pop - removes the top element of the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _pop(stack_t **stack, unsigned int line_number)
{
stack_t *aux;

if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

aux = *stack;
*stack = (*stack)->next;
free(aux);
}

