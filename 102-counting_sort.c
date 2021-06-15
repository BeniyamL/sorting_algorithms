#include "sort.h"
/**
 * counting_sort - function to perform couting sort
 * @array: the given array
 * @size: the size of array
 *
 * Return: nothing
 **/
void counting_sort(int *array, size_t size)
{
	int max, *count_array, i, j, *sorted_array;

	if (size < 2)
		return;
	max = max_value(array, size);
	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	for (i = 0; i <= max; i++)
	{
		for (j = 0; j < (int)size; j++)
		{
			if (i == array[j])
				count_array[i] += 1;
		}
	}
	for (i = 1; i <= max; i++)
		count_array[i] = count_array[i] + count_array[i - 1];
	print_array(count_array, max + 1);
	sorted_array = malloc(sizeof(int) * (count_array[max] + 1));
	if (sorted_array == NULL)
	{
		free(sorted_array);
		return;
	}
	for (j = 0; j < (int)size; j++)
	{
		sorted_array[count_array[array[j]] - 1] = array[j];
		count_array[array[j]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];
	free(count_array);
	free(sorted_array);
}
/**
 * max_value - function to find the maximum value
 * @array: the given array
 * @size: the size of array
 *
 * Return: the max value
 **/
int max_value(int *array, size_t size)
{
	int max = array[0], i;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
