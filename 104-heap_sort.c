#include <stdio.h>
#include "sort.h"

/**
 * swap_integers - Swaps two integers in an array
 *
 * @a: Pointer to first integer to be swapped
 * @b: Pointer to second integer to be swapped
 *
 * This function swaps values of the two integers in an array.
 */
void swap_integers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Repairs the heap whose root element is at the index 'start'.
 * Assumes that the heaps rooted at its children are valid.
 * @array: Arrays to sort.
 * @start: Start index to repair heap from.
 * @end: End index of the heap.
 * @size: Size of array.
 *
 * Return: void.
 */
static void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		swap_integers(&array[root], &array[swap]);
		print_array(array, size);

		root = swap;
	}
}

/**
 * heap_sort - Sorts the array of integers in ascending order
 *        using the Heap sort algorithm.
 * @array: Arrays to be sorted.
 * @size: Size of the array.
 *
 * Return: void.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size <= 1)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, i, size - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_integers(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
