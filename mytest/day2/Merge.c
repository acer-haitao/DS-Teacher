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
void Merge(linknode *Ha,linknode *Hb);

int main(int argc, const char *argv[])
{
	linknode * Ha = NULL,*Hb = NULL;

	if((Ha= list_create()) == NULL)
	{
		printf("create list failed\n");
		return -1;
	}
	if((Hb= list_create()) == NULL)
	{
		printf("create list failed\n");
		return -1;
	}

	head_insert(Ha,9);
	head_insert(Ha,6);
	head_insert(Ha,3);
	head_insert(Ha,2);

	head_insert(Hb,10);
	head_insert(Hb,8);
	head_insert(Hb,7);
	head_insert(Hb,6);
	head_insert(Hb,1);

	show(Ha);
	show(Hb);
	Merge(Ha,Hb);
	show(Ha);

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
void show(linknode *H)
{
	while(H->next != NULL)
	{
		printf("%d ",H->next->data);
		H = H->next;  //每次H向后移动一个位置
	}
	putchar(10);
}
	
void Merge(linknode *Ha,linknode *Hb)
{
	linknode *p = Ha->next,*q = Hb->next,*r = Ha;
	free(Hb);
	while(p && q)
	{
		if(p->data <= q->data)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = q;
			q = q->next;
		}
	}
	if(p == NULL)
		p = q;
	r->next = p;

}
