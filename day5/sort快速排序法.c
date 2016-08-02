#include <stdio.h>

int partition(int * a, int i, int j);
void sort(int *a, int i, int j);

int main()
{
	int a[] = {1, 19, 21, 5, 21, 16, 28, 9}, i, n;

	n = sizeof(a) / sizeof(int);

	sort(a, 0, n-1);//sort(a, 10, 0) //从第0位开始 n-1最后一个数的下标

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
		
	return 0;
}

void sort(int *a, int i, int j)
{
	int t;

	if (i >= j)
		return;

	t = partition(a, i, j);
	sort(a, i, t-1);
	sort(a, t+1, j);
}

int partition(int * a, int i, int j)
{
	int key = a[i];

	while (i < j)//i==j
	{
		while (i < j && a[j] >= key)
			j--;
		a[i] = a[j];

		while (i < j && a[i] <= key)
			i++;
		a[j] = a[i];
	}

	a[i] = key;
	return i;
}
