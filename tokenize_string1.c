#include "monty.h"

int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get word count from
 * @delims: delimitors to use to delimit words
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
 int count = 0;
    int is_word = 0;

    while (*str)
    {
        if (*str && !strchr(delims, *str))
        {
            if (!is_word)
                is_word = 1;
            count++;
        }
        else
        {
            is_word = 0;
        }
        str++;
    }

return (count);
}


/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 *
char *get_next_word(char *str, char *delims)
{
 while (*str && strchr(delims, *str))
    {     
	    str++;

    return (str);
return (NULL);
    }
}*/