int	divide(int *arr, int s, int e, int (*compare) (int, int))
{
	int	lt, rt, pivot, temp;

	pivot = arr[s];
	lt = s + 1;
	rt = e;
	while (lt <= rt)
	{
		while (compare(arr[lt], pivot) <= 0 && lt <= e)
			lt++;
		while (compare(arr[rt], pivot) >= 0 && rt >= s + 1)
			rt--;
		if (lt <= rt)
		{
			temp = arr[rt];
			arr[rt] = arr[lt];
			arr[lt] = temp;
		}
	}
	temp = arr[rt];
	arr[rt] = arr[s];
	arr[s] = temp;
	return (rt);
}

void	quick_sort(int *arr, int s, int e, int (*compare) (int, int))
{
	int	pivot;

	if (s >= e)
		return;
	pivot = divide(arr, s, e, compare);
	quick_sort(arr, s, pivot - 1, compare);
	quick_sort(arr, pivot + 1, e, compare);
}
