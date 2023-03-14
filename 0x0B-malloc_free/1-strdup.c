#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicates a string
 *
 * @str: the string to duplicate
 *
 * Return: pointer to new duplicated string or NULL if str is NULL or if
 *         memory allocation fails
 */
char *_strdup(char *str)
{
char *dup_str;
int i;

if (str == NULL)
return (NULL);

/* Get length of str */
for (i = 0; str[i] != '\0'; i++)
;

/* Allocate memory for new string */
dup_str = malloc(sizeof(char) * (i + 1));
if (dup_str == NULL)
return (NULL);

/* Copy contents of str to dup_str */
for (i = 0; str[i] != '\0'; i++)
dup_str[i] = str[i];
dup_str[i] = '\0';

return (dup_str);
}

