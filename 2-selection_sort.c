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
 * selection_sort- sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: input array of integers
 * @size: size of the array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;

	for (i = 0; i < size; i++)
	{
		for (j = k = i; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		if (i != k)
		{
			swap(&array[i], &array[k]);
			print_array(array, size);
		}
	}
}
