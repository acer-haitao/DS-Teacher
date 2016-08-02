#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"
#include "linkqueue.h"

bitree * bitree_create()
{
	bitree * r = NULL;
	char ch;
	scanf("%c",&ch);

	if(ch == '#')
		return NULL;//给左右孩子空

	if((r = malloc(sizeof(bitree))) == NULL)
	{
		return r;
	}
	r->data = ch;

	r->left = bitree_create();//递归创建左子树
	r->right = bitree_create();//递归创建右子树

	return r;
}
//先根遍历
void preorder(bitree * r)
{
	if(r == NULL)
		return;

	printf("%c ",r->data);
	preorder(r->left);
	preorder(r->right);
}
void inorder(bitree * r)//中根
{
	if(r == NULL)
		return;
	inorder(r->left);
	printf("%c ",r->data);
	inorder(r->right);

}
void postorder(bitree * r)//后根
{
	if(r == NULL)
		return;
	postorder(r->left);
	postorder(r->right);
	printf("%c ",r->data);

}

void noorder(bitree * r)//层次（调用栈）
{
	linkqueue * lq = NULL;
	if((lq = queue_create()) == NULL)
	{
		printf("create queue failed\n");
		return;
	}
	
	printf("%c ",r->data);
	enqueue(lq,r);
	while(!queue_empty(lq))
	{
		r = dequeue(lq);
		if(r->left != NULL)
		{
			printf("%c ",r->left->data);
			enqueue(lq,r->left);
		}
		if(r->right != NULL)
		{
			printf("%c ",r->right->data);
			enqueue(lq,r->right);
		}
	}
	putchar(10);
}
