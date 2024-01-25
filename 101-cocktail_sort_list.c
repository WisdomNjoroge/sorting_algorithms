#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @a: First parameter
 * @b: Second parameter
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	b->next = a;
	a->prev = b;

	if (*list == a)
		*list = b;

	print_list((const listint_t *)*list);
}

/**
 * cocktail_sort_list - function for cocktail sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	tmp = *list;
	while (swapped)
	{
		swapped = 0;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(list, tmp, tmp->next);
				swapped = 1;
			}
			else
				tmp = tmp->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_nodes(list, tmp->prev, tmp);
				swapped = 1;
			}
			else
				tmp = tmp->prev;
		}
	}
}
