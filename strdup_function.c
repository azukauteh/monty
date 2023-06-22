#include "monty.h"
#include <string.h>

char *strdup(const char *str);

/**
 * strdup - Duplicates a string.
 * @str: The string to duplicate.
 * Return: Pointer to the newly allocated
 *          duplicated string, or NULL on failure.
 */
char *strdup(const char *str)
{
char *dup = NULL;
size_t len;

if (!str)
return (NULL);

len = strlen(str);
dup = malloc((len + 1) * sizeof(char));
if (!dup)
return (NULL);

strcpy(dup, str);
return (dup);
}
