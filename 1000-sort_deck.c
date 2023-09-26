#include "deck.h"
#include <stdio.h>

/**
 *_strcmp - compare two strings
 *@str1: string
 *@str2: string
 *Return: 1 str1 and str2 is equal, 0 they are not equal
 */
int _strcmp(const char *str1, char *str2)
{
	size_t i = 0;

	if (str1 == '\0')
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i])
		return (0);
	return (1);
}

/**
 * cardpos - return the position based on card you put in
 * @node: represent the card
 * Return: return the card position
 */
int cardpos(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (_strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (_strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (_strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (_strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (_strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}

/**
 *swap_card - swap a card for his previous one
 *@card: card
 *@deck: card deck
 *Return: return a pointer to a card which was enter it
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *prev = card->prev, *crnt = card;

	prev->next = crnt->next;
	if (crnt->next)
		crnt->next->prev = prev;
	crnt->next = prev;
	crnt->prev = prev->prev;
	prev->prev = crnt;
	if (crnt->prev)
		crnt->prev->next = crnt;
	else
		*deck = crnt;
	return (crnt);
}

/**
 * my_isort - function that sorts a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: Dobule linked deck to sort
 */
void my_isort(deck_node_t **deck)
{
	deck_node_t *node;
	int valprev, valcrnt;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		if (node->prev)
		{
			valprev = cardpos((node->prev));
			valcrnt = cardpos(node);
		}
		while ((node->prev) && (valprev > valcrnt))
		{
			valprev = cardpos((node->prev));
			valcrnt = cardpos(node);
			node = swap_card(node, deck);
		}
		node = node->next;
	}
}

/**
 * sort_deck - sort a deck you put in using
 * insertion sort algorithm
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	my_isort(deck);
}
