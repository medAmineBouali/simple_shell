#include "shell.h"

/**
 * mem_free - frees memory
 *@arg_num: number of args to free.
 * Return: nothing.
 */
void mem_free()
{
	int i;

	for (i = 0; i <= arg_num; i++)
	{
		free(argvs[i]);
	}
	free(argvs);
	free(buffer);
}
