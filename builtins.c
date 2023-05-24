#include "shell.h"
/**
 * exit_check - check for exit command.
 * @buff: buffer.
 *
 * Return: nothing.
 */
void _exiter(char* buff)
{
	(void)buff;
	exit(0);
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
void print_env(void)
{
	int index = 0;
	char **env = environ;
	index = 0;
	while (env[index])
	{
		printf("%s\n",env[index]);
		++index;
	}
}
void built_ins(char* buff)
{
	if(strncmp(buff,"exit",5) == 0)
	       _exiter(buff);
	if(strncmp(buff,"env",4) == 0)
		print_env();
}
