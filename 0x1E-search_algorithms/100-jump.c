#include "search_algos.h"
/**
 * jump_search - Searches for a value in a sorted array of integers
 * using the Jump Search Algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The first index where value is located
*/

int jump_search(int *array, size_t size, int value)
{
	size_t jump, i, step;

	if (array == NULL)
		return (-1);

	/* Compute jump step */
	step = sqrt(size);
	for (i = 0, jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%lu] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += step;
	}

	printf("Value found between indices[%lu] and [%lu]\n", i, jump);

	/* Perform linear search */
	for (; i < size && array[i] <= value; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
