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
 * radix_sort - sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: input array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int flag = 1, n = 10;
	size_t i, f;

	if (!array || size == 1)
		return;
	while (flag)
	{
		flag = 0;
		for (i = 1, f = 1; i <  size; i++, f++)
		{
			if ((array[i - 1] % (n * 10)) / ((n * 10) / 10) > 0)
				flag = 1;
			if (((array[i - 1] % n) / (n / 10)) > ((array[i] % n) / (n / 10)))
			{
				swap_int(array, i - 1, i);
				if ((i - 1) > 0)
					i = i - 2;
			}
		}
		print_array(array, size);
		n = n * 10;
	}
}
