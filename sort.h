#ifndef sort_h
#define sort_h
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void do_quick_sort(int *array, int start, int end, size_t size);
void swap(int *array, int i, int j, size_t size);
int partition(int *array, int start, int end, size_t size);
void shell_sort(int *array, size_t size);
void swap_list(listint_t **list, listint_t **cur_node);
void cocktail_sort_list(listint_t **list);
int max_value(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge(int *array, int *buf, int start, int mid, int end);
void do_merge_sort(int *array, int *buf, int start, int end);
void merge_sort(int *array, size_t size);
void print_my_array(int *array, int start, int end);
void radix_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void countSort(int *array, size_t size, int base);
int *mem_arr(int size);
#endif
