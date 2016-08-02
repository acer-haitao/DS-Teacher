#include <stdio.h>
#include "linkstack.h"

int main(int argc, const char *argv[])
{
	linkstack *s = NULL;

	if((s = stack_create()) == NULL)
	{
		printf("create failed\n");
		return -1;
	}

	push(s,10);
	push(s,20);
	push(s,30);
	push(s,40);

	printf("pop : %d\n",pop(s));

	stack_clear(s);

	return 0;
}


