#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of boolean values
 */
typedef enum bool
{
	false = 0,
	true
} bool;
/**
 * print_list - Prints a list of integers
 * @list: The list to be printed
 */
void print_list(const listint_t *list);

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);
/* sorting function */
void shell_sort(int *array, size_t size);
/* swap function */
void swap(int *x, int *y);
/* swapping function */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
/* swapping function */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
/* cocktail shaker algorithm */
void cocktail_sort_list(listint_t **list);
/* Counting function */
void counting_sort(int *array, size_t size);
/* swapping function */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
/* bubble sort */
void bubble_sort(int *array, size_t size);
/* insertion sort*/
void insertion_sort_list(listint_t **list);
/* selection sort */
void selection_sort(int *array, size_t size);
/* quick sort */
void quick_sort(int *array, size_t size);
/* merge sort */
void merge_sort(int *array, size_t size);

#endif
