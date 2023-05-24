#include "shell.h"
/**
 * sig_handler - handles signals.
 * @sig: signal number.
 *
 * Return: nothing.
 */
void exit_check(char* buff)
{
	if(strncmp(buff,"exit",5) == 0)
		exit(EXIT_SUCCESS);
}
