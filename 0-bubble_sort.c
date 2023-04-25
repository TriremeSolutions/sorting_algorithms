#include "sort.h"

/**
 * bubble_sort - A sorting function for an
 * array of integers which arranges them in
 * ascending order using the
 * bubble sort algorithm
 *
 * @array: the array
 * @size: array size
 *
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int temp, swapped;

	for (n = size, swapped = 1; n > 0 && swapped; n--)
	{
		swapped = 0;
		for (i = 0; (i + 1) < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
	}
}
