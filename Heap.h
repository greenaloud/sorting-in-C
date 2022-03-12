#ifndef HEAP_H
# define HEAP_H

# include <stdlib.h>
# include <stdio.h>

typedef int	element;

typedef struct s_heap
{
	element	*arr;
	int		count;
	int		capacity;
} t_heap;

t_heap	*create_heap(int capacity);
void	push(t_heap *pheap, element data);
element pop(t_heap *pheap);
int		is_empty(t_heap *pheap);
int		is_full(t_heap *pheap);
void	delete_heap(t_heap *pheap);

# define TRUE	1
# define FALSE	0

#endif