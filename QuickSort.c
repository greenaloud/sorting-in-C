int	divide(int *arr, int s, int e)
{
	int	lt, rt, pivot, temp;

	pivot = arr[s];
	lt = s + 1;
	rt = e;
	while (lt <= rt)
	{
		while (arr[lt] <= pivot && lt <= e)
			lt++;
		while (arr[rt] >= pivot && rt >= s + 1)
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

void	quick_sort(int *arr, int s, int e)
{
	int	pivot;

	if (s >= e)
		return;
	pivot = divide(arr, s, e);
	quick_sort(arr, s, pivot - 1);
	quick_sort(arr, pivot + 1, e);
}
