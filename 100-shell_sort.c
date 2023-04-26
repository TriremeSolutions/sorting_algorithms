#include "sort.h"
/**
 * shell_sort - A function that takes an array of
 * integers and arranges them in ascending order
 * using the shell sort algorithm
 *
 * @array: the array of integers
 * @size: the size of the array
 * uses the Knuth sequence n + 1 = n * 3 + 1
 * Return: no return
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		_sh_sort(array, size, n);
}

/**
 * _sh_sort - A shell_sort helper function
 * @arr: the array
 * @size: the array size
 * @n: the interval
 *
 * Return: no return
 */

void _sh_sort(int *arr, int size, int n)
{
	int current, a, b;

	for (a = 0; (a + n) < size; a++)
	{
		for (b = a + n; (b - n) >= 0; b = b - n)
		{
			if (arr[b] < arr[b - n])
			{
				current = arr[b];
				arr[b] = arr[b - n];
				arr[b - n] = current;
			}
		}
	}
	print_array(arr, size);
}
