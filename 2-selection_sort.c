#include "sort.h"

/**
 * selection_sort - function that takes an array of integers
 * and arranges them in ascending order
 * using the selection sort algorithm
 *
 * @array: the array of integers
 * @size: the array size
 *
 * Description: after each swap, print_array prints the array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	int current;
	size_t i, j, k;

	for (i = 0; i < size; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[k] > array[j])
				k = j;
		}

		if (i != k)
		{
			current = array[i];
			array[i] = array[k];
			array[k] = current;
			print_array(array, size);
		}
	}
}
