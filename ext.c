#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 **_strncpy - function that copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - function that concatenates two strings
 *@ama: first string
 *@krl: second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *ama, char *krl, int n)
{
	int i, j;
	char *s = ama;

	i = 0;
	j = 0;
	while (ama[i] != '\0')
		i++;
	while (krl[j] != '\0' && j < n)
	{
		ama[i] = krl[j];
		i++;
		j++;
	}
	if (j < n)
		ama[i] = '\0';
	return (s);
}

/**
 **_strchr - function that locates a character in a string
 *@s: string to be parsed
 *@c: character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
