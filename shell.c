#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
/**
 * main - Entry point.
 * 
 * Return: nothing.
 */

void main(void)
{
	char *buffer;
	size_t bufsize = 32;
	struct stat status;
	char delim[] = "\n";
	char *const argv[] = {NULL};
	char *const envp[] = {NULL};

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	printf("#cisfun$ ");
	if (getline(&buffer,&bufsize,stdin) == -1)
		exit(0);
	strtok(buffer,delim);
	if (stat(buffer, &status) == 0)
	{
		if(execve(buffer, argv, envp) == -1)
		{
			perror("Could not execve");
		} else
			exit(0);
	} else
		{
			perror("./shell: No such file or directory");
			main();
		}
}
