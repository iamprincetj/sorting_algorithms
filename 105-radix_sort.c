#include "sort.h"

int get_highest(int *array, int size);
void radix_count_sort(int *array, size_t size, int sig, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * get_highest - Get the highest value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The highestimum integer in the array.
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
 * radix_count_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void radix_count_sort(int *array, size_t size, int sig, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: No return.
 */
void radix_sort(int *array, size_t size)
{
	int highest, sig, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	highest = get_highest(array, size);
	for (sig = 1; highest / sig > 0; sig *= 10)
	{
		radix_count_sort(array, size, sig, buffer);
		print_array(array, size);
	}

	free(buffer);
}
