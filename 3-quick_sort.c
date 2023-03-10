#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @x: The first integer to swap
 * @y: The second integer to swap
 * Return: void
*/

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - partitions the array
 * @array: array to take in
 * @str: start of array;
 * @end: end of array
 * @size: full size of array
 * Return: position of pivot
 */

int partition(int *array, int str, int end, int size)
{
	int pivot = array[end];
	int i = str, j;

	for (j = str; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		swap(&array[i], &array[end]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort - quick sorts with recursion
 * @array: array to sort through
 * @str: start of array or subarray
 * @end: end of array or subarray
 * @size: size of full array
 */

void quicksort(int *array, int str, int end, int size)
{
	int j;

	if (str < end)
	{
		j = partition(array, str, end, size);
		quicksort(array, str, j - 1, size);
		quicksort(array, j + 1, end, size);
	}
}

/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */

void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
