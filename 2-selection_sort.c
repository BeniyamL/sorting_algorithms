#include "sort.h"
/**
 * selection_sort - function to perform selection sort
 * @array: the given array
 * @size: the size of array
 *
 * Returns: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, swap_ind;
	int min, tmp;

	if (size < 2)
		return;
	while (i < size)
	{
		swap_ind = 0;
		j = i + 1;
		min = array[i];
		while (j < size)
		{
			if (array[j] < min)
			{
				min = array[j];
				swap_ind = j;
			}
			j++;
		}
		if (swap_ind != 0)
		{
			tmp = array[i];
			array[i] = min;
			array[swap_ind] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
