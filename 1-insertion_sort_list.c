#include "sort.h"

/**
 *insertion_sort_list - function that does insertion sort
 *@list: head node
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;

			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;
			prev = current->prev;
			print_list((const listint_t *)*list);
		}

		current = next;
	}
}

/**
 *swap_list - function for swapping doubly linked list
 *@a: the node that's greater than b
 *@b: the node that's less than a
 */
void swap_list(listint_t *a, listint_t *b)
{
	if (a->prev != NULL)
		a->prev->next = b;

	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
