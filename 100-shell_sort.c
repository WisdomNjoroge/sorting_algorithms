#include "sort.h"

/**
 * LargestKnuthGap - function to find the largest gap
 * @n: integer
 * Return: the largest gap
 */
int LargestKnuthGap(int n)
{
	int gap = 1;

	while (gap <= n / 3)
		gap = 3 * gap + 1;

	return (gap);
}

/**
 * reduceGap - function to reduce the gap
 * @gap: pointer to an integer
 */
void reduceGap(int *gap)
{
	*gap = (*gap - 1) / 3;
}

/**
 * shell_sort - function for the shell sort
 * @size: unsigned integer
 * @array: pointer to an integer
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, gap;

	gap = LargestKnuthGap(size);

	if (array == NULL || size < 2)
		return;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= (size_t)gap && array[j - (size_t)gap] > temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		reduceGap(&gap);
	}
}
