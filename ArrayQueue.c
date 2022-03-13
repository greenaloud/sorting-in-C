#include "ArrayQueue.h"

ArrayQueue	*createArrayQueue(int maxElementCount)
{
	ArrayQueue		*pQueue;
	ArrayQueueNode	*pNode;

	if (maxElementCount < 1)
		return (NULL);
	pQueue = malloc(sizeof(ArrayQueue));
	if (!pQueue)
		return (NULL);
	pNode = malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!pNode)
	{
		free(pQueue);
		return (NULL);
	}
	pQueue->maxElementCount = maxElementCount;
	pQueue->currentElementCount = 0;
	pQueue->pElement = pNode;
	pQueue->front = -1;
	pQueue->rear = -1;
	return (pQueue);
}

int	enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element)
{
	ArrayQueueNode	*pNewNode;
	int				i;

	if (!pQueue)
		return (FALSE);
	if (isArrayQueueFull(pQueue))
	{
		pNewNode = malloc(pQueue->maxElementCount * 2);
		if (!pNewNode)
			return (FALSE);
		pQueue->maxElementCount *= 2;
		printf("Reallocate memory: maxElementCount = %d\n", pQueue->maxElementCount);
		pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
		for (i = 0; pQueue->front != pQueue->rear; i++)
		{
			pNewNode[i] = pQueue->pElement[pQueue->front];
			pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
		}
		pNewNode[i] = pQueue->pElement[pQueue->front];
		free(pQueue->pElement);
		pQueue->pElement = pNewNode;
		pQueue->front = -1;
		pQueue->rear = pQueue->currentElementCount - 1;
	}
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->pElement[pQueue->rear] = element;
	pQueue->currentElementCount++;
	return (TRUE);
}

// malloc??
ArrayQueueNode dequeueAQ(ArrayQueue *pQueue)
{
	int result;

	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	result = (pQueue->pElement[pQueue->front]);
	pQueue->currentElementCount--;
	return (result);
}

ArrayQueueNode	*peekAQ(ArrayQueue *pQueue)
{
	return (&pQueue->pElement[(pQueue->front + 1) % pQueue->maxElementCount]);
}

void	deleteArrayQueue(ArrayQueue *pQueue)
{
	free(pQueue->pElement);
	free(pQueue);
}
int	isArrayQueueFull(ArrayQueue *pQueue)
{
	if (pQueue->maxElementCount == pQueue->currentElementCount)
		return (TRUE);
	return (FALSE);
}

int	isArrayQueueEmpty(ArrayQueue *pQueue)
{
	if (pQueue->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

void	displayArrayQueue(ArrayQueue *pQueue)
{
	int	i;

	printf("[");
	if (isArrayQueueEmpty(pQueue))
		printf("]");
	else
	{
		i = (pQueue->front + 1) % pQueue->maxElementCount;
		while (i != pQueue->rear)
		{
			printf("%c, ", pQueue->pElement[i]);
			i = (i + 1) % pQueue->maxElementCount;
		}
		printf("%c]", pQueue->pElement[i]);
	}
}
