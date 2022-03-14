#ifndef DEQUE_H
# define DEQUE_H

# include <stdlib.h>

typedef int	element;

typedef struct _Deque
{
	element	*arr;
	int		size;
	int 	count;
	int		front;
	int		rear;
} Deque;

Deque	*create_deque(int size);
void	add_front(Deque *deque, element data);
void	add_rear(Deque *deque, element data);
element remove_front(Deque *deque);
element remove_rear(Deque *deque);
int		is_deque_empty(Deque *deque);

#endif
