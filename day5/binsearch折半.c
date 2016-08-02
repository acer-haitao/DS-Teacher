#include <stdio.h>

int binsearch(int *a,int n,int value)
{
	int low = a[0];
	int hight = a[n - 1];
	int mid = 0;

	while(low <= hight)
	{
		mid = (low + hight) / 2;
		if(value < mid)
			hight = mid - 1;
		else if(value > mid)
			low = mid + 1;
		else
			return 1;  //表示找到
	}

	return 0; //表示没找到
}

int main(int argc, const char *argv[])
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int n = 0;
	scanf("%d",&n);

	printf("n = %d\n",n);

	printf("%d\n",binsearch(a,10,n));

	return 0;
}
