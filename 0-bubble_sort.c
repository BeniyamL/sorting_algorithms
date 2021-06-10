#include "sort.h"
/**
 * bubble_sort - function for bubble sort
 * @array: the given array
 * @size: the size of the array
 *
 * Returns: nothing
 **/
void bubble_sort(int *array, size_t size)
{
	size_t first_elem, second_elem, i = 0, j = 0;
	int swap_flag = 0;

	if (!array || size < 2)
		return;
	while (i < size)
	{
		j = 0;
		while ((j + 1) < size)
		{
			first_elem = array[j];
			second_elem = array[j + 1];
			if (second_elem < first_elem)
			{
				array[j] = second_elem;
				array[j + 1] = first_elem;
				print_array(array, size);
				swap_flag = 1;
			}
			j++;
		}
		if (swap_flag == 0)
			break;
		i++;
	}
}
