#include "sort.h"
/**
 * cocktail_sort_list - function to perfrom cocktail sort
 * @list: the given list
 *
 * Return: nothing
 **/
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur = *list, *next_node, *prev_node;
	int start = -1, end = -1, swap_flag = 1;

	if (cur == NULL || list == NULL)
		return;
	while (swap_flag == 1)
	{
		swap_flag = 0;
		end = 0;
		while (cur && cur->next && start != end)
		{
			next_node = cur->next;
			if (next_node->n < cur->n)
			{
				swap_list(list, &cur);
				print_list(*list);
				swap_flag = 1;
			}
			cur = cur->next;
			end++;
		}
		if (swap_flag == 0)
			break;
		swap_flag = 0;
		start = end - 1;
		cur = cur->prev;
		end = -1;
		while (cur && cur->prev && start != end)
		{
			prev_node = cur->prev;
			if (prev_node->n > cur->n)
			{
				swap_list(list, &prev_node);
				print_list(*list);
				swap_flag = 1;
				cur = cur->next;
			}
			cur = cur->prev;
			end++;
		}
		cur = cur->next;
	}
}
/**
 * swap - function to swap doubly linked list
 * @list: the given list
 * @cur: the current node
 *
 * Return: nothing
 **/
void swap_list(listint_t **list, listint_t **cur_node)
{
	listint_t *tmp, *next_node, *cur = *cur_node;

	next_node = cur->next;
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
	*cur_node = cur;
}
