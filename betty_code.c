#include"shell.h"
/**
 * add_numbers - Adds two numbers and returns the result.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The sum of the two numbers.
 */
int add_numbers(int a, int b)
{
	return (a + b);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int num1 = 8;
	int num2 = 2;
	int sum;

	sum = add_numbers(num1, num2);

	printf("The sum is: %d\n", sum);

	return (0);
}
