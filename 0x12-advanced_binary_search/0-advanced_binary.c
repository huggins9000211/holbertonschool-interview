#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

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
			{
				return (binarySearch(arr, mid-1, mid, x));
			}
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
