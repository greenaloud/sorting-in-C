#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

static void	check_sorted(int *arr, int n, int order)
{
	if (order == ASC)
	{
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] > arr[i]) {
				printf("Sort Failed\n");
				return;
			}
		}
	}
	else if (order == DES)
	{
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] < arr[i]) {
				printf("Sort Failed\n");
				return;
			}
		}
	}
	printf("Successfully SORTED in %s Order!!\n", order == ASC ? "Ascending" : "Descending");
}

static void	fill_random_nums(int *arr, int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
		arr[i] = rand() - 1000000000;
}

int asc(int a, int b)
{
	return (a - b);
}

int des(int a, int b)
{
	return (b - a);
}

int	main(void)
{
	int	len;
	int opt;
	int	loop;
	int order;
	int	*arr;

	arr = NULL;
	loop = 1;
	while (loop)
	{
		printf("<0> Sort Checker\n<1> Make random array\n<2> Print Array\n<3> Bubble Sort\n<4> Selection Sort\n<5> Insertion Sort\n<6> Heap Sort\n<7> Merge Sort\n<8> Quick Sort\n<9> Shell Sort\n<10> Radix Sort\n<11> EXIT\n\n");
		scanf("%d", &opt);
		switch (opt)
		{
			case 0:
				printf("============================================\n");
				check_sorted(arr, len, order);
				printf("============================================\n\n");
				break;
			case 1:
				printf("Input length of array\n");
				scanf("%d", &len);
				if (arr)
					free(arr);
				arr = malloc(sizeof *arr * len);
				fill_random_nums(arr, len);
				printf("============================================\n");
				printf("Random Array Created!\n");
				printf("============================================\n\n");
				break;
			case 2:
				printf("============================================\n");
				for (int i = 0; i < len; i++)
					printf("[%d]: %3d\n", i, arr[i]);
				printf("============================================\n\n");
				break;
			case 3:
				printf("============================================\n");
				printf("<0> Ascending Order\n<1> Descending Order\n");
				scanf("%d", &opt);
				if (opt == 0)
				{
					order = ASC;
					bubble_sort(arr, len, asc);
					printf("Bubble Sort Completed\n");
				}
				else if (opt == 1)
				{
					order = DES;
					bubble_sort(arr, len, des);
					printf("Bubble Sort Completed\n");
				}
				else
					printf("Enter Valid Option\n");
				printf("============================================\n\n");
				break;
			case 4:
				printf("============================================\n");
				printf("<0> Ascending Order\n<1> Descending Order\n");
				scanf("%d", &opt);
				if (opt == 0)
				{
					order = ASC;
					selection_sort(arr, len, asc);
					printf("Selection Sort Completed\n");
				}
				else if (opt == 1)
				{
					order = DES;
					selection_sort(arr, len, des);
					printf("Selection Sort Completed\n");
				}
				else
					printf("Enter Valid Option\n");
				printf("============================================\n\n");
				break;
			case 5:
				printf("============================================\n");
				printf("<0> Ascending Order\n<1> Descending Order\n");
				scanf("%d", &opt);
				if (opt == 0)
				{
					order = ASC;
					insertion_sort(arr, len, asc);
					printf("Insertion Sort Completed\n");
				}
				else if (opt == 1)
				{
					order = DES;
					insertion_sort(arr, len, des);
					printf("Insertion Sort Completed\n");
				}
				else
					printf("Enter Valid Option\n");
				printf("============================================\n\n");
				break;
			case 6:
				printf("============================================\n");
				printf("<0> Ascending Order\n<1> Descending Order\n");
				scanf("%d", &opt);
				if (opt == 0)
				{
					order = ASC;
					heap_sort(arr, len, asc);
					printf("Heap Sort Completed\n");
				}
				else if (opt == 1)
				{
					order = DES;
					heap_sort(arr, len, des);
					printf("Heap Sort Completed\n");
				}
				else
					printf("Enter Valid Option\n");
				printf("============================================\n\n");
				break;
			case 7:
				printf("============================================\n");
				printf("<0> Ascending Order\n<1> Descending Order\n");
				scanf("%d", &opt);
				if (opt == 0)
				{
					order = ASC;
					merge_sort(arr, 0, len - 1, asc);
					printf("Merge Sort Completed\n");
				}
				else if (opt == 1)
				{
					order = DES;
					merge_sort(arr, 0, len - 1, des);
					printf("Merge Sort Completed\n");
				}
				else
					printf("Enter Valid Option\n");
				printf("============================================\n\n");
				break;
			case 8:
				printf("============================================\n");
				printf("<0> Ascending Order\n<1> Descending Order\n");
				scanf("%d", &opt);
				if (opt == 0)
				{
					order = ASC;
					quick_sort(arr, 0, len - 1, asc);
					printf("Quick Sort Completed\n");
				}
				else if (opt == 1)
				{
					order = DES;
					quick_sort(arr, 0, len - 1, des);
					printf("Quick Sort Completed\n");
				}
				else
					printf("Enter Valid Option\n");
				printf("============================================\n\n");
				break;
			case 9:
				printf("============================================\n");
				printf("<0> Ascending Order\n<1> Descending Order\n");
				scanf("%d", &opt);
				if (opt == 0)
				{
					order = ASC;
					shell_sort(arr, len, asc);
					printf("Shell Sort Completed\n");
				}
				else if (opt == 1)
				{
					order = DES;
					shell_sort(arr, len, des);
					printf("Shell Sort Completed\n");
				}
				else
					printf("Enter Valid Option\n");
				printf("============================================\n\n");
				break;
			case 10:
				printf("============================================\n");
				printf("<0> Ascending Order\n<1> Descending Order\n");
				scanf("%d", &opt);
				if (opt == 0)
				{
					order = ASC;
					radix_sort(arr, len, 0);
					printf("Radix Sort Completed\n");
				}
				else if (opt == 1)
				{
					order = DES;
					radix_sort(arr, len, 1);
					printf("Radix Sort Completed\n");
				}
				else
					printf("Enter Valid Option\n");
				printf("============================================\n\n");
				break;
			case 11:
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
