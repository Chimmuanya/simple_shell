#include "cshell.h"


/**
 * _putchar - write char to stdout
 * @c: char to be written
 *
 * Return: -1 on error
*/
int _putchar(char c)
{
	int n = 0;

	n = write(1, &c, 1);
	return (n);
}


/**
 * _puts - write str to stdout
 * @str: str to be written
 *
 * Return: -void
*/
void _puts(char *str)
{
	if (str == NULL)
		return;
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
