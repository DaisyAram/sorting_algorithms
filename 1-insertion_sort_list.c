#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *next, *current;

	if (list == NULL || *list == NULL)/*list is null*/
	return;

	current = ((*list)->next);
	while (current != NULL)/*current node is not null*/
	{
		next = current->next;
		itr = current->prev;

		while (itr != NULL && itr->n > current->n)/*iterator is not null*/
		{
			itr->next = current->next;
			if (current->next != NULL)
				current->next->prev = itr;
			current->prev = itr->prev;
			current->next = itr;
			itr->prev = current;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			itr = current->prev;
			print_list(*list);
		}
		current = next;
	}
}
