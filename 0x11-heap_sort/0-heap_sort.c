#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
 * swap - Entry point
 *
 * @a: test
 * @b: test
 * Return: Always 0
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * heapify - Entry point
 *
 * @arr: test
 * @n: test
 * @i: test
 * @size: test
 * Return: Always 0
 */
void heapify(int arr[], int n, int i, int size)
{

	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, size);
		heapify(arr, n, largest, size);
	}
}
/**
 * heap_sort - Entry point
 *
 * @array: test
 * @size: test
 * Return: Always 0
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i > 0)
		{
			print_array(array, size);
		}
		heapify(array, i, 0, size);

	}
}
