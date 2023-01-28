#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *a, size_t s, size_t strt, size_t seq, char f);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge- Sort a bitonic sequence inside an array of integers
 * @a: An array of integers
 * @s: The size of the array
 * @strt: The starting index of the sequence in array to sort
 * @f: The direction to sort in
 * @seq: sequence to follow
 */
void bitonic_merge(int *a, size_t s, size_t strt, size_t seq, char f)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = strt; i < strt + jump; i++)
		{
			if ((f == UP && a[i] > a[i + jump])
			|| (f == DOWN && a[i] < a[i + jump]))
				swap_ints(a + i, a + i + jump);
		}
		bitonic_merge(a, s, strt, jump, f);
		bitonic_merge(a, s, strt + jump, jump, f);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence
 * @array: An array of integers
 * @start: The starting index of a block of the building bitonic sequence
 * @size: The size of the array
 * @seq: The size of a block of the building bitonic sequence
 * @flow: The direction to sort the bitonic sequence block in
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}
