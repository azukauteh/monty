#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!vglo.arg)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (int j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
}

