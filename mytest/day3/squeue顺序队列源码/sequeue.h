#ifndef _SEQUEUE_
#define _SEQUEUE_

#define N 64

typedef int datatype;

typedef struct{
	datatype data[N];
	int front;
	int rear;
}sequeue;

sequeue * queue_create();
int enqueue(sequeue *s,datatype value);
int queue_full(sequeue * s);
datatype dequeue(sequeue * s);
int queue_empty(sequeue * s);
void queue_clear(sequeue * s);



#endif
