#include "Deque.h"

void	radix_sort(int *arr, int n, int mode)
{
	int		i, j, k, mask, temp, idx;
	int 	count[2];
	Deque	*deques[2];

	mask = 1;
	deques[0] = create_deque(n);
	deques[1] = create_deque(n);
	// 2진수로 뒤에서 첫 번째 digit 비교
	for (i = 0; i < n; i++)
		add_front(deques[arr[i] & mask], arr[i]);
	// 큐에서 값을 빼낼 때 원래 있었던 갯수 만큼만 빼기 위한 count 변수 설정
	for (i = 0; i < 2; i++)
		count[i] = deques[i]->count;
	for (i = 0; i < 31; i++)
	{
		// 다음 digit 비교를 위한 shift 연산
		mask <<= 1;
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < count[j]; k++)
			{
				temp = remove_rear(deques[j]);
				add_front(deques[!!(temp & mask)], temp);
			}
		}
		for (j = 0; j < 2; j++)
			count[j] = deques[j]->count;
	}
	idx = 0;
	if (mode == 0)
		for (i = 1; i >= 0; i--)
			for (j = 0; j < count[i]; j++)
				arr[idx++] = remove_rear(deques[i]);
	else
		for (i = 0; i < 2; i++)
			for (j = 0; j < count[i]; j++)
				arr[idx++] = remove_front(deques[i]);
	for (i = 0; i < 2; i++)
		free(deques[i]);
}
