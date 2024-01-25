#include "sort.h"

void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int low, int high);
void quick_sort_recursive(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot = array + high;
	int i, j;

	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, size, low, high);
		quick_sort_recursive(array, size, low, pivot - 1);
		quick_sort_recursive(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
