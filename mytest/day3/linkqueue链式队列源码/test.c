#include <stdio.h>
#include "linkqueue.h"

int main(int argc, const char *argv[])
{
	linkqueue *lq = NULL;

	if((lq = queue_create()) == NULL)
	{
		printf("create queue failed\n");
		return -1;
	}

	enqueue(lq,10);
	enqueue(lq,20);
	enqueue(lq,30);
	enqueue(lq,40);

	printf("dequeue : %d\n",dequeue(lq));

	return 0;
}
