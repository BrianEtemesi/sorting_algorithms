#include "sort.h"

/**
 * bubble_sort - sorts an array
 * @array: array
 * @size: number of elements in an array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int swap_flag, temp = -1;

	for (i = 0; i < size; i++)
	{
		swap_flag = 0;
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				for (k = 0; k < size - 1; k++)
				{
					printf("%d, ", array[k]);
				}
				printf("%d\n", array[k]);
				swap_flag = 1;
			}
		}
		if (swap_flag == 0)
		{
			break;
		}
	}
}
