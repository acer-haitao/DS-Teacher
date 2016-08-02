#ifndef _LINKSTACK_
#define _LINKSTACK_

typedef int datatype;

typedef struct node{
	datatype data;
	struct node * next;
}linkstack;

linkstack * stack_create();
int push(linkstack*,datatype);
datatype pop(linkstack*);
// empty------1  not empty------0
int empty(linkstack*);
void stack_clear(linkstack*);


#endif
