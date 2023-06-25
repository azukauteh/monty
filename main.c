#include "monty.h"
#define BUFFER_SIZE 256

/**
 * free_vglo - frees the global variables
 *
 * Return: no return
 */
void free_vglo(void)
{
free_dlistint(vglo.head);
free(vglo.buffer);
fclose(vglo.fd);
}

/**
 * start_vglo - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_vglo(FILE *fd)
{
vglo.lifo = 1;
vglo.cont = 1;
vglo.arg = NULL;
vglo.head = NULL;
vglo.fd = fd;
vglo.buffer = NULL;
}

/**
 * free_stack - Frees the memory allocated for the stack.
 *
 * @stack: Pointer to the head of the linked list.
 */
void free_stack(stack_t *stack)
{
stack_t *current = stack;
stack_t *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
}



/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
FILE *fd;

if (argc == 1 || argc > 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

fd = fopen(argv[1], "r");

if (fd == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

return (fd);
}



/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */



int main(int argc, char *argv[])
{
void (*f)(stack_t **stack, unsigned int line_number);
FILE *fd;
char buffer[BUFFER_SIZE];
ssize_t nlines = 0;
char *lines[2] = {NULL, NULL};
fd = check_input(argc, argv);
start_vglo(fd);

while (fgets(buffer, sizeof(buffer), fd) != NULL)
{
nlines++;
lines[0] = _strtoky(buffer, " \t\n");
if (lines[0] && lines[0][0] != '#')
{
f = get_opcodes(lines[0]);
if (!f)
{
fprintf(stderr, "L%u: unknown instruction %s\n", vglo.cont, lines[0]);
free_vglo();
exit(EXIT_FAILURE);
}
vglo.arg = _strtoky(NULL, " \t\n");
f(&vglo.head, vglo.cont);
}
vglo.cont++;
free_vglo();
}

fclose(fd);
return (0);
}
