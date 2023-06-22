#include "monty.h"
void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);

/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
size_t i = 0;
if (op_toks == NULL)
return;
for (i = 0; op_toks[i]; i++)
free(op_toks[i]);
free(op_toks);
}

/**
 * token_arr_len - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int token_arr_len(void)
{
unsigned int toks_len = 0;
while (op_toks[toks_len])
toks_len++;
return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
int i, j;
for (i = 0; line[i]; i++)
{
for (j = 0; delims[j]; j++)
{
if (line[i] == delims[j])
break;
}
if (delims[j] == '\0')
return (0);
}
return (1);
}


