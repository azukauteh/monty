#include "monty.h"


/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */

void _push(stack_t **doubly, unsigned int cline)
{
int n, j;

if (!vglo.arg)
{
fprintf(stderr, "L%u: usage: push integer\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}

for (j = 0; vglo.arg[j] != '\0'; j++)
{
if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
{
fprintf(stderr, "L%u: usage: push integer\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
}

n = atoi(vglo.arg);

if (vglo.lifo == 1)
add_dnodeint(doubly, n);
else
add_dnodeint_end(doubly, n);
}
