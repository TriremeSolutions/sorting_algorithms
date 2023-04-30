#include "sort.h"

/**
 * radix_sort - sorts an array of integers in
 * ascending order using the
 * Radix sort algorithm
 *
 * @array: the integer array
 * @size: array size
 */

void radix_sort(int *array, size_t size)
{
	int n = 10, caption = 1;
	size_t m, i;

	if (!array || size == 1)
		return;
	while (caption)
	{
		caption = 0;
		for (i = 1, m = 1; i <  size; i++, m++)
		{
			if ((array[i - 1] % (n * 10)) / ((n * 10) / 10) > 0)
				caption = 1;
			if (((array[i - 1] % n) / (n / 10)) > ((array[i] % n) / (n / 10)))
			{
				array[i - 1] = array[i - 1] + array[i];
				array[i] = array[i - 1] - array[i];
				array[i - 1] = array[i - 1] - array[i];
				if ((i - 1) > 0)
					i = i - 2;
			}
		}
		print_array(array, size);
		n = n * 10;
	}
}
