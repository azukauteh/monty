#include "monty.h"

/**
 * _pstr - prints the string of the stack
 *
 * @stack: head of the linked list
 * @line_number: line number;
 * Return: no return
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
stack_t *aux;
(void)line_number;

aux = *stack;
while (aux && aux->n > 0 && aux->n < 128)
{
printf("%c", aux->n);
aux = aux->next;
}

printf("\n");
}

