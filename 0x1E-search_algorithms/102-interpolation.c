#include "search_algos.h"
/**
 * interpolation_search - Searches for a value in a sorted array
 * of integers using Interpolation Search Algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The first index where value is located
*/

int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, low, hi;

	if (array == NULL)
		return (-1);

	for (low = 0, hi = size - 1; hi >= low;)
	{
		pos = low + (((double)(hi - low) /
					  (array[hi] - array[low])) *
					 (value - array[low]));
		if (pos < size)
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			break;
		}

		if (array[pos] == value)
			return (pos);
		if (array[pos] > value)
			low = pos + 1;
		else
			hi = pos - 1;
	}

	return (-1);
}
