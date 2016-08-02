#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

struct node{
	datatype data;
	struct node * next;
};

typedef struct node linknode;

linknode * list_create();
int head_insert(linknode * H,datatype value);

void show(linknode *H);

void joseph(linknode *H,int k,int m);


int main(int argc, const char *argv[])
{
	linknode * H = NULL;
	int i;

	if((H= list_create()) == NULL)
	{
		printf("create list failed\n");
		return -1;
	}

	for(i = 8;i > 1;i--)
		head_insert(H,i);


	show(H);

	joseph(H,3,4);

	return 0;
}

//单向循环链表
linknode * list_create()
{
	linknode * H = NULL;//头指针

	if((H = malloc(sizeof(linknode))) == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	
	H->data = 1;
	H->next = H;

	return H;
}
int head_insert(linknode * H,datatype value)
{
	linknode *p = NULL;
	if((p = malloc(sizeof(linknode))) == NULL)
	{
		printf("malloc node failed\n");
		return -1;
	}
	
	p->data = value;

	p->next = H->next; // 让p挂上H的下一个结点
	H->next = p; //H与原来的节点断开挂上p

	return 0;
}
void show(linknode *H)
{
	linknode *p = H;
	while(p->next != H)
	{
		printf("%d ",p->data);
		p = p->next;  //每次H向后移动一个位置
	}
	printf("%d ",p->data);

	putchar(10);
}
	

void joseph(linknode *H,int k,int m)
{
	
}
