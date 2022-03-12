void	insertion_sort(int *arr, int n)
{
	int val;
	int i, j;

	for (i = 1; i < n; i++)
	{
		val = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > val)
				arr[j + 1] = arr[j];
			else
				break ;
		}
		arr[j + 1] = val;
	}
}
