#include "ArrayQueue.h"

void	radix_sort(int *arr, int n)
{
	int	divider;
	int count[10];
	ArrayQueue *qlist[10];
	ArrayQueueNode element;
	ArrayQueueNode *node;

	for (int i = 0; i < 10; i++)
		qlist[i] = createArrayQueue(n);
	for (int i = 0; i < n; i++) {
		enqueueAQ((qlist[arr[i] % 10]), arr[i]);
	}
	for (int i = 0; i < 10; i++)
		count[i] = qlist[i]->currentElementCount;
	divider = 1;
	for (int i = 0; i < 9; i++) {
		divider *= 10;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < count[j]; k++) {
				int temp = dequeueAQ(qlist[j]);
				enqueueAQ(qlist[(temp / divider) % 10], temp);
			}
		}
		for (int j = 0; j < 10; j++)
			count[j] = qlist[j]->currentElementCount;
	}
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < count[i]; j++) {
			arr[idx] = dequeueAQ(qlist[i]);
			idx++;
		}
	}
}
