#ifndef _LINKQUEUE_
#define _LINKQUEUE_
#include "bitree.h"

typedef bitree* datatype;

//结点结构体
typedef struct node{
	datatype data;
	struct node * next;
}linknode;

//队列结构体
typedef struct{
	linknode * front;
	linknode * rear;
}linkqueue;

linkqueue * queue_create();
int enqueue(linkqueue *lq,datatype value);
int queue_empty(linkqueue * lq);
datatype dequeue(linkqueue * lq);


#endif
