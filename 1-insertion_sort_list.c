#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - A function that sorts
 * a Doubly linked list of integers
 * in ascending order using
 * the insertion sort algorithm
 *
 * @list: the doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *tmp;

	if (!list)
		return;
	new_pt = *list;
	while (new_pt)
	{
		while (new_pt->next && (new_pt->n > new_pt->next->n))
		{
			temp = new_pt->next;
			new_pt->next = temp->next;
			temp->prev = new_pt->prev;
			if (new_pt->prev)
				new_pt->prev->next = temp;
			if (temp->next)
				temp->next->prev = new_pt;
			new_pt->prev = temp;
			temp->next = new_pt;
			if (temp->prev)
				new_pt = temp->prev;
			else
				*list = temp;
			print_list(*list);
		}
		new_pt = new_pt->next;
	}
}
