#include <stdlib.h>

static void	merge(int *arr, int s, int m, int e, int (*compare) (int, int))
{
	int	*left, *right;
	int	l_len, r_len, lt, rt, idx;

	l_len = m - s + 1;
	r_len = e - m;
	left = malloc(sizeof *left * l_len);
	right = malloc(sizeof *right * r_len);
	for (int i = 0; i < l_len; i++)
		left[i] = arr[s + i];
	for (int i = 0; i < r_len; i++)
		right[i] = arr[m + 1 + i];
	idx = lt = rt = 0;
	while (lt < l_len && rt < r_len)
	{
		if (compare(left[lt], right[rt]) <= 0)
			arr[s + idx++] = left[lt++];
		else
			arr[s + idx++] = right[rt++];
	}
	if (lt == l_len)
		while (rt < r_len)
			arr[s + idx++] = right[rt++];
	else
		while (lt < l_len)
			arr[s + idx++] = left[lt++];
	free(left);
	free(right);
}

void	merge_sort(int *arr, int s, int e, int (*compare) (int, int))
{
	int	mid;

	if (s >= e)
		return;
	mid = s + (e - s) / 2;
	merge_sort(arr, s, mid, compare);
	merge_sort(arr, mid + 1, e, compare);
	merge(arr, s, mid, e, compare);
}
