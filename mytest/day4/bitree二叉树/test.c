#include <stdio.h>
#include "bitree.h"

int main(int argc, const char *argv[])
{
	bitree * r = NULL;

	if((r = bitree_create()) == NULL)
	{
		printf("create bitree failed\n");
		return -1;
	}
	preorder(r);
	putchar(10);

	inorder(r);
	putchar(10);

	postorder(r);
	putchar(10);

	noorder(r);

	return 0;
}
