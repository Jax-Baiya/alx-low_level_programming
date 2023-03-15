#include <stdlib.h>
#include "main.h"

/**
 * count_words - count the number of words in a string
 * @str: the string to count words in
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return (count);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: pointer to an array of strings (Success) or NULL (Error)
 */
char **strtow(char *str)
{
	char **tokens;
	int i, j, k, len, count;

	if (str == NULL || *str == '\0')
		return (NULL);

	count = count_words(str);
	if (count == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count + 1));
	if (tokens == NULL)
		return (NULL);

	for (i = 0, k = 0; i < count; i++)
	{
		while (str[k] == ' ')
			k++;

		len = 0;
		while (str[k + len] != ' ' && str[k + len] != '\0')
			len++;

		tokens[i] = malloc(sizeof(char) * (len + 1));
		if (tokens[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			return (NULL);
		}

		for (j = 0; j < len; j++)
			tokens[i][j] = str[k++ + j];
		tokens[i][j] = '\0';
	}
	tokens[i] = NULL;

	return (tokens);
}

