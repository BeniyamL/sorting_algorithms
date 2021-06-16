#include "sort.h"
/**
 * radix_sort - function to perfom radix sort
 * @array: the given array
 * @size: the size of array
 *
 * Return: nothing
 **/
void radix_sort(int *array, size_t size)
{
	int max, digit = 1;

	if (size < 2)
		return;
	max = get_max(array, size);
	while (max >= 1)
	{
		countSort(array, size, digit);
		print_array(array, size);
		digit *= 10;
		max = max / digit;
	}
}
/**
 * get_max - get the maximum number
 * @array: the given array
 * @size: the size of array
 *
 * Return: the maximum value
 */
int get_max(int *array, size_t size)
{
	int max = array[0], i;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * countSort- function to perfrom customized counting sort
 * @array: the given array
 * @size: the size of array
 * @base: th base number that divides the number
 *
 * Return: nothing
 **/
void countSort(int *array, size_t size, int base)
{
	int count_array[10] = {0}, i, j, *sorted_array;

	sorted_array = malloc(sizeof(int) * (size + 1));
	if (sorted_array == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		count_array[(array[i] / base) % 10] += 1;

	for (i = 1; i < 10; i++)
		count_array[i] = count_array[i] + count_array[i - 1];
	for (j = ((int)size) - 1 ; j >= 0; j--)
	{
		sorted_array[count_array[(array[j] / base) % 10] - 1] = array[j];
		count_array[(array[j] / base) % 10] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];
	free(sorted_array);
}

