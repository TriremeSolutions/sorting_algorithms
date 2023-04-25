#include "sort.h"

/**
 * selection_sort - A function that takes
 * an array of integers and
 * arranges them in ascending order
 * using the selection sort algortihm
 *
 * @array: the array
 * @size: array size
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, k;

	for (i = 0; i < size; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array(k) > array[j])
				k = j;
		}

		if (i != k)
		{
			temp = array[i];
			array[i] = array[k];
			array[k] = temp;
			print_array(array, size);
		}
	}
}
