#include "cshell.h"

/**
 * _puterr -function to write char to stderr
 * @c: char to add to buffer
 * Return: -1 on error with setting of errorno
*/
int _puterr(char c)
{
	int n;
	n = write(2, &c, 1);
	return (n);
}

/**
 * _putserr - write string to sterr
 * @str: str to add to buffer
 * Return: void
*/
void _putserr(char *str)
{
	int j = 0;

	if(str == NULL)
		return;
	while (*(str + j) != '\0')
	{
		_puterr(*(str + j));
		j++;
	}
}

/**
 * _pchat_tofd - write char to fd
 * @c: char to be written
 * @fd: fd
 * Return: -1 on error
 */
int pchar_tofd(char c, int fd)
{
	int n;
	n = write(fd, &c, 1);
	return (n);
}

/**
 * _pstr_tofd - write str to fd
 * @str: str to be written
 * @fd: fd
 * Return: -1 on error
 */
int pstr_tofd(char *str, int fd)
{
	int j = 0;
	if(str == NULL)
		return (0);
	while (*str != '\0')
		j = pchar_tofd(*(str++), fd) + j;
	return (j);
}

/**
 * print_err - print an error msg
 * @fname: info struct container
 * @err_str: string contains errr type
 * Return: 0 if no numbers in converted strr wlse 1
*/
void print_err(char *fname, char *err_str)
{
    _putserr(fname);
    _putserr(": ");
    _putserr(err_str);
}

/**
 * print_dec - prints a base 10 number
 * @n: input
 * @fd: file descriptor to write to
 *
 * Return: number of chars printed
*/
int print_dec(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	if (fd == STDERR_FILENO)
		__putchar = _puterr;
	if (input < 0)
	{
		input *= -1;
		__putchar('-');
	}
	if (input / 10)
	{
		print_dec(input / 10, fd);
	}

	return (1 + __putchar((input % 10) + '0'));
}
