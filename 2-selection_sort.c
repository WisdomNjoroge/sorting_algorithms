/**
 * selection_sort - Sorts an array of integers in ascending order using the
 *                  selection sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	/* Check if the array is NULL or has less than 2 elements */
	if (array == NULL || size < 2)
		return;

	/* Iterate through the array */
	for (size_t i = 0; i < size - 1; i++)
	{
		int *minIndex = array + i;

		/* Find the minimum element in the unsorted part of the array */
		for (size_t j = i + 1; j < size; j++)
		{
			if (array[j] < *minIndex)
				minIndex = array + j;
		}

		/* Swap the minimum element with the current element */
		if ((array + i) != minIndex)
		{
			swap(array + i, minIndex);
			print_array(array, size);
		}
	}
}

/**
 * swap - Swaps two integers.
 *
 * @a: The first integer.
 * @b: The second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
