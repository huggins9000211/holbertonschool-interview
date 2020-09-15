#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - Entry point
 *
 * @n: Arguments counter
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int is_palindrome(unsigned long n)
{
	unsigned long r, originalN;

	originalN = n;
	r = 0;
	while (n != 0)
	{
		r = r * 10;
		r = r + n % 10;
		n = n / 10;
	}

	if (originalN == r)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
