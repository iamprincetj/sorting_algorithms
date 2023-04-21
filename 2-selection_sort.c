#include "sort.h"

/**
 *selection_sort - function that sorts an array of integers
 *		in ascending order using the Selection sort algorithm
 *@array: A pointer to the array
 *@size: the size of the array
 *Return: no return
 */

void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
