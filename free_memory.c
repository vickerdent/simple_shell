#include "shell.h"

/**
 * free_dp - check code.
 * @instr: Input value.
 * Return: Nothing.
 */
void free_dp(char **instr)
{
size_t s = 0;

if (instr == NULL)
return;

while (instr[s])
{
free(instr[s]);
s++;
}

if (instr[s] == NULL)
free(instr[s]);
free(instr);
}


/**
 * free_exit - check the code
 * @instr: Input value.
 * Return: Nothing.
 */
void free_exit(char **instr)
{
size_t s = 0;

if (instr == NULL)
return;

while (instr[s])
{
free(instr[s]);
s++;
}

if (instr[s] == NULL)
free(instr[s]);
free(instr);
exit(EXIT_FAILURE);
}
