#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcmp - Performs lexicographic comparison of two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, 0 if s1 == s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * starts_with - Checks if a string starts with a given substring.
 * @haystack: The string to search in.
 * @needle: The substring to find.
 *
 * Return: Address of the next character after the substring if found,
 *         NULL otherwise.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*haystack != *needle)
			return (NULL);
		haystack++;
		needle++;
	}

	return ((char *)haystack);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while ((*dest++ = *src++))
		;

	return (ret);
}
