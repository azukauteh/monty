#include "monty.h"

/**
 * _pall - prints all the values on the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _pall(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}

(void)line_number;
}

