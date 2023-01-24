#include "sort.h"

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
	int temp;
	
	for (i = 0; i < size; i++)
	{
		for (j = k = i; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		
		if (i != k)
		{
			temp = array[i];
			array[i] = array[k];
			array[k] = temp;
			print_array(array, size);
		}
	}
}
