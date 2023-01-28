#include "sort.h"

/**
 * p_data - print data
 * @text: text to print
 * @arr: array
 * @start: starting index
 * @end: last index
 * Return: void
 */

void p_data(char *text, int *arr, int start, int end)
{
	char *del;
	int i;

	printf("[%s]: ", text);
	del = "";
	for (i = start; i <= end; i++)
	{
		printf("%s%d", del, arr[i]);
		del = ", ";
	}
	printf("\n");
}

/**
 * merge - function that performs merging
 * @arr: List/array to merge
 * @low: low index
 * @mid: mid point
 * @high: highest index
 * @buffer: buffer/space/array
 * Return: void
 */

void merge(int *arr, int low, int mid, int high, int *buffer)
{
	int i, j, k;

	i = k = low;
	j = mid + 1;
	printf("Merging...\n");
	p_data("left", arr, low, mid);
	p_data("right", arr, mid + 1, high);

	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
			buffer[k++] = arr[i++];
		else
			buffer[k++] = arr[j++];
	}
	for (; i <= mid; i++)
		buffer[k++] = arr[i];
	for (; j <= high; j++)
		buffer[k++] = arr[j];
	for (i = low; i <= high; i++)
		arr[i] = buffer[i];
	p_data("Done", arr, low, high);
}

/**
 * rec_msort - recursive merge sort function
 * @arr: array to sort
 * @low: low index
 * @high: highest index
 * @buffer: buffer/array
 * Return: void
 */

void rec_msort(int *arr, int low, int high, int *buffer)
{
	int mid;

	if (low < high)
	{
		mid = (low + high - 1) / 2;
		rec_msort(arr, low, mid, buffer);
		rec_msort(arr, mid + 1, high, buffer);
		merge(arr, low, mid, high, buffer);
	}
}

/**
 * merge_sort -Sorts an arrayof integers
 * in ascending order using the
 * Merge sort algorithm
 * @array: array
 * @size: size
 * Return: no return
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	rec_msort(array, 0, size - 1, buffer);
	free(buffer);
}
