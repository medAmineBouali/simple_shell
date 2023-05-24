#include "shell.h"
/**
 * sig_handler - handles signals.
 * @sig: signal number.
 *
 * Return: nothing.
 */
void sig_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n($) ",5);
}
