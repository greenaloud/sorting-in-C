void	selection_sort(int *arr, int n, int (*compare) (int, int))
{
	int	temp;
	int	min_idx;

	for (int i = 0; i < n - 1; i++) {
		min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (compare(arr[j], arr[min_idx]) < 0) {
				min_idx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}
