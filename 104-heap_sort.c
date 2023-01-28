#include "sort.h"

/**
 * swap_int - swaps two integers
 * @arr: array
 * @x: first number
 * @y: second number
 * Return void
 */

void swap_int(int *arr, int x, int y)
{
	arr[x] = arr[x] + arr[y];
	arr[y] = arr[x] - arr[y];
	arr[x] = arr[x] - arr[y];
}

/**
 * rec_heap - recursion to build max heap
 * @arr: array
 * @n: index number
 * @size: size of array
 * @limit: limit of the array
 * Return: void
 */

void rec_heap(int *arr, int n, size_t size, int limit)
{
	int large, n2;

	n2 = n * 2;

	if (n2 + 2 < limit)
	{
		rec_heap(arr, n2 + 1, size, limit);
		rec_heap(arr, n2 + 2, size, limit);
	}

	if (n2 + 1 >= limit)
		return;
	if (n2 + 2 < limit)
	{
		if (arr[n2 + 1] > arr[n2 + 2])
			large = n2 + 1;
		else
			large = n2 + 2;
	}
	else
		large = n2 + 1;

	if (arr[n] < arr[large])
	{
		swap_int(arr, n, large);
		print_array(arr, size);
		rec_heap(arr, large, size, limit);
	}
}

/**
 * heap_sort - sorts array of int in ascending order
 * @array: size of array
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	int i;
	size_t lim;

	if (!array || size == 0)
		return;

	lim = size;

	for (i = 0; lim > 1; lim--)
	{
		rec_heap(array, i, size, lim);
		if (array[i] >= array[lim - 1])
		{
			swap_int(array, i, lim - 1);
			print_array(array, size);
		}
	}
}
