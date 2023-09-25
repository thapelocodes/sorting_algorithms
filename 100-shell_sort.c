#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @n1: The first integer to swap.
 * @n2: The second integer to swap.
 */
void swap_ints(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: array of integers.
 * @size: size of @array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (array == NULL || size < 2)
		return;

	for (; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
				swap_ints(array + j, array + (j - gap));
		print_array(array, size);
	}
}
