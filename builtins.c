#include "shell.h"
/**
 * exit_check - check for exit command.
 * @buff: buffer.
 *
 * Return: nothing.
 */
void exit_check(char* buff)
{
	if(strncmp(buff,"exit",5) == 0)
		exit(EXIT_SUCCESS);
}
/**
 * path_handler - handles the path entery.
 * @path: path to return.
 * @buff: buffer
 * Return: nothing.
 */
void path_handler(char* path,char* buff)
{
	if (stat(buff, &status) != 0)
	{
		strcat(path,buff);
	} else
		strcpy(path, buff);
}
