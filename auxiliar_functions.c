#include "shell.h"

/**
 * _strcmp - Check the code
 * @s1: Input value
 * @s2: Input value
 * Return: 1 or 0
 */
int _strcmp(char *s1, char *s2)
{
unsigned int c = 0;
while (s1[c])
{
if (s1[c] != s2[c])
return (0);
c++;
}
return (1);
}


/**
 * _strlen - Check the code
 * @s: Input value
 * Return: value
 */
unsigned int _strlen(char *s)
{
unsigned int length = 0;
while (s[length])
length++;
return (length);
}


/**
 * _strcpy - Check the code
 * @dest: Input value
 * @src: Input value
 * Return: pointer value
 */
char *_strcpy(char *dest, char *src)
{
char *final = dest;
while (*src)
*dest++ = *src++;
*dest = '\0';
return (final);
}


/**
 * _strcat - Check the code
 * @dest: Input value
 * @src: Input value
 * Return: pointer value
 */
char *_strcat(char *dest, char *src)
{
char *final = dest;
while (*dest)
dest++;
*dest++ = '/';
while (*src)
*dest++ = *src++;
return (final);
}


/**
 * _atoi - Check the code
 * @s: Input value
 * Return: int value.
 */
int _atoi(char *s)
{
int pt = 1;
unsigned int sum = 0;
char n_variable = 0;
if (s == NULL)
return (0);
while (*s)
{
if (*s == '-')
pt *= -1;
if (*s >= '0' && *s <= '9')
{
n_variable = 1;
sum = sum * 10 + (*s - '0');
}
else if (*s < '0' || *s > '9')
{
if (n_variable == 1)
break;
}
s++;
}
if (pt < 0)
sum = (-1 * (sum));
return (sum);
}
