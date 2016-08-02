
typedef int datatype;

typedef struct node {
	datatype data;
	struct node * next;
}listnode, * linklist;

typedef struct {
	listnode * front;
	listnode * rear;
}linkqueue;

linkqueue * queue_create();
void queue_clear(linkqueue * lq);
int queue_empty(linkqueue * lq);
int enqueue(linkqueue * lq, datatype x);
datatype dequeue(linkqueue * lq);
void queue_free(linkqueue *lq);

