#include "sort.h"

void swap_ints(int *a, int *b);
int hp(int *array, size_t size, int left, int right);
void hsort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swaps two integers in an array.
 * @n1: first integer to swap.
 * @n2: second integer to swap.
 */
void swap_ints(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

/**
 * hp - Orders a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the piv.
 * Prints the array after each swap of two elements.
 */
int hp(int *array, size_t size, int left, int right)
{
	int piv, abv, blw;

	piv = array[right];
	for (abv = left - 1, blw = right + 1; above < below;)
	{
		do {
			abv++;
		} while (array[abv] < piv);
		do {
			blw--;
		} while (array[blw] > piv);
		if (abv < blw)
		{
			swap_ints(array + abv, array + blw);
			print_array(array, size);
		}
	}

	return (abv);
}

/**
 * hsort - Implements the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hsort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hp(array, size, left, right);
		hsort(array, size, left, part - 1);
		hsort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hsort(array, size, 0, size - 1);
}
