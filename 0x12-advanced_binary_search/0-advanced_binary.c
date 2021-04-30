#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * printArr - check the code for Holberton School students.
 *
 * @array: test
 * @i1: test
 * @i2: test
 * Return: Always 0.
 */
void printArr(int *array, int i1, int i2)
{
	int use = 0;

	if (i1 <= i2)
	{
		printf("Searching in array: ");
		use = 1;
	}
    if (i1 == i2)
    {
        printf("%d", array[i1]);
    }
    else
    {
    	while (i1 <= i2)
    	{

    		printf("%d", array[i1]);
    		if (i1 != i2)
    			printf(", ");
    		i1++;
    	}
    }
	if (use)
		printf("\n");
}

/**
 * indexHelper - check the code for Holberton School students.
 *
 * @arr: test
 * @i: test
 * @x: test
 * @start: test
 * Return: Always 0.
 */
int indexHelper(int *arr, int i, int x, int start)
{
	if (start == 1)
		printf("Searching in array: ");
	if (arr[i - 1] == x)
	{

		printf("%d**, ", x);
		return (indexHelper(arr, i - 1, x, 0));
	}
	printf("%x $$\n", x);
	return (i);
}

/**
 * binarySearch - check the code for Holberton School students.
 *
 * @arr: test
 * @l: test
 * @r: test
 * @x: test
 * Return: Always 0.
 */
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid;

		printArr(arr, l, r);
		mid = l + (r - l) / 2;
		if ((arr[mid] == x) && (arr[mid - 1] != x))
			return (mid);
		if (arr[mid] >= x)
			return (binarySearch(arr, l, mid, x));
		return (binarySearch(arr, mid + 1, r, x));
	}
	return (-1);
}

/**
 * advanced_binary - check the code for Holberton School students.
 *
 * @array: test
 * @size: test
 * @value: test
 * Return: Always 0.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int result;

	if (!array)
		return (-1);
	result = binarySearch(array, 0, size - 1, value);
	return (result);
}
