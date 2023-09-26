#include "sort.h"

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
 * @l: starting index of the subset to order.
 * @r: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the piv.
 * Prints the array after each swap of two elements.
 */
int hp(int *array, size_t size, int l, int r)
{
	int piv, abv, blw;

	piv = array[r];
	for (abv = l - 1, blw = r + 1; abv < blw;)
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
 * @array: array of integers to sort.
 * @size: size of the array.
 * @l: starting index of the array partition to order.
 * @r: ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hsort(int *array, size_t size, int l, int r)
{
	int part;

	if (r - l > 0)
	{
		part = hp(array, size, l, r);
		hsort(array, size, l, part - 1);
		hsort(array, size, part, r);
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
