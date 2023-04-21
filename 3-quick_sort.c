#include "sort.h"

void swap_num(int *num, int *num1);
int lomuto_partition(int *array, size_t size, int start, int end);
void lomuto_sort(int *array, size_t size, int start, int end);
void quick_sort(int *array, size_t size);

/**
 * swap_num - Swap two integers in an array.
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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int *pivot, high, low;

	pivot = array + end;
	for (high = low = start; low < end; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap_num(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > *pivot)
	{
		swap_num(array + high, pivot);
		print_array(array, size);
	}

	return (high);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 * Return: no return.
 */
void lomuto_sort(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = lomuto_partition(array, size, start, end);
		lomuto_sort(array, size, start, part - 1);
		lomuto_sort(array, size, part + 1, end);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: no return.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
