#include "sort.h"

/**
 * swap_num - Swap two integers.
 * @num: The first integer to swap.
 * @num1: The second integer to swap.
 */
void swap_num(int *num, int *num1)
{
	int temp;

	temp = *num;
	*num = *num1;
	*num1 = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: no return
 */
void shell_sort(int *array, size_t size)
{
	size_t space, i, j;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (i = space; i < size; i++)
		{
			j = i;
			while (j >= space && array[j - space] > array[j])
			{
				swap_num(array + j, array + (j - space));
				j -= space;
			}
		}
		print_array(array, size);
	}
}
