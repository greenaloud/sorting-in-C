#include "Deque.h"
#include <stdio.h>

Deque	*create_deque(int size)
{
	Deque	*deque;

	deque = malloc(sizeof (Deque));
	if (deque == NULL)
		return (NULL);
	deque->arr = malloc(sizeof (element) * (size + 1));
	if (deque->arr == NULL)
	{
		free(deque);
		return (NULL);
	}
	deque->size = size + 1;
	deque->front = 0;
	deque->rear = 0;
	deque->count = 0;
	return (deque);
}

void	add_front(Deque *deque, element data)
{
	deque->arr[deque->front] = data;
	deque->front = (deque->front - 1 + deque->size) % (deque->size);
	(deque->count)++;
}

void	add_rear(Deque *deque, element data)
{
	deque->rear = (deque->rear + 1) % (deque->size);
	deque->arr[deque->rear] = data;
	(deque->count)++;
}

element	remove_front(Deque *deque)
{
	deque->front = (deque->front + 1) % (deque->size);
	(deque->count)--;
	return (deque->arr[deque->front]);
}

element remove_rear(Deque *deque)
{
	element	result;

	result = deque->arr[deque->rear];
	deque->rear = (deque->rear - 1 + deque->size) % (deque->size);
	(deque->count)--;
	return (result);
}

int	is_deque_empty(Deque *deque)
{
	return (deque->front == deque->rear);
}

//int	pop(t_stack *pstack, int pos)
//{
//	int	 ret;
//
//	if (pos == TOP)
//	{
//		pstack->top = (pstack->top + 1) % (pstack->size);
//		return (pstack->arr[pstack->top]);
//	}
//	else
//	{
//		ret = pstack->arr[pstack->bot];
//		pstack->bot = (pstack->bot - 1 + pstack->size) % (pstack->size);
//		return (ret);
//	}
//}

//void	push(t_stack *pstack, int pos, int data)
//{
//	if (pos == TOP)
//	{
//		pstack->arr[pstack->top] = data;
//		pstack->top = (pstack->top - 1 + pstack->size) % (pstack->size);
//	}
//	else
//	{
//		pstack->bot = (pstack->bot + 1) % (pstack->size);
//		pstack->arr[pstack->bot] = data;
//	}
//}