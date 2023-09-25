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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t pos, comp;

	if (array == NULL || size < 2)
		return;

	for (pos = 0; pos < size - 1; pos++)
	{
		min = array + pos;
		for (comp = pos + 1; comp < size; comp++)
			min = (array[comp] < *min) ? (array + comp) : min;

		if ((array + pos) != min)
		{
			swap_ints(array + pos, min);
			print_array(array, size);
		}
	}
}
