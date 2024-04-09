#include "search_algos.h"
/**
 * jump_list - Searches for a value in a sorted list of integers
 * using the Jump Search Algorithm
 * @list: A pointer to the head of the list to search in
 * @size: The number of nodes in list
 * @value: The value to search for
 *
 * Return: A pointer to the the first node value is located, or
 * NULL if value is not present in head or if head is NULL
*/

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t index, j, jump;
	listint_t *prev;

	if (list == NULL || size == 0)
		return (NULL);
	/* Compute jump step */
	jump = (size_t)sqrt((double)size);
	index = 0;
	j = 0;
	do {
		prev = list;
		j++;
		index = j * jump;

		while (list->next && list->index < index)
			list = list->next;
		if (list->next == NULL && index != list->index)
			index = list->index;
		printf("Value checkec at index [%d] = [%d]\n", (int)index, list->n);
	} while (index < size && list->next && list->n < value);

	printf("Value found between indexes[%d] and [%d]\n",
			(int)prev->index, (int)list->index);
	/* Perform linear search */
	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index[%d] = [%d]\n",
				(int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
