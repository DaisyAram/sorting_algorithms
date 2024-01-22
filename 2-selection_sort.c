#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int min_idx;
	size_t i, j;

	if (array == NULL || size < 2)/*array is null or less than 1*/
		return;

	for (i = 0; i < size - 1; i++)/*iterate over the array*/
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != 1)
		{
			swap_ints(array + i, array +  min_idx);
			print_array(array, size);
		}
	}
}
