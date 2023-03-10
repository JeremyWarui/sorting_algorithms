#include "sort.h"
#include <stdbool.h>

/**
*swap_ints - Swap two integers in an array.
*@a: The first integer to swap
*@b: The second integer to swap
*/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
*bubble_sort - sort an array of integersin ascending ordedr.
*@array: An array of the integersto sort
*@size: The size of the array
*
*Description: Prints the array after each swap
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, len = size;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
