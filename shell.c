#include "shell.h"

int calc_args(char *buffer);
/**
 * main - Entry point.
 * 
 * Return: nothing.
 */

int main(void)
{
	int i;
	pid_t pid;
	char path[25] = "/bin/";
	size_t bufsize = 32;
	char delim1[] = "\n", delim2[] = " ";
	char *envp[] = {NULL};
	char *argv;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	printf("($) ");
	if (getline(&buffer,&bufsize,stdin) == -1)
	{
		exit(EXIT_FAILURE);
	}
	signal(SIGINT, sig_handler);
	strtok(buffer, delim1);
	arg_num = calc_args(buffer);
	argvs = (char **)malloc((arg_num + 1) * sizeof(char *));
	argv = strtok(buffer, delim2);
	built_ins();
	path_handler(path);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (1);
	}
	if (pid != 0)
	{
		wait(&i);
		mem_free();
		main();
	}
	else
	{
		for (i = 0; argv; i++)
		{
			*(argvs + i) = argv;
			argv = strtok(NULL, delim2);
		}
		if(execve(path, argvs, envp) == -1)
		{
			perror("./shell");
		}

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
		if(buffer[i] == ' ' && buffer[i - 1] != ' ')
			n++;
	}
	return (n + 1);
}
