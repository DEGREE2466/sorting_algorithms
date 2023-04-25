#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts the array of the integers in ascending
 *   order using Shell sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculates the gaps using the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/* Sort all elements at gap intervals */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		/* Prints the array after each gap is decreased */
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
