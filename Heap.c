#include "Heap.h"

t_heap	*create_heap(int capacity, int (*comp) (int, int))
{
	t_heap	*heap;

	if (capacity < 1)
		return (NULL);
	heap = malloc(sizeof (t_heap));
	if (heap == NULL)
		return (NULL);
	// 배열의 0번째 인덱스는 사용하지 않기 위해서 + 1 을 해준다.
	heap->arr = malloc(sizeof (element) * (capacity + 1));
	if (heap->arr == NULL)
	{
		free(heap);
		return (NULL);
	}
	heap->count = 0;
	heap->capacity = capacity;
	heap->comp = comp;
	return (heap);
}

static int	resize(t_heap *pheap)
{
	element	*new_arr;

	new_arr = malloc(sizeof (element) * (((pheap->capacity) - 1) * 2 + 1));
	if (new_arr == NULL)
		return (FALSE);
	for (int i = 1; i <= pheap->capacity; i++)
		new_arr[i] = (pheap->arr)[i];
	pheap->capacity *= 2;
	free(pheap->arr);
	pheap->arr = new_arr;
	return (TRUE);
}

void	push(t_heap *pheap, element data)
{
	int		idx;

	if (is_full(pheap))
	{
		if (resize(pheap) == FALSE)
			return ;
	}
	idx = ++(pheap->count);
	while (idx > 1 && pheap->comp(data, (pheap->arr)[idx / 2]) < 0)
	{
		(pheap->arr)[idx] = (pheap->arr)[idx / 2];
		idx /= 2;
	}
	(pheap->arr)[idx] = data;
}

element pop(t_heap *pheap)
{
	element	root, comp;
	int		parent, child;

	root = (pheap->arr)[1];
	comp = (pheap->arr)[(pheap->count)--];
	parent = 1;
	child = 2;
	while (child <= pheap->count)
	{
		if (pheap->comp((pheap->arr)[child], (pheap->arr)[child + 1]) > 0)
			child++;
		if (pheap->comp(comp, (pheap->arr)[child]) <= 0)
			break;
		(pheap->arr)[parent] = (pheap->arr)[child];
		parent = child;
		child *= 2;
	}
	(pheap->arr)[parent] = comp;
	return root;
}

int		is_empty(t_heap *pheap)
{
	return (pheap->count == 0);
}

int		is_full(t_heap *pheap)
{
	return (pheap->count == pheap->capacity);
}

void	delete_heap(t_heap *pheap)
{
	if (pheap == NULL)
		return ;
	free(pheap->arr);
}