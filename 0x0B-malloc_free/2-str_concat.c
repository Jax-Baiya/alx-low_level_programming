#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 * Return: a pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *conct;
	int len1 = 0, len2 = 0, i = 0, j = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	conct = malloc(sizeof(char) * (len1 + len2 + 1));
	if (conct == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		conct[i] = s1[i];
	for (j = 0; j < len2; j++, i++)
		conct[i] = s2[j];

	conct[i] = '\0';
	return (conct);
}

