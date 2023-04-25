#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints the arrays of the integers
 *
 * @array: The integer arrays to be printed
 * @size: The number of elements in the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
