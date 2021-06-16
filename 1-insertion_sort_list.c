#include "sort.h"
/**
 * insertion_sort_list - function to sort a doubly list using insertion sort
 * @list: the given list
 *
 * Return: nothing
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = *list, *tmp, *next_node, *lastStop = NULL;
	int flag = 0;

	if (cur == NULL || list == NULL || cur->next == NULL || !cur->prev)
		return;
	while (cur && cur->next)
	{
		next_node = cur->next;
		if (next_node->n < cur->n)
		{
			tmp = cur->prev;
			cur->next = next_node->next;
			cur->prev = next_node;
			next_node->next = cur;
			next_node->prev = tmp;
			if (cur->next)
				cur->next->prev = cur;
			if (tmp)
				next_node->prev->next = next_node;
			else
				*list = next_node;
			cur = cur->prev;
			print_list(*list);
			if (cur->prev && cur->prev->n > cur->n)
			{
				if (flag == 0)
					lastStop = cur->next;
				flag = 1;
				cur = cur->prev;
				continue;
			}
		}
		if (flag == 1)
		{
			cur = lastStop;
			flag = 0;
		}
		else
			cur = cur->next;
	}
}
