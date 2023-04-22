#include "sort.h"

/**
 * swap_num - Swap two NUMBERS in an numray.
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
 * bitonic_stuff - Sort a bitonic sequence in an array of Numbers(Numray).
 * @numray: An array of NUMBERS (NUMRAY).
 * @size: The size of the numray.
 * @start: The starting index of the sequence in numray to sort.
 * @seq: The size of the sequence to sort.
 * @dir: The direction to sort in.
 */
void bitonic_stuff(int *numray, size_t size, size_t start, size_t seq,
		char dir)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((dir == UP && numray[i] > numray[i + jump]) ||
			    (dir == DOWN && numray[i] < numray[i + jump]))
				swap_num(numray + i, numray + i + jump);
		}
		bitonic_stuff(numray, size, start, jump, dir);
		bitonic_stuff(numray, size, start + jump, jump, dir);
	}
}

/**
 * bitonic_stu2 - Convert an numray of integers into a bitonic sequence.
 * @numray: An array of NUMBERS (numray)..
 * @size: The size of the numray.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @dir: The direction to sort the bitonic sequence block in.
 */
void bitonic_stu2(int *numray, size_t size, size_t start, size_t seq, char dir)
{
	size_t cut = seq / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(numray + start, seq);

		bitonic_stu2(numray, size, start, cut, UP);
		bitonic_stu2(numray, size, start + cut, cut, DOWN);
		bitonic_stuff(numray, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(numray + start, seq);
	}
}

/**
 * bitonic_sort - Sort an numray of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the numray.
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_stu2(array, size, 0, size, UP);
}
