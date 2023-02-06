#include "sort.h"

/**
 * _swap - swaps two elements in a linked list,
 * @temp: pointer to node to be swapped
 * @list: list
 */

void _swap(listint_t *temp, listint_t **list)
{
	/* declare variable to save temp-next, temp-prev and temp-prev-prev */
	listint_t *x, *y, *z;
	int a, b;

	a = temp->n;
	b = temp->prev->n;

	x = temp->next;
	y = temp->prev;
	z = temp->prev->prev;
	/* compare n to (n-1), swap only if condition is true */
	if (a < b)
	{
		y->next = x;
		/* check if temp-next is null; case for when temp is the last node of the linked list */
		if (x)
			x->prev = y;
		temp->next = y;
		/* check if temp-prev is null; case for when temp-prev is the 1st node of the list  */
		if (y->prev == NULL)
			*list = temp;
		y->prev = temp;

		if (z == NULL)
		{
			/* if z is null, temp prev will not point to anything */
			temp->prev = NULL;
			print_list(*list);
			/* if temp-prev is null, it means temp has occupied the first position of the linked list
			 * no more swapping can be done so we exit the swap function
			 */
			return;
		}
		else
		{
			temp->prev = z;
			z->next = temp;
			print_list(*list);
		}
		/* call swap recursively to ensure that temp compares to all the previous nodes of the linked list */
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

	temp = *list;
	/* move temp to second element of list for easy comparison with (n-1) */
	temp = temp->next;
	printf("Data at temp: %d\n", temp->n);
	/* loop through the nodes */
	while (temp)
	{
		j = temp->next; /* save address of temp-next since temp is manipulated inside the swap function */
		/* call swap - which will only swap if temp data is less than data at temp prev.Otherwise
		 * it will return to the while loop for the while loop to check the next node.
		 * */
		_swap(temp, list);
		temp = j;
	}
}
