#include "shell.h"

/**
* _strlen - get length of string
* @s: A pointer to char
*
*  a function that returns the length of a string.
* Return: length of string
*/
int _strlen(const char *s)
{
	int len = 0;
	const char *c = s;

	while (*c != '\0')
	{
		len++;
		c++;
	}

	return (len);
}

/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * if NULL is passed, treat it as an empty string
 * Return: a pointer should point to a newly allocated space
 * in memory which contains the ontents of s1,
 * followed by the contents of s2, and null terminated
 * or return NULL on failure
 */
char *str_concat(const char *s1, const char *s2)
{
	char *concat;
	int size1 = 0;
	int size2 = 0;
	int i = 0;
	int j;

	if (s1 != NULL)
	{
		while (s1[size1] != '\0')
			size1++;
	}
	if (s2 != NULL)
	{
		while (s2[size2] != '\0')
			size2++;
	}
	concat = malloc((size1 + size2 + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);

	if (s1 != NULL)
	{
		for (i = 0; i < size1; i++)
			concat[i] = s1[i];
	}
	if (s2 != NULL)
	{
		for (j = 0; i < size1 + size2; i++, j++)
			concat[i] = s2[j];
	}
	concat[i] = '\0';
	return (concat);
}

/**
 * _strcmp - compares two strings.
 * @s1: first string
 * @s2: second string
 *
 *  a function that compares two strings similar to strcmp funcution
 *  Return: 0: s1 = s2, +ve value: s1 > s2, -ve value: s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (s1[i] - s2[i]);
}

/**
 * _strdup - copy string
 * @str: a string to be copied
 * a function that returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 *
 * Return: a pointer to a new string which is a duplicate of the string str
 * or returns NULL if insufficient memory was available
 */
char *_strdup(const char *str)
{
	char *copy;
	int size = 0;
	int i;

	if (str == NULL)
		return (NULL);

	while (str[size] != '\0')
		size++;
	size++;
	copy = malloc(size * sizeof(char));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		copy[i] = str[i];
	return (copy);
}
