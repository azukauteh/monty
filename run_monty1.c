#include "monty.h"
#include <stdio.h>

void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);
int is_empty_line(const char *line, const char *delims);

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
instruction_t op_funcs[] = {
{"push", monty_push},
{"pall", monty_pall},
{"pint", monty_pint},
{"pop", monty_pop},
{"swap", monty_swap},
{"add", monty_add},
{"nop", monty_nop},
{"sub", monty_sub},
{"div", monty_div},
{"mul", monty_mul},
{"mod", monty_mod},
{"pchar", monty_pchar},
{"pstr", monty_pstr},
{"rotl", monty_rotl},
{"rotr", monty_rotr},
{"stack", monty_stack},
{"queue", monty_queue},
{NULL, NULL}
};
int i;

for (i = 0; op_funcs[i].opcode; i++)
{
if (strcmp(opcode, op_funcs[i].opcode) == 0)
return (op_funcs[i].f);
}

return (NULL);
}


/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	int exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (fgets(line, len, script_fd) != NULL)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			free(line);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(op_toks[0], line_number);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, line_number);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);
	free(line);

	return (exit_status);
}

