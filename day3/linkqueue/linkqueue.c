#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

linkqueue * queue_create()
{
	linkqueue * lq = NULL;
	linknode * p = NULL;
	
	if((p = malloc(sizeof(linknode))) == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	if((lq = malloc(sizeof(linkqueue))) == NULL)
	{
		printf("malloc queue failed\n");
		return NULL;
	}

	lq->front = lq->rear = p;

	return lq;
}
int enqueue(linkqueue *lq,datatype value)
{
	linknode * p = NULL;
	if((p = malloc(sizeof(linknode))) == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}

	p->next = NULL;
	p->data = value;

	lq->rear->next = p;
	lq->rear = p;

	return 0;
}
int queue_empty(linkqueue * lq)
{
	return lq->front == lq->rear;
}
datatype dequeue(linkqueue * lq)
{
	linknode *p = lq->front;

	if(queue_empty(lq))
	{
		printf("queue is empty\n");
		return -1;
	}

	lq->front = p->next;
	free(p);
	p = NULL;
	
	return lq->front->data;
}

void queue_clear(linkqueue * lq)
{
	linknode * p = NULL;

	while(lq->front->next != NULL)
	{
		p = lq->front;
		lq->front = p->next;
		free(p);
		p = NULL;
		printf("%d ",lq->front->data);
	}
	putchar(10);
		
}
void queue_free(linkqueue * lq)
{
	puts("clear....");
	queue_clear(lq);
	
	puts("free....");
	printf("%d\n",lq->front->data);
	free(lq->front);
	free(lq);
}
