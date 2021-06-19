#include "sort.h"
/**
 * merge_sort - function to perform merge sort
 * @array: the given array
 * @size: the size of the array
 *
 * Return: nothing
 **/
void merge_sort(int *array, size_t size)
{
	int start = 0, end = size - 1, *buf;

	if (size < 2)
		return;
	buf = mem_arr(size);
	do_merge_sort(array, buf, start, end);
	free(buf);
}
/**
 * do_merge_sort - function to perform merge sort
 * @array: the given array
 * @start: the start index of array
 * @end: the end index of array
 *
 * Return: nothing
 **/
void do_merge_sort(int *array, int *buf, int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = start + (end - start) / 2;
		do_merge_sort(array, buf, start, mid);
		do_merge_sort(array, buf, mid + 1, end);
		merge(array, buf, start, mid, end);
	}
}
/**
 * mem_arr- functin to create allocated array
 * @size: the size of array
 *
 * Return: the allocated array
 **/
int *mem_arr(int size)
{
	int *arr;

	arr = malloc(sizeof(int) * (size + 1));
	if (arr == NULL)
		return (NULL);
	else
		return (arr);
}
/**
 * merge - function to merge the divided elements
 * @array: the given array
 * @start: the start index of the array
 * @mid: the mid index of the array
 * @end: the end index of the array
 *
 * Return: nothing
 **/
void merge(int *array, int *buf, int start, int mid, int end)
{
	int l = 0, i = start, s1 = (mid - start) + 1, s2 = end - mid, r = s2;

	for (l = 0; l < s1 ; l++)
		buf[l] = array[l + start];
	for (r = s1; r <= end; r++)
		buf[r] = array[r];
	l = 0, r = s1;
	printf("Merging...\n");
	printf("[left]: ");
	print_my_array(array, start, s1);
	printf("[right]: ");
	print_my_array(array, r, end + 1);
	while (l < s1 && r < end + 1)
	{
		if (buf[l] <= buf[r])
		{
			array[i] = buf[l];
			l++;
		}
		else
		{
			array[i] = buf[r];
			r++;
		}
		i++;
	}
	while (l < s1)
	{
		array[i] = buf[l];
		l++, i++;
	}
	while (r < end + 1)
	{
		array[i] = buf[r];
		r++, i++;
	}
	printf("[Done]: ");
	print_my_array(array, start, end + 1);
}
/**
 * print_my_array - function to print an array
 * @array: the given array
 * @start: the start index
 * @end: the end index
 *
 * Return: nothing
 **/
void print_my_array(int *array, int start, int end)
{
	int i;

	for (i = start; i < end; i++)
	{
		if (i == end - 1)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
}
