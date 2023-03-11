#include "main.h"
#include<stdio.h>

/**
 * _puts - prints a string to stdout
 * @str: string to be printed
 *
 * Description: This function prints a string to the standard output.
 *
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
