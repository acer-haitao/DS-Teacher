#ifndef _SQSTACK_
#define _SQSTACK_

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
int full(sqstack *sq); //打印数据
void stack_clear(sqstack *sq);

void stack_free(sqstack * sq);  //将栈中的元素全部弹出

#endif
