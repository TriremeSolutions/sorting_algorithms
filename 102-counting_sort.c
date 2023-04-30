#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: array
 * @size: size
 *
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int i, n;
	int *ptr, *buff;

	if (size < 2)
		return;

	for (n = i = 0; i < (int)size; i++)
		if (array[i] > n)
			n = array[i];

	buff = malloc(sizeof(int) * (n + 1));
	if (!buff)
		return;

	for (i = 0; i <= n; i++)
		buff[i] = 0;
	for (i = 0; i < (int)size; i++)
		buff[array[i]] += 1;
	for (i = 1; i <= n; i++)
		buff[i] += buff[i - 1];

	print_array(buff, (n + 1));
	ptr = malloc(sizeof(int) * (size + 1));

	if (!ptr)
	{
		free(buff);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		ptr[buff[array[i]] - 1] = array[i];
		buff[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = ptr[i];

	free(ptr);
	free(buff);
}
