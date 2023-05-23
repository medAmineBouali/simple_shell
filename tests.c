#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
int calc_args(char *buffer);
/**
 * main - Entry point.
 * 
 * Return: nothing.
 */

int main(void)
{
	int i;
	char *buffer;
	struct stat status;
	size_t bufsize = 32;
	char delim1[] = "\n", delim2[] = " ";
	char **argvs;
	char *envp[] = {"PATH=/bin", NULL};
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
		exit(0);
	}
	strtok(buffer, delim1);
	argvs = (char **)malloc((calc_args(buffer) + 2)* sizeof(char *));
	argv = strtok(buffer, delim2);
	if (stat(buffer, &status) == 0)
	{
		for (i = 0; argv; i++)
		{
			*(argvs + i) = argv;
			argv = strtok(NULL, delim2);
		}
		main();
	} else
		{
			perror("./shell");
			main();
		}
	return (1);
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
