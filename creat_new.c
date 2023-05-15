#include "shell.h"

/**
 * creat_new - check the code
 * @instr: Input value
 * @noun: Input value
 * @environm: Input value
 * @input3: Input value.
 * Return: Nothing.
 */
void creat_new(char **instr, char *noun, char **environm, int input3)
{
int pid = 0;
int stat = 0;
int wt_err = 0;

pid = fork();
if (pid < 0)
{
perror("Error: ");
free_exit(instr);
}
else if (pid == 0)
{
execve(instr, noun, environm, input3);
free_dp(instr);
}
else
{
wt_err = waitpid(pid, &stat, 0);
if (wt_err < 0)
{
free_exit(instr);
}
free_dp(instr);
}
}


/**
 * change_folder - Check the code.
 * @p_way: Input value
 * Return: 0 or -1.
 */
int change_folder(const char *p_way)
{
char *buffer_t = NULL;
size_t sz = 1024;

if (p_way == NULL)
p_way = getcwd(buffer_t, sz);
if (chdir(p_way) == -1)
{
perror(p_way);
return (98);
}
return (1);
}
