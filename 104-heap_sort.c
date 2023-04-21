#include "sort.h"


/**
 * swap_num - Swap two integers.
 * @num: The first integer to swap.
 * @num1: The second integer to swap.
 * Return: no return
 */
void swap_num(int *num, int *num1)
{
	int temp;

	temp = *num;
	*num = *num1;
	*num1 = temp;
}

/**
 * heap_binary - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 * Return: no return.
 */
void heap_binary(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, max;

	left = 2 * root + 1;
	right = 2 * root + 2;
	max = root;

	if (left < base && array[left] > array[max])
		max = left;
	if (right < base && array[right] > array[max])
		max = right;

	if (max != root)
	{
		swap_num(array + root, array + max);
		print_array(array, size);
		heap_binary(array, size, base, max);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: no return
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heap_binary(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_num(array, array + i);
		print_array(array, size);
		heap_binary(array, size, i, 0);
	}
}
