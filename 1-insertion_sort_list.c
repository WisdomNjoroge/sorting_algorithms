/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using the insertion sort algorithm.
 *
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	// Check if the list is empty or has only one element
	if (*list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *prev, *next;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;

		// Move the current node to its correct position in the sorted part of the list
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
