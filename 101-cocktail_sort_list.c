#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @a: First parameter
 * @b: Second parameter
 *
 * This function swaps two nodes in a doubly linked list. It takes in the double
 * pointer to the head of the list, as well as the two nodes to be swapped.
 * It updates the necessary pointers to correctly swap the nodes.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	// Swap the previous and next pointers of the nodes
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	// Update the next and previous pointers of the nodes
	a->next = b->next;
	b->prev = a->prev;

	b->next = a;
	a->prev = b;

	// Update the head of the list if necessary
	if (*list == a)
		*list = b;

	// Print the updated list
	print_list((const listint_t *)*list);
}

/**
 * cocktail_sort_list - Function for cocktail sort
 * @list: Double pointer to the head of the list
 *
 * This function implements the cocktail sort algorithm on a doubly linked list.
 * It takes in the double pointer to the head of the list and sorts the list in
 * ascending order using the cocktail sort algorithm.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *tmp;

	// Check if the list is empty or has only one element
	if (!list || !*list || !(*list)->next)
		return;

	tmp = *list;
	while (swapped)
	{
		swapped = 0;
		while (tmp->next)
		{
			// If the current node is greater than the next node, swap them
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
			// If the current node is smaller than the previous node, swap them
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
