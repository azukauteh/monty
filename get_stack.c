#include "monty.h"

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @stack: head of the linked list
 * @line_number: line number;
 * Return: no return
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	vglo.lifo = 1;
}
