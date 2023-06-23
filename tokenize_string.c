#include "monty.h"
#include <string.h>
#include <stdio.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);

/**
 * strtow - takes a string and seperates its words
 *
 * @str: string to seperate into words
 * @delims: delimitors to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */

char **strtow(char *str, char *delims)
{
char **words = NULL;
int wc = 0;
int wordLen, i = 0;

if (str == NULL || !*str)
return (NULL);

/* wc = get_word_count(str, delims);*/
if (wc == 0)
return (NULL);

words = malloc((wc + 1) * sizeof(char *));
if (words == NULL)
return (NULL);

while (*str)
{
if (*str == '\0')
break;
while (*str && strchr(delims, *str))
str++;
if (*str == '\0')
break;
wordLen = 0;
while (str[wordLen] && !strchr(delims, str[wordLen]))
wordLen++;
words[i] = malloc((wordLen + 1) * sizeof(char));
if (words[i] == NULL)
{
while (i > 0)
free(words[--i]);
free(words);
return (NULL);
}
strncpy(words[i], str, wordLen);
words[i][wordLen] = '\0';
i++;
str += wordLen;
}
words[i] = NULL;
return (words);
}

/**
 * is_delim - checks if stream has delimitor char
 *
 * @ch: character in stream
 *
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
int i = 0;

while (delims[i])
{
if (delims[i] == ch)
return (1);
i++;
}
return (0);
}

/**
 * get_word_length - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use to delimit words
 *
 * Return: word length of current word
 */

int get_word_length(char *str, char *delims)
{
int wLen = 0, pending = 1, i = 0;
while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
{
wLen++;
}
if (wLen > 0 && is_delim(str[i], delims))
break;
i++;
}
return (wLen);
}
