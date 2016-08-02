#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

struct node{
	datatype data;
	struct node * prior;//指向上一个节点
	struct node * next;
};

typedef struct node linknode;

linknode * list_create();
int list_insert(linknode * H,datatype value);
int list_delete(linknode *H);

void show(linknode *H);

int main(int argc, const char *argv[])
{
	linknode * H = NULL;
	int i;

	if((H= list_create()) == NULL)
	{
		printf("create list failed\n");
		return -1;
	}

	for(i = 8;i >= 1;i--)
		list_insert(H,i);


	show(H);

	list_delete(H);
	show(H);

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
	
	H->data = 0;
	H->prior = H->next = H;

	return H;
}
int list_insert(linknode * H,datatype value)
{
	linknode *p = NULL;
	if((p = malloc(sizeof(linknode))) == NULL)
	{
		printf("malloc node failed\n");
		return -1;
	}
	
	p->data = value;

	//插入过程
	p->next = H->next;
	H->next->prior = p;
	p->prior = H;
	H->next = p;


	return 0;
}
void show(linknode *H)
{
	linknode *p = H;
	while(p->prior != H)
	{
		printf("%d ",p->data);
		p = p->prior;  //每次H向后移动一个位置
	}
	printf("%d ",p->data);

	putchar(10);
}
int list_delete(linknode *H)
{
	linknode *p = H->next;

	H->next = p->next;
	p->next->prior = H;

	free(p);

	return 0;
}

	


