#include "shell.h"

/**
 * objecting - Check the code
 * @s: Input value
 * @input2: input value
 * Return: string
 */
char **objecting(char *input2, const char *s)
{
char *token = NULL, **commands = NULL;
size_t bufsize = 0;
int i = 0;
if (input2 == NULL)
return (NULL);
bufsize = _strlen(input2);
commands = malloc((bufsize + 1) * sizeof(char *));
if (commands == NULL)
{
perror("Unable to allocate input2");
free(input2);
free_dp(commands);
exit(EXIT_FAILURE);
}
token = strtok(input2, s);
while (token != NULL)
{
commands[i] = malloc(_strlen(token) + 1);
if (commands[i] == NULL)
{
perror("Unable to allocate input2");
free_dp(commands);
return (NULL);
}
_strcpy(commands[i], token);
token = strtok(NULL, s);
i++;
}
commands[i] = NULL;
return (commands);
}
