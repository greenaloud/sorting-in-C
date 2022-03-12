#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

static void	check_sorted(int *arr, int n)
{
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			printf("Sort Failed\n");
			return;
		}
	}
	printf("This array is SORTED!!\n");
}

static void	fill_random_nums(int *arr, int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
		arr[i] = rand() % 10000;
}

int	main(void)
{
	int	len;
	int opt;
	int	loop;
	int	*arr;

	arr = NULL;
	loop = 1;
	while (loop)
	{
		printf("<0> Sort Checker\n<1> Make random array\n<2> Print Array\n<3> Bubble Sort\n<4> Selection Sort\n<5> Insertion Sort\n<6> Heap Sort\n<7> Merge Sort\n<8> Quick Sort\n<9> Radix Sort\n<10> EXIT\n\n");
		scanf("%d", &opt);
		switch (opt)
		{
			case 0:
				printf("======================\n");
				check_sorted(arr, len);
				printf("======================\n\n");
				break;
			case 1:
				printf("Input length of array\n");
				scanf("%d", &len);
				if (arr)
					free(arr);
				arr = malloc(sizeof *arr * len);
				fill_random_nums(arr, len);
				printf("======================\n");
				printf("Random Array Created!\n");
				printf("======================\n\n");
				break;
			case 2:
				printf("======================\n");
				for (int i = 0; i < len; i++)
					printf("[%d]: %3d\n", i, arr[i]);
				printf("======================\n\n");
				break;
			case 3:
				printf("======================\n");
				bubble_sort(arr, len);
				printf("Bubble Sort Completed\n");
				printf("======================\n\n");
				break;
			case 4:
				printf("======================\n");
				selection_sort(arr, len);
				printf("Selection Sort Completed\n");
				printf("======================\n\n");
				break;
			case 5:
				printf("======================\n");
				insertion_sort(arr, len);
				printf("Insertion Sort Completed\n");
				printf("======================\n\n");
				break;
			case 6:
				printf("======================\n");
				heap_sort(arr, len);
				printf("Heap Sort Completed\n");
				printf("======================\n\n");
				break;
			case 7:
				printf("======================\n");
				merge_sort(arr, 0, len - 1);
				printf("Merge Sort Completed\n");
				printf("======================\n\n");
				break;
			case 8:
				printf("======================\n");
				quick_sort(arr, 0, len - 1);
				printf("Quick Sort Completed\n");
				printf("======================\n\n");
				break;
			case 9:
				printf("======================\n");
				heap_sort(arr, len);
				printf("Radix Sort Completed\n");
				printf("======================\n\n");
				break;
			case 10:
				loop = 0;
				break;
			default:
				printf("Please Enter a Valid Option\n\n");
				break;
		}
	}
	if (arr)
		free(arr);
	return (0);
}
