#include "sort.h"
/**
 * quick_sort - Function that takes an array of integers
 * and arranges them in ascending order using the
 * quicksort algorithm
 * @array: the array of integers
 * @size: the array size
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	_sub_sort(array, 0, size - 1, size);
}
/**
 * _sub_sort - A quick_sort helper function,
 * implementation of the Lomuto partition scheme.
 * @arr: input array
 * @min: first element index
 * @max: last element index
 * @size: array size
 * Return: no return
 */
void _sub_sort(int *arr, int min, int max, int size)
{
	int i, j, k;
	int current;

	if (min < max)
	{
		i = max;
		j = min;
		for (k = min; k < max; k++)
		{
			if (arr[k] < arr[i])
			{
				if (k != j)
				{
					current = arr[k];
					arr[k] = arr[j];
					arr[j] = current;
					print_array(arr, size);
				}
				j++;
			}
		}
		if (j != i && arr[j] != arr[i])
		{
			current = a[j];
			a[j] = a[i];
			a[i] = current;
			print_array(arr, size);
		}
		_sub_sort(arr, min, j - 1, size);
		_sub_sort(arr, j + 1, max, size);
	}
}
