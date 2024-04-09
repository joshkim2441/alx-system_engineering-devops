#include "search_algos.h"
/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: The number of elements in array
*/
void print_array(const int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * binary_search - Searches for a vlaue in a sorted array of integers
 * using the Binary Search Algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The index where value is stored, or
 * -1 if value is not present
*/

int binary_search(int *array, size_t size, int value)
{
	size_t low, mid, hi;

	if (!array)
		return (-1);

	for (low = 0, hi = size - 1; hi >= low;)
	{
		print_array(array + low, hi - low + 1);
		mid = low + (hi - low) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
			hi = mid - 1;
		else
			low = mid + 1;
	}

	return (-1);
}
