#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of your program into a single
 *              string.
 * @ac: The number of arguments passed to the program
 * @av: An array of pointers to the arguments
 *
 * Return: If ac == 0, av == NULL, or malloc() fails, returns NULL.
 *         Otherwise, returns a pointer to the new string.
 */
char *argstostr(int ac, char **av)
{
int i, j, k = 0, len = 0;
char *str;

if (ac == 0 || av == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
len++;
len++; /* account for space between words */
}
len++; /* account for null terminator */

str = malloc(sizeof(char) * len);
if (str == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
{
str[k] = av[i][j];
k++;
}
str[k] = '\n';
k++;
}
str[k] = '\0';
return (str);
}

