#include "sort.h"

/**
 * _swap - swaps two elements in a linked list,
 * @temp: pointer to node to be swapped
 * @list: list
 */

void _swap(listint_t *temp, listint_t **list)
{
	listint_t *x, *y, *z;
	int a, b;

	a = temp->n;
	b = temp->prev->n;

	x = temp->next;
	y = temp->prev;
	z = temp->prev->prev;
	if (a < b)
	{
		y->next = x;

		if (x)
			x->prev = y;
		temp->next = y;

		if (y->prev == NULL)
			*list = temp;
		y->prev = temp;

		if (z == NULL)
		{
			temp->prev = NULL;
			print_list(*list);
			return;
		}
		else
		{
			temp->prev = z;
			z->next = temp;
			print_list(*list);
		}
		_swap(temp, list);
	}
}
/**
 * insertion_sort_list - sorts a list of doubly linked lists in ascenidng order
 * @list: Doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *j;

	if (list)
		temp = *list;
	else
		exit(EXIT_FAILURE);
	temp = temp->next;
	while (temp)
	{
		j = temp->next;
		_swap(temp, list);
		temp = j;
	}
}
