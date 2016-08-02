#include <stdio.h>
#include <stdlib.h>

#define N 64

typedef int datatype;

typedef struct{
	datatype data[N];
	int top;
}sqstack;

//创建 ，入栈，出栈，取栈顶元素，判断栈的空满，清空栈

sqstack *stack_create();
int push(sqstack * sq,datatype value);
datatype pop(sqstack *sq);  //将出站数据返回
datatype top(sqstack *sq);
//如果栈为空/满  ----1  否则 ------ 0
int empty(sqstack *sq);
int full(sqstack *sq);

void stack_free(sqstack * sq);  //将栈中的元素全部弹出

int main(int argc, const char *argv[])
{
	
	return 0;
}

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
int push(sqstack * sq,datatype value);
datatype pop(sqstack *sq);  //将出站数据返回
datatype top(sqstack *sq)
{
	return sq->data[sq->top];
}
//如果栈为空/满  ----1  否则 ------ 0
int empty(sqstack *sq)
{
	return (sq->top == -1) ? 1 : 0;
}
int full(sqstack *sq);
void stack_free(sqstack * sq);  //将栈中的元素全部弹出
