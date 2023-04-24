#include "sort.h"


/**
 * swap_num - Swap two integers in an numray.
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
 * hoare_parti - Order a subset of an numray of integers
 *                   according to the hoare partition scheme.
 * @numray: The array of NUMBERS.
 * @size: The size of the numray.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int hoare_parti(int *numray, size_t size, int start, int end)
{
	int pivot, high, low;

	pivot = numray[end];
	for (high = start - 1, low = end + 1; high < low;)
	{
		do {
			high++;
		} while (numray[high] < pivot);
		do {
			low--;
		} while (numray[low] > pivot);

		if (high < low)
		{
			swap_num(numray + high, numray + low);
			print_array(numray, size);
		}
	}

	return (high);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @numray: An array of numbers..
 * @size: The size of the numray.
 * @start: The starting index of the numray partition to order.
 * @end: The ending index of the numray partition to order.
 * Return: Nothing
 */
void hoare_sort(int *numray, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = hoare_parti(numray, size, start, end);
		hoare_sort(numray, size, start, part - 1);
		hoare_sort(numray, size, part, end);
	}
}

/**
 * quick_sort_hoare - Sort an numray of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of Numbers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the numray after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
