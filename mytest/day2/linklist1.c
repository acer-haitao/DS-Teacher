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
	int i;
	linknode *r = H,*p = NULL;
	for(i = 1;i < k;i++)  //r指向待计数节点的上一个节点
		r = r->next;    
	while(r->next != r)
	{
		for(i = 0;i < m-2;i++)  //注意临界关系，从0开始要移动 m-1次 所以是m - 2
			r = r->next;
		p = r->next;
		r->next = p->next;  //删除结点

		printf("%d ",p->data);//打印出圈的数值
		free(p);

		r = r->next; // r指向下一个待计数结点
	}

	printf("%d\n",r->data);

	free(r);
}
