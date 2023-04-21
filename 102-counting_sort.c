#include "sort.h"

/**
 * get_highest - Get the highets value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The highest integer in the array.
 */
int get_highest(int *array, int size)
{
	int highest, i;

	for (highest = array[0], i = 1; i < size; i++)
	{
		if (array[i] > highest)
			highest = array[i];
	}

	return (highest);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the countering sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *sorted, highest, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	highest = get_highest(array, size);
	counter = malloc(sizeof(int) * (highest + 1));
	if (counter == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (highest + 1); i++)
		counter[i] = 0;
	for (i = 0; i < (int)size; i++)
		counter[array[i]] += 1;
	for (i = 0; i < (highest + 1); i++)
		counter[i] += counter[i - 1];
	print_array(counter, highest + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(counter);
}
