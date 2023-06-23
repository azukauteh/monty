#include "monty.h"

char **op_toks;
int check_mode(stack_t *stack);

/**
 * monty_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */

void monty_push(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *new;
int i;
new = malloc(sizeof(stack_t));
if (new == NULL)
{

return;
}
if (op_toks[1] == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free(new);
return;
}
for (i = 0; op_toks[1][i]; i++)
{
if (op_toks[1][i] == '-' && i == 0)
continue;
if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free(new);
return;
}
}
new->n = atoi(op_toks[1]);
switch (check_mode(*stack))
{
case STACK:
tmp = (*stack)->next;
new->prev = *stack;
new->next = tmp;
if (tmp)
tmp->prev = new;
(*stack)->next = new;
break;
case QUEUE:
tmp = *stack;
while (tmp->next)
tmp = tmp->next;
new->prev = tmp;
new->next = NULL;
tmp->next = new;
break;
default:
free(new);
break;
}
}
