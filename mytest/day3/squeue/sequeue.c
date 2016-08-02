#include <stdio.h>
#include <stdlib.h>
#include "sequeue.h"

sequeue * queue_create()
{
	sequeue * s = NULL;

	if((s = malloc(sizeof(sequeue))) == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	
	s->front = s->rear = 0;

	return s;
}
int enqueue(sequeue *s,datatype value)//入队
{
	if(queue_full(s))
	{
		printf("queue is full\n");
		return -1;
	}

	s->data[s->rear] = value;//值给队尾
	s->rear = (s->rear + 1) % N;

	return 0;
}

//full ----1   not full----0
int queue_full(sequeue * s)//判断队列是否为满
{
	if (s->front == (s->rear + 1) % N)
		return 1;
	else
		return 0;
}
datatype dequeue(sequeue * s)
{
	datatype t = s->data[s->front];//保存队头元素
	if(queue_empty(s))
	{
		printf("queue is emtpy\n");
		return -1;
	}

	s->front = (s->front + 1) % N;//删除队头元素

	return t;
}

//emtpy -----1   not empty ----0
int queue_empty(sequeue * s)//判断队列是否为空
{
	return s->front == s->rear;
}
void queue_clear(sequeue * s)
{
	s->front = s->rear = 0;
}
