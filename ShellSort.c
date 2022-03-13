void shell_sort(int *arr, int n, int (*compare)(int, int))
{
	int	i, j, gap, comp;

	gap = 1;
	while (gap < n)
		gap = gap * 3 + 1;
	gap /= 3;
	while (gap > 0)
	{
		for (i = gap; i < n; i++) {
			j = i - gap;
			comp = arr[i];
			while (j >= 0 && compare(comp, arr[j]) < 0)
			{
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = comp;
		}
		gap /= 3;
	}
}
