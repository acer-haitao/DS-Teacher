#ifndef _BITREE_
#define _BITREE_

typedef char datatype_t;

typedef struct node_t
{
	datatype_t data;
	struct node_t * left;  //分别指向二叉树的左孩子和右孩子
	struct node_t * right;
}bitree;

bitree * bitree_create();

void preorder(bitree * r);
void inorder(bitree * r);
void postorder(bitree * r);
void noorder(bitree * r);

#endif
