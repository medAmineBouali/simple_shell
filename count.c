#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * main - Entry point.
 *
 * Return: returns 0 if successfull and 1 if failed.
 */

int main(void)
{
	pid_t pid = getpid();

	fork();
	if (getpid() == -1)
		return(1);
	if (pid == getpid())
		printf("hi, im the parent, %d\n", pid);
	else
	{
		 pid = getpid();
		printf("hi, im the child, %d\n", pid);
	}
	return (0);
}
