#include "search_algos.h"
/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @low: The index to start printing from
 * @hi: The index at which to stop printing
*/
void print_array(int *array, size_t low, size_t hi)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= hi; i++)
		printf("%d%s", array[i], i == hi ? "\n" : ", ");
}

/**
 * binary_search_recursive - Recursively applies the Binary
 * Search Algorithm
 * @array: A pointer to the first element of the array to search in
 * @low: The first index of the array/subarray
 * @hi: The last index of the array/subarray
 * @value: The value to search for
 *
 * Return: The first index where value is located, or
 * -1 if value is not present or if array is NULL
*/
int binary_search_recursive(int *array, size_t low, size_t hi, int value)
{
	size_t mid;

	if (hi >= low)
	{
		mid = low + (hi - low) / 2;

		print_array(array, low, hi);
		/* If element is present at the middle */
		if (array[mid] == value && (mid == low ||
		array[mid - 1] != value))
			return (mid);
		/**
		 * If element is smaller than mid, it can
		 * can only be present in right subarray
		*/
		if (array[mid] >= value)
			return (binary_search_recursive(array, low, mid, value));
			/* Else the element can only be present in the right subarray */
		return (binary_search_recursive(array, mid + 1, hi, value));
	}
	/* We reach here if element is not in array */
	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of ints
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index of where value is located, or
 * -1 if value is not present in array or array is NULL
*/

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}
