void	insertion_sort(int *arr, int n, int (*compare) (int, int))
{
	int val;
	int i, j;

	for (i = 1; i < n; i++)
	{
		val = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (compare(arr[j], val) > 0)
				arr[j + 1] = arr[j];
			else
				break ;
		}
		arr[j + 1] = val;
	}
}
