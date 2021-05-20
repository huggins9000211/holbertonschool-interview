#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



/**
 * _strlen - test
 * @s: test
 * Return: test
 */
int _strlen(char *s)
{
	int count;

	count = 0;
	while (s[0] != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

/**
 * getResult - test
 * @len: test
 * @num1: test
 * @len1: test
 * @num2: test
 * @len2: test
 * Return: test
 */
void getResult(int len, char *num1, int len1, char *num2, int len2)
{
	int *result, *a, *b;
	int i, j, tmp;

	result = (int *) malloc(sizeof(int) * len);
	a = (int *) malloc(sizeof(int) * len1);
	b = (int *) malloc(sizeof(int) * len2);
	i = 0;
	while (i <= len)
	{
		result[i] = 0;
		i++;
	}
	for (i = len1 - 1, j = 0; i >= 0; i--, j++)
		a[j] = num1[i] - '0';
	for (i = len2 - 1, j = 0; i >= 0; i--, j++)
		b[j] = num2[i] - '0';
	i = 0;
	for (i = 0; i < len2; i++)
	{
		for (j = 0; j < len1 ; j++)
			result[i + j] += b[i] * a[j];
	}
	for (i = 0; i < len; i++)
	{
		tmp = result[i] / 10;
		result[i] = result[i] % 10;
		result[i + 1] = result[i + 1] + tmp;
	}
	for (i = len1 + len2; i > 0; i--)
	{
		if (result[i] > 0)
			break;
	}
	for (; i >= 0; i--)
		_putchar(result[i] + '0');
	_putchar('\n');
}
/**
 * makeArrays - test
 * @num1: test
 * @num2: test
 * Return: test
 */
void makeArrays(char *num1, char *num2)
{
	int len1;
	int len2;
	int len3;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len3 = len1 + len2;
	getResult(len3, num1, len1, num2, len2);

}
/**
 * errorr - test
 * Return: test
 */
void errorr(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * main - test
 * @argc: test
 * @argv: test
 * Return: test
 */
int main(int argc, char *argv[])
{
	int count;
	char *num1;
	char *num2;
	int i;

	if ((argc < 3) || (argc > 3))
	{
		errorr();
	}
	count = 1;
	while (count < argc)
	{
		if (count == 1)
			num1 = argv[count];
		else
			num2 = argv[count];
		count++;
	}
	for (i = 0; num1[i]; i++)
	{
		if ((num1[i] > 57) || (num1[i] < 48))
			errorr();
	}
	for (i = 0; num2[i]; i++)
	{
		if ((num2[i] > 57) || (num2[i] < 48))
			errorr();
	}
	makeArrays(num1, num2);
	return (1);
}
