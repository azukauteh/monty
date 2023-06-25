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
    int n, j;

    if (!vglo.arg)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    for (j = 0; vglo.arg[j] != '\0'; j++)
    {
        if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
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

