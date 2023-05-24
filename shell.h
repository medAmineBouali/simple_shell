#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <wait.h>
#include <fcntl.h>
#include <signal.h>

#define END_OF_FILE -2
extern char **environ;
void print_env(void);
void built_ins(char* buff);
struct stat status;
extern char **environ;
void sig_handler(int sig);
void _exiter(char* buff);
void path_handler(char* path,char* buff);

#endif
