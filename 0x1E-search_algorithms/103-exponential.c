#include "search_algos.h"
/**
 * _binary_search - Searches for a value in a sorted array of
 * integers using the Binary Search Algorithm
 * @array: A ppointer to the first element of the array ro search in
 * @hi: The first index in the array to search
 * @low: The last index in the array to search
 * @value: The value to search for
 *
 * Return: The first index where value is located, or
 * -1 if value is not present in array or if array is NULL
*/
int _binary_search(int *array, size_t low, size_t hi, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (hi >= low)
	{
		printf("Searching in array: ");
		for (i = low; i < hi; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = low + (hi - low) / 2;
		if (array[i] == value)
			return (i);

		/**
		 * If element is smaller than mid, then it can only
		be present in left subarray
		*/
		if (array[i] > value)
			hi = i - 1;
		else
			low = i + 1;
	}

	/**
	 * We reach here if when the element is not present in the array
	 */
	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of
 * integers using the Exponential Search Algorithm
 * @array: The number of elements of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The first index where value is located, or
 * -1 if value is not present in array or is NULL
*/

int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, hi;

	if (array == NULL)
		return (-1);

	/* Find range for binary search */
	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	hi = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, hi);
	return (_binary_search(array, i / 2, hi, value));
}
