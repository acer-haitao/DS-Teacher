#include <stdio.h>
#include <stdlib.h>

#define N 64

#if 0
//每个数据元素的定义
struct BOOK{
	int num;
	char name[32];
	float price;
};
#endif

typedef int datatype;

//数据模型结构体
typedef struct{
//	struct BOOK data[N];
	datatype data[N];
	int last;
}sqlist;

//创建线性标
sqlist * list_create();
//简单的插入
int list_insert(sqlist * L,datatype value);
//遍历线性表
void show(sqlist *L);
//指定插入位置
int list_insert1(sqlist * L,datatype value,int pos);
//指定位置的删除
int list_delete(sqlist * L,int pos);
//修改制定的值
int replace(sqlist * L,datatype value,int pos);
//查找到相应的数值（key）返回 1  没找到返回 0
int list_search(sqlist *L,datatype value);




int main(int argc, const char *argv[])
{
	sqlist * L = NULL;
	
	if((L = list_create()) == NULL)
	{
		printf("create list failed\n");
		return -1;
	}

	list_insert(L,1);
	list_insert(L,2);
	list_insert(L,3);
	list_insert(L,4);
	show(L);
	list_insert1(L,10,2);
	show(L);
	list_delete(L,3);
	show(L);
	replace(L,20,1);
	show(L);
	printf("search : %d\n",list_search(L,99));


	return 0;
}

sqlist * list_create()
{
	sqlist * L = NULL;

	L = (sqlist *)malloc(sizeof(sqlist));

	if(L == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}

	L->last = -1;
	
	return L;
}
int list_insert(sqlist * L,datatype value)
{
	if(L->last == N - 1)
	{
		printf("list is full\n");
		return -1;
	}

	L->data[L->last + 1] = value;
	L->last++;  //last永远为最后一个元素的下标

	return 0;
}

int list_insert1(sqlist * L,datatype value,int pos)
{
	int i;
	
	if(L->last == N - 1)
	{
		printf("list is full\n");
		return -1;
	}
	
	if(pos < 0 || pos > L->last + 1)
	{
		printf("pos is error\n");
		return -1;
	}


	for(i = L->last;i >= pos;i--)
	{
		L->data[i + 1] = L->data[i];
	}
	L->data[pos] = value;

	L->last++;

	return 0;
}
void show(sqlist *L)
{
	int i = 0;
	for(;i <= L->last;i++)
	{
		printf("%d ",L->data[i]);
	}
	putchar(10);
}
int list_delete(sqlist * L,int pos)
{
	int i;
	if(L->last == -1)
	{
		printf("list is emtpy\n");
		return -1;
	}
	if(pos < 0 || pos > L->last )
	{
		printf("pos is error\n");
		return -1;
	}
	
	for(i = pos;i < L->last;i++)
	{
		L->data[i] = L->data[i + 1];
	}
	L->last--;

	return 0;
}

int replace(sqlist * L,datatype value,int pos)
{
	if(pos < 0 || pos >= L->last )
	{
		printf("pos is error\n");
		return -1;
	}

	L->data[pos] = value;

	return 0;
}

int list_search(sqlist *L,datatype value)
{
	int i = 0;
	for(;i <= L->last;i++)
	{
		if(L->data[i] == value)
			return 1;
	}

	return 0;
}
