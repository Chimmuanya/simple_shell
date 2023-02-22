#include "cshell.h"
/**
 * sigintHandler -handle signal
 * Return: void
*/
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(-1);
}
