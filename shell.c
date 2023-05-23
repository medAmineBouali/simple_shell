#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <wait.h>
int calc_args(char *buffer);
/**
 * main - Entry point.
 * 
 * Return: nothing.
 */

int main(void)
{
	int i, ii;
	pid_t pid;
	char *buffer;
	struct stat status;
	size_t bufsize = 32;
	char delim1[] = "\n", delim2[] = " ";
	char **argvs;
	char *envp[] = {"HOME=/root", "PATH=/bin:/sbin", NULL};
	char *argv;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	printf("#cisfun$ ");
	if (getline(&buffer,&bufsize,stdin) == -1)
	{
		printf("\n");
		exit(EXIT_FAILURE);
	}
	strtok(buffer, delim1);
	ii = (calc_args(buffer) + 2);
	argvs = (char **)malloc(ii * sizeof(char *));
	argv = strtok(buffer, delim2);
	if (stat(buffer, &status) != 0)
	{
		perror("./shell1");
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (1);
	}
	if (pid != 0)
	{
		wait(&i);
		for (i = 0; i < ii; i++)
		{
			free(argvs[i]);
		}
		free(argvs);
		free(buffer);
		main();
	}
	else
	{
		for (i = 0; argv; i++)
		{
			*(argvs + i) = argv;
			argv = strtok(NULL, delim2);
		}
		if(execve(buffer, argvs, envp) == -1)
		{
			perror("./shell");
		}
		main();
	}

	return (0);
}

/**
 * calc_args - calculates the number of arguments enterd.
 * @buffer: the command line entered. \
 *
 * Return: number or arguments.
 */
int calc_args(char *buffer)
{
	int i, n = 0;
	for (i = 0; buffer[i]; i++)
	{
		if(buffer[i] == ' ')
			n++;
	}
	return (n);
}
