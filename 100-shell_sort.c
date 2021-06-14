#include "sort.h"
/**
 * shell_sort - function to perform shell sort using knuth's gap
 * @array: the given array
 * @size: the size of the array
 *
 * Return: nothing
 **/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j, tmp;

	if (size < 2)
		return;
	while (gap <= (size / 3))
		gap = gap * 3 + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap; j = j - gap)
			{
				if (array[j] < array[j - gap])
				{
					tmp = array[j - gap];
					array[j - gap] = array[j];
					array[j] = tmp;
				}
			}
		}
		gap /= 3;
		print_array(array, size);
	}
}
