#include "sort.h"

/**
 * swap - Swap two nodes in a doubly-linked list.
 * @h: A pointer to the head of the linked list.
 * @first: The first node to swap.
 * @second: The second node to swap.
 */
void swap(listint_t **h, listint_t **first, listint_t *second)
{
	(*first)->next = second->next;
	if (second->next != NULL)
		second->next->prev = *first;
	second->prev = (*first)->prev;
	second->next = *first;
	if ((*first)->prev != NULL)
		(*first)->prev->next = second;
	else
		*h = second;
	(*first)->prev = second;
	*first = second->prev;
}

/**
 *insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 *@list: A pointer to the head of a doubly-linked list of integers.
 *Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = tmp)
	{
		tmp = curr->next;
		prev = curr->prev;
		while (prev != NULL && curr->n < prev->n)
		{
			swap(list, &prev, curr);
			print_list((const listint_t *)*list);
		}
	}
}
