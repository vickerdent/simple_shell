#include "shell.h"

/**
 * exec - check the code.
 * @instr: Input value
 * @noun: Input value
 * @environm: Input value
 * @input3: Input value
 * Return: Nothing.
 */
void exec(char **instr, char *noun, char **environm, int input3)
{
struct stat z;
unsigned int i = 0;
char **a_value = NULL;
char *tot_value = NULL;

if (_strcmp(instr[0], "environm") != 0)
print_env(environm);
if (stat(instr[0], &z) == 0)
{
if (execve(instr[0], instr, environm) < 0)
{
perror(noun);
free_exit(instr);
}
}
else
{
a_value = _getPATH(environm);
while (a_value[i])
{
tot_value = _strcat(a_value[i], instr[0]);
i++;
if (stat(tot_value, &z) == 0)
{
if (execve(tot_value, instr, environm) < 0)
{
perror(noun);
free_dp(a_value);
free_exit(instr);
}
return;
}
}
msgerror(noun, input3, instr);
free_dp(a_value);
}
}


/**
 * print_env - Check the code
 * @environm: Input value
 * Return: Nothing.
 */
void print_env(char **environm)
{
size_t i = 0, len = 0;

while (environm[i])
{
len = _strlen(environm[i]);
write(STDOUT_FILENO, environm[i], len);
write(STDOUT_FILENO, "\n", 1);
i++;
}
}


/**
 * _getPATH - check the code
 * @environm: Input value.
 * Return: value or null.
 */
char **_getPATH(char **environm)
{
char *ano_value = NULL;
char **a_value = NULL;
unsigned int i = 0;

ano_value = strtok(environm[i], "=");
while (environm[i])
{
if (_strcmp(ano_value, "PATH"))
{
ano_value = strtok(NULL, "\n");
a_value = objecting(ano_value, ":");
return (a_value);
}
i++;
ano_value = strtok(environm[i], "=");
}
return (NULL);
}


/**
 * msgerror - check the code
 * @noun: Input value
 * @input3: Input value
 * @instr: Input value
 * Return: Nothing.
 */
void msgerror(char *noun, int input3, char **instr)
{
char c;

c = input3 + '0';
write(STDOUT_FILENO, noun, _strlen(noun));
write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, &c, 1);
write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, instr[0], _strlen(instr[0]));
write(STDOUT_FILENO, ": not found\n", 12);
}
