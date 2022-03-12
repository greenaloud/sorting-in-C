#include "Heap.h"

void	heap_sort(int *arr, int n)
{
	t_heap	*heap;

	heap = create_heap(15);
	for (int i = 0; i < n; i++) {
		push(heap, arr[i]);
	}
	for (int i = 0; i < n; i++) {
		arr[i] = pop(heap);
	}
	delete_heap(heap);
}