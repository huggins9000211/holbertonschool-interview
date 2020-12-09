#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"


int indexHelper(int *arr, int i, int x, int start)
{
	if (start == 1)
		printf("Searching in array: ");
	if (arr[i - 1] == x)
	{
		printf("%d, ", x);
		return (indexHelper(arr, i - 1, x, 0));
	}
	printf("%x\n", x);
	return (i);
	
}

int binarySearch(int arr[], int l, int r, int x)
{
	if ((r - l == 0) && (arr[r] != x))
		return (-1);
	if (r >= l)
	{
		int i;
		int mid;

		i = l;
		printf("Searching in array: ");
		while (i <= r)
		{
			if (i == r)
				printf("%d\n", arr[r]);
			else
				printf("%d, ", arr[i]);
			i++;
		}
		mid = l + (r - l) / 2;

		if (arr[mid] == x)
		{
			if (arr[mid - 1] == x)
				return(indexHelper(arr, mid, x, 1));
			return (mid);
		}
		if (arr[mid] > x)
			return (binarySearch(arr, l, mid - 1, x));
		return (binarySearch(arr, mid + 1, r, x));
	}
	return (-1);
}

int advanced_binary(int *array, size_t size, int value)
{
	int result;

	if (!array)
		return (-1);
	result = binarySearch(array, 0, size - 1, value);
	return (result);
}
