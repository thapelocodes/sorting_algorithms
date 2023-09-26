#include "sort.h"

void swap_ints(int *a, int *b);
void merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bseq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * merge - Sort a bitonic sequence inside an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index of the sequence in array to sort.
 * @seq: size of the sequence to sort.
 * @flow: direction to sort in.
 */
void merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		merge(array, size, start, jump, flow);
		merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bseq - Converts an array of integers into a bitonic sequence.
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index of a block of the building bitonic sequence.
 * @seq: size of a block of the building bitonic sequence.
 * @flow: direction to sort the bitonic sequence block in.
 */
void bseq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	char *str = (flow == UP) ? "UP" : "DOWN";
	size_t cut = seq / 2;

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
		bseq(array, size, start, cut, UP);
		bseq(array, size, start + cut, cut, DOWN);
		merge(array, size, start, seq, flow);
		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bseq(array, size, 0, size, UP);
}
