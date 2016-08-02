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
int head_delete(linknode *H);

int list_insert(linknode *H,datatype value,int pos);
//指定数据删除
int list_delete(linknode *H,datatype value);

int replace(linknode *H,datatype old,datatype new);
int search(linknode * H,datatype value);

void show(linknode *H);


int main(int argc, const char *argv[])
{
	linknode * H = NULL;

	if((H = list_create()) == NULL)
	{
		printf("create list failed\n");
		return -1;
	}
	head_insert(H,1);
	head_insert(H,2);
	head_insert(H,3);
	head_insert(H,4);
	head_insert(H,5);

	show(H);
	head_delete(H);
	show(H);
	list_insert(H,10,2);
	show(H);
	list_delete(H,20);
	show(H);
	replace(H,3,20);
	show(H);
	printf("search : %d\n",search(H,20));


	return 0;
}

linknode * list_create()
{
	linknode * H = NULL;//头指针

	if((H = malloc(sizeof(linknode))) == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	
	H->next = NULL;

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
int head_delete(linknode *H)
{
	linknode *p = H->next;

	if(H->next == NULL)
	{
		printf("list is empty\n");
		return -1;
	}
	
	H->next = p->next;
	free(p);

	return 0;
}
void show(linknode *H)
{
	while(H->next != NULL)
	{
		printf("%d ",H->next->data);
		H = H->next;  //每次H向后移动一个位置
	}
	putchar(10);
}

int list_insert(linknode *H,datatype value,int pos)
{
	linknode *p = H,*q = NULL;
	int i = 0;

	if((q = malloc(sizeof(linknode))) == NULL)
	{
		printf("malloc node failed\n");
		return -1;
	}
	q->data = value;
	
	while(i < pos && (p != NULL))
	{
		p = p->next;
		i++;
	}

	if(p == NULL)
	{
		printf("pos is error\n");
		return -1;
	}

	q->next = p->next;
	p->next = q;

	return 0;
}
int list_delete(linknode *H,datatype value)
{
	linknode *p = H,*q = NULL;

	while(p->next != NULL)
	{
		if(p->next->data != value)
		{
			p = p->next;
		}
		else
		{
			q = p->next;
			p->next = q->next;
			free(q);
			return 0;
		}
	}

	if(p->next == NULL)
	{
		printf("做不到啊！\n");
		return -1;
	}
}
int replace(linknode *H,datatype old,datatype new)
{
	while(H->next != NULL)
	{
		if(H->next->data != old)
		{
			H = H->next;
		}
		else
		{
			H->next->data = new;
			return 0;
		}
	}

	printf("No old value\n");
	return -1;
}

int search(linknode * H,datatype value)
{
	int i = 0;
	while(H->next != NULL)
	{
		if(H->next->data != value)
		{
			H = H->next;
			i++;
		}
		else
		{
			return i;
		}
	}

	printf("No  search\n");
	return -1;
}
