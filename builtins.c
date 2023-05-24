#include "shell.h"
/**
 * _exiter - exit command..
 *
 * Return: nothing.
  */
void _exiter()
{
	mem_free();
	exit(0);
}
/**
 * path_handler - handles the path entery.
 * @path: path to return.
 * Return: nothing.
 */
void path_handler(char* path)
{
	if (stat(buffer, &status) != 0)
	{
		strcat(path,buffer);
	} else
		strcpy(path, buffer);
}
void print_env(void)
{
	int index = 0;
	char **env = environ;
	index = 0;
	while (env[index])
	{
		printf("%s\n",index,env[index]);
		++index;
	}
}
void built_ins()
{
	if(strncmp(buffer,"exit",5) == 0)
	       _exiter();
	if(strncmp(buffer,"env",4) == 0)
		print_env();
}
