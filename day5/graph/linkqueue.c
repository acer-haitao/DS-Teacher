#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

linkqueue * queue_create() {
	linkqueue * lq;
	listnode * p;

	if ((lq = (linkqueue *)malloc(sizeof(linkqueue))) == NULL) {
		printf("malloc failed\n");
		return NULL;
	}

	if ((p = (listnode *)malloc(sizeof(listnode))) == NULL) {
		printf("malloc failed\n");
		return NULL;
	}
	p->data = 0;
	p->next = NULL;

	lq->front = p;
	lq->rear = p;

	return lq;
}

void queue_clear(linkqueue * lq) {
	listnode * p;

	printf("clear:");

	while (lq->front->next != NULL) {
		p = lq->front;
		lq->front = p->next;
		printf("%d ", p->data);
		free(p);
		p = NULL;
	}
	printf("\n");
}

int queue_empty(linkqueue * lq) {
	return (lq->front == lq->rear);
	//return (lq->front->next == NULL);
}

int enqueue(linkqueue * lq, datatype x) {
	listnode * p;

	if ((p = (listnode *)malloc(sizeof(listnode))) == NULL) {
		printf("malloc failed\n");
		return -1;
	}
	p->data = x;
	p->next = NULL;

	lq->rear->next = p;
	lq->rear = p;

	return 0;
}

datatype dequeue(linkqueue * lq) {
	listnode * p;

	p = lq->front;

	lq->front = p->next;
	free(p);
	p = NULL;

	return (lq->front->data);
}

void queue_free(linkqueue *lq) {
	queue_clear(lq);

	printf("clear.....  free:%d\n", lq->front->data);
	free(lq->front);
	free(lq);
	lq = NULL;
}

