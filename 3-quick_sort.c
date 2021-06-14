#include "sort.h"
/**
 * quick_sort - function to perform a quick sort using lomuto partition
 * @array: the given array
 * @size: the size of array
 *
 * Return: nothing
 **/
void quick_sort(int *array, size_t size)
{
	int beg = 0, end = size - 1;

	if (size < 2)
		return;
	do_quick_sort(array, beg, end, size);
}
/**
 * do_quick_sort - perform quick sort
 * @array: the given array
 * @start: the begnining index of an array
 * @end: end index of an array
 * @size: the size of array
 *
 * Return: nothing
 **/
void do_quick_sort(int *array, int start, int end, size_t size)
{
	int p_index;

	if (start < end)
	{
		p_index = partition(array, start, end, size);
		do_quick_sort(array, start, p_index - 1, size);
		do_quick_sort(array, p_index + 1, end, size);
	}
}
/**
 * swap - swap to element of an array
 * @array: the given array
 * @i: index of the frist element
 * @j: index of the second element
 * @size: the size of array
 *
 * Return: nothing
 **/
void swap(int *array, int i, int j, size_t size)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}
/**
 * partition - sort and partition the array
 * @array: the given array
 * @start: the start of the array
 * @end: the end of the array
 * @size: the size of array
 *
 * Return: the index of the pivot element
 **/
int partition(int *array, int start, int end, size_t size)
{
	int i = start, j = start;
	int pivot = array[end];

	while (j <= end)
	{
		if (array[j] < pivot)
		{
			swap(array, i, j, size);
			i++;
		}
		j++;
	}
	swap(array, i, end, size);
	return (i);
}
