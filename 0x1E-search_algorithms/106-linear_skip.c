#include "search_algos.h"
/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: A pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: A pointer on the first node where value is located, or
 * NULL if value is not present in list or if head is NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp;

	if (list == NULL)
		return (NULL);

	/** Find range for linear search */
	tmp = list;
	while (tmp->express != NULL && tmp->n < value)
	{
		list = tmp;
		tmp = tmp->express;
		printf("Value checked at index [%d] = [%d]\n",
				(int)tmp->index, tmp->n);
	}

	if (tmp->express == NULL)
	{
		list = tmp;
		while (tmp->next != NULL)
			tmp = tmp->next;
	}

	printf("Value found between indexes [%d] and [%d]\n",
			(int)list->index, (int)tmp->index);

	/* Perform linear search */
	while (list != NULL && list != tmp->next)
	{
		printf("Value checked at index [%d] = [%d]\n",
				(int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
