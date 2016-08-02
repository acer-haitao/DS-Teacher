#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"

sqstack *stack_create()
{
	sqstack * sq = NULL;
	if((sq = malloc(sizeof(sqstack))) == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	
	sq->top = -1;
	return sq;
}
int push(sqstack * sq,datatype value)
{
	if(full(sq))
	{
		printf("stack is full\n");
		return -1;
	}
	
	sq->data[sq->top + 1] = value;
	sq->top++;
	
	return 0;
}
datatype pop(sqstack *sq)  //将出站数据返回
{
	if(empty(sq))
	{
		printf("stack is empty\n");
		return -1;
	}
	
	sq->top--;
	
	return sq->data[sq->top + 1];
}
datatype top(sqstack *sq)
{
	return sq->data[sq->top];
}
//如果栈为空/满  ----1  否则 ------ 0
int empty(sqstack *sq)
{
	return (sq->top == -1) ? 1 : 0;
}
int full(sqstack *sq)
{
	return (sq->top == N - 1) ? 1 : 0;
}
void stack_free(sqstack * sq)  //将栈中的元素全部弹出
{
	while(!empty(sq))
	{
		printf("%d ",pop(sq));
	}
	putchar(10);
}

void stack_clear(sqstack *sq)
{
	sq->top = -1;
}
