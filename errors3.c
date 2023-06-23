#include "monty.h"

int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * div_error - Prints division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: Always returns EXIT_FAILURE.
 */
int div_error(unsigned int line_number)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: Always returns EXIT_FAILURE.
 */
int pchar_error(unsigned int line_number, char *message)
{
fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
return (EXIT_FAILURE);

}
