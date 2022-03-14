#include "Deque.h"

void	radix_sort(int *arr, int n, int mode)
{
	int		mask, temp, idx;
	int 	count[2];
	Deque	*deques[2];

	mask = 1;
	deques[0] = create_deque(n);
	deques[1] = create_deque(n);
	// 2진수로 뒤에서 첫 번째 digit 비교
	for (int i = 0; i < n; i++)
		add_front(deques[!!(arr[i] & mask)], arr[i]);
	for (int i = 0; i < 2; i++)
		count[i] = deques[i]->count;
	// 2진수로 남은 30개 digit 비교
	for (int i = 0; i < 31; i++)
	{
		mask <<= 1;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < count[j]; k++)
			{
				temp = remove_rear(deques[j]);
				add_front(deques[!!(temp & mask)], temp);
			}
		}
		for (int j = 0; j < 2; j++)
			count[j] = deques[j]->count;
	}
	idx = 0;
//	오름차순 정렬인 경우
	if (mode == 0)
	{
		for (int i = 0; i < count[1]; i++) {
			arr[idx] = remove_rear(deques[1]);
			idx++;
		}
		for (int i = 0; i < count[0]; i++) {
			arr[idx] = remove_rear(deques[0]);
			idx++;
		}
	}
	else
	{
		for (int i = 0; i < count[0]; i++) {
			arr[idx] = remove_front(deques[0]);
			idx++;
		}
		for (int i = 0; i < count[1]; i++) {
			arr[idx] = remove_front(deques[1]);
			idx++;
		}
	}
}
