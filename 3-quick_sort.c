#include "sort.h"
/**
 * lomotu_partition - lomotu partition scheme
 * @array: array of numbers
 * @low: first index of the array
 * @high: last index of the array
 * @size: size of the array
 * Return: position of the pivot in the array
 */

int lomotu_partition(int *array, int low, int high, size_t size)
{
	int pi = low, pivot = array[high], i = low, tmp;


	for (; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			tmp = array[pi];
			array[pi] = array[i];
			array[i] = tmp;
			if (i != pi)
			{
				print_array(array, size);
			}
			pi++;
		}
	}
	tmp = array[pi];
	array[pi] = array[high];
	array[high] = tmp;
	if (i != pi)
	{
		print_array(array, size);
	}
	return (pi);
}

/**
 * quick_sort_rec - recursive call to partition function
 * @array: array of numbers
 * @low: first index of the array
 * @high: last index of the array
 * @size: size of the array
 * Return: nothing
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot = 0;

	if (low < high)
	{
		pivot = lomotu_partition(array, low, high, size);
		quick_sort_rec(array, low, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}
