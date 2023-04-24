#include "deck.h"

int _strcmp(const char *str1, const char *str2);
char get_val(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: Positive byte difference if str1 > str2
 *         0 if str1 == str2
 *         Negative byte difference if str1 < str2
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * get_val - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_val(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *i, *insert, *temp;

	for (i = (*deck)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && insert->card->kind > i->card->kind)
		{
			insert->next = i->next;
			if (i->next != NULL)
				i->next->prev = insert;
			i->prev = insert->prev;
			i->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = i;
			else
				*deck = i;
			insert->prev = i;
			insert = i->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *i, *insert, *temp;

	for (i = (*deck)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL &&
		       insert->card->kind == i->card->kind &&
		       get_val(insert) > get_val(i))
		{
			insert->next = i->next;
			if (i->next != NULL)
				i->next->prev = insert;
			i->prev = insert->prev;
			i->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = i;
			else
				*deck = i;
			insert->prev = i;
			insert = i->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
