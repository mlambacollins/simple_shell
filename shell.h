#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
void prompt(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
int _argc(char *str);
extern char **environ;
char **_av(char *line);
char *_str_dupl(char *str);
void handle_sign(int signh);
void _handle_buitin(char **line, char ***av, char **s_dup);

#endif
