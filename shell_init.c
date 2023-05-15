#include "shell.h"

/**
 * main - check the code.
 * @acr: no of arguments.
 * @arv: each argument.
 * @environm: pointer to argument.
 * Return: Always 0.
 */
int main(int acr, char **arv, char **environm)
{
char *input2 = NULL, **instr = NULL;
size_t inp_size = 0;
ssize_t i_read = 0;
int input3 = 0;
(void)acr;

while (1)
{
input3++;
prompt();
signal(SIGINT, handler);
i_read = getline(&input2, &inp_size, stdin);
if (i_read == EOF)
_EOF(input2);
else if (*input2 == '\n')
free(input2);
else
{
input2[_strlen(input2) - 1] = '\0';
instr = objecting(input2, " \0");
free(input2);
if (_strcmp(instr[0], "exit") != 0)
exit_shell(instr);
else if (_strcmp(instr[0], "cd") != 0)
change_folder(instr[1]);
else
creat_new(instr, arv[0], environm, input3);
}
fflush(stdin);
input2 = NULL, inp_size = 0;
}
if (i_read == -1)
return (EXIT_FAILURE);
return (EXIT_SUCCESS);
}


/**
 * prompt - check the code
 * Return: Nothing.
 */
void prompt(void)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "Hell_Shell>> ", 13);
}


/**
 * handler - check code.
 * @input: The input value.
 * Return: Nothing.
 */
void handler(int input)
{
(void)input;
write(STDOUT_FILENO, "\nHell_Shell>> ", 14);
}


/**
 * _EOF - check the code
 * @input2: Input value
 * Return: Nothing
 */
void _EOF(char *input2)
{
if (input2)
{
free(input2);
input2 = NULL;
}

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
free(input2);
exit(EXIT_SUCCESS);
}


/**
 * exit_shell - check the code
 * @instr: input value
 * Return: Nothing.
 */
void exit_shell(char **instr)
{
int sta_tus = 0;

if (instr[1] == NULL)
{
free_dp(instr);
exit(EXIT_SUCCESS);
}

sta_tus = _atoi(instr[1]);
free_dp(instr);
exit(sta_tus);
}
