#ifndef SORT_H
# define SORT_H

# define ASC	0
# define DES	1

void	bubble_sort(int *arr, int n, int (*compare) (int, int));
void	selection_sort(int *arr, int n, int (*compare) (int, int));
void	insertion_sort(int *arr, int n, int (*compare) (int, int));
void	heap_sort(int *arr, int n, int (*compare) (int, int));
void	merge_sort(int *arr, int s, int e, int (*compare) (int, int));
void	quick_sort(int *arr, int s, int e, int (*compare) (int, int));
void	shell_sort(int *arr, int n, int (*compare)(int, int));
void	radix_sort(int *arr, int n, int mode);

#endif