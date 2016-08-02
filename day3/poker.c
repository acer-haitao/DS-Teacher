#include <stdio.h>

#define N 64

typedef int datatype;

typedef struct {
	datatype index[N];  //存放原来的顺序号
	int front;
	int rear;
}game;

void poker(int *p,int num)
{
	int i,j = 1;  //j作为牌上的数字
	game queue;  //创建队列
	queue.front = 0;
	queue.rear = 13;   //假定牌已经在队列中

	for(i = 0;i < num;i++)
		queue.index[i] = i;   //0----12 共13 个数 为下标号

	while(queue.front < queue.rear)  //队列不为空
		                  //这里没有用循环队列，因为64个位置足够
	{
		int tmp;  //用来操作p 还原原来的值

		//取牌到队尾
		queue.index[queue.rear++] = queue.index[queue.front];
		queue.front++;

		//将牌取出
		tmp = queue.index[queue.front];
		p[tmp] = j++;
		queue.front++;
	}
	
}

int main(int argc, const char *argv[])
{
	int i,num = 13;
	int a[13] = {0}; //a[0]为最上边的牌，数组用来存原来的牌的值
	
	poker(a,num);  //函数实现过程

	printf("原顺序为：\n");
	for(i = 0;i < num;i++)//打印原来顺序
		printf("%d ",a[i]);
	putchar(10);

	return 0;
}
