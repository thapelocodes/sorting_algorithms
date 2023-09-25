#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps two integers in an array.
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
 * partition - Orders a subset of an array of integers according to
 *             the lomuto partition scheme (last element as pivot).
 * @array: array of integers.
 * @size: size of @array.
 * @l: subset to order.
 * @r: subset to order.
 *
 * Return: partition index.
 */
int partition(int *array, size_t size, int l, int r)
{
	int *p, a, b;

	p = array + r;
	for (a = b = l; b < r; b++)
	{
		if (array[b] < *p)
		{
			if (a < b)
			{
				swap_ints(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}

	if (array[a] > *p)
	{
		swap_ints(array + a, p);
		print_array(array, size);
	}

	return (a);
}

/**
 * sort - Implements the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @l: The starting index of the array partition to order.
 * @r: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void sort(int *array, size_t size, int l, int r)
{
	int part;

	if (r - l > 0)
	{
		part = partition(array, size, l, r);
		sort(array, size, l, part - 1);
		sort(array, size, part + 1, r);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
