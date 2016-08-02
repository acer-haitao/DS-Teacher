#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

linkstack * stack_create()
{
	linkstack * s = NULL;
	if((s = malloc(sizeof(linkstack)))== NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	s->next = NULL;

	return s;
}
int push(linkstack*s,datatype value)
{
	linkstack * p = NULL;
	if((p = malloc(sizeof(linkstack))) == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	
	p->data = value;

	p->next = s->next;
	s->next = p;

	return 0;
}
datatype pop(linkstack* s)
{
	linkstack * p = s->next;
	datatype t = p->data;

	if(empty(s))
	{
		printf("stack is empty\n");
		return -1;
	}
	s->next = p->next;
	free(p);
	
	return t;
}
// empty------1  not empty------0
int empty(linkstack*s)
{
	return (s->next == NULL) ?  1 : 0;
}
void stack_clear(linkstack*s)
{
	while(!empty(s))
	{
		printf("%d ",pop(s));
	}
	putchar(10);
}

