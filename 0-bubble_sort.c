#include "sort.h"

/**
 *bubble_sort - function that sorts an array of integers
 *	in ascending order using the Bubble sort algorithm
 *@array: the array to sort
 *@size: the size of the array
 *Return: no return
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, size1;
	int tmp;

	size1 = size;

	if (array == NULL || size < 2)
		return;

	while (size1 > 0)
	{
		for (i = 0; i < size1 - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
		--size1;
	}
}
