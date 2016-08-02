#include <stdio.h>
#include <stdlib.h>
#include "sequeue.h"

int main(int argc, const char *argv[])
{
	sequeue *s = NULL;

	if((s = queue_create()) == NULL)
	{
		printf("create queue failed\n");
		return -1;
	}

	enqueue(s,10);
	enqueue(s,20);
	enqueue(s,30);
	enqueue(s,40);

	printf("dequeue: %d\n",dequeue(s));

	queue_clear(s);

	free(s);

	return 0;
}
