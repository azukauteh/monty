#include "monty.h"

int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * unknown_op_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: Always returns EXIT_FAILURE.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: Always returns EXIT_FAILURE.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
