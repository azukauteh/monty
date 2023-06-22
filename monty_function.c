#include "monty.h"
#include <string.h>

char **op_toks;

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);


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
malloc_error();
return;
}

if (op_toks[1] == NULL)
{
set_op_tok_error(no_int_error(line_number));
free(new);
return;
}

for (i = 0; op_toks[1][i]; i++)
{
if (op_toks[1][i] == '-' && i == 0)
continue;
if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
{
set_op_tok_error(no_int_error(line_number));
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

