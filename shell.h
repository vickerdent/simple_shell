#ifndef _SHELL_H_
#define _SHELL_H_
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

void handler(int input);
void _EOF(char *input2);
void exit_shell(char **instr);
int main(int acr, char **arv, char **environm);
void prompt(void);

int change_folder(const char *dir);
void creat_new(char **instr, char *noun, char **environm, int input3);

char **objecting(char *input2, const char *s);

char **_getPATH(char **environm);
void msgerror(char *noun, int input3, char **instr);
void print_env(char **environm);
void execve(char **instr, char *noun, char **environm, int input3);

void free_dp(char **instr);
void free_exit(char **instr);

int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif /* _SHELL_H_ */
