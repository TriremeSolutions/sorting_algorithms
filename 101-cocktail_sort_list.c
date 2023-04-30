#include "sort.h"

/**
 * list_switch - switches the list elements
 *
 * @ptA: pointer one
 * @ptB: pointer two
 * @n: in increment 0, in decrement 1
 *
 * Return: no return
 */
void list_switch(listint_t **ptA, listint_t **ptB, int n)
{
	listint_t *temp, *sec;

	sec = *ptA;
	temp = *ptB;

	sec->next = temp->next;
	temp->prev = sec->prev;

	if (temp->next)
		temp->next->prev = sec;

	if (sec->prev)
		sec->prev->next = temp;

	sec->prev = temp;
	temp->next = sec;

	if (n == 0)
		*ptA = temp;
	else
		*ptB = sec;
}

/**
 * move_big - shifts bigger numbers to end
 *
 * @pt_m: the bigger number's pointer
 * @lim: list limit
 * @list: list of integers
 *
 * Return: no return
 */
void move_big(listint_t **pt_m, listint_t **lim, listint_t **list)
{
	listint_t *sec;

	sec = *pt_m;

	while (sec != *lim && sec->next != *lim)
	{
		if (sec->n > sec->next->n)
		{
			list_switch(&sec, &(sec->next), 0);
			if (sec->prev == NULL)
				*list = sec;
			print_list(*list);
		}
		sec = sec->next;
	}

	*lim = sec;
	*pt_m = sec;
}

/**
 * move_small - shifts smaller numbers to the start
 *
 * @pt_m: the smaller number's pointer
 * @lim: list limit
 * @list: list of integers
 *
 * Return: no return
 */
void move_small(listint_t **pt_m, listint_t **lim, listint_t **list)
{
	listint_t *sec;

	sec = *pt_m;

	while (sec != *lim && sec->prev != *lim)
	{
		if (sec->n < sec->prev->n)
		{
			list_switch(&(sec->prev), &sec, 1);
			if (sec->prev->prev == NULL)
				*list = sec->prev;
			print_list(*list);
		}
		sec = sec->prev;
	}

	*lim = sec;
	*pt_m = sec;
}

/**
 * cocktail_sort_list - sorts a doubly linked
 * list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 *
 * @list: the linked list head
 * Return: no return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limA, *limB, *pt_m;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limA = limB = NULL;
	pt_m = *list;

	do {
		move_big(&pt_m, &limA, list);
		move_small(&pt_m, &limB, list);
	} while (limA != limB);
}
