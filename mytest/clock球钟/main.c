#include <stdio.h>
#include "sqstack.h"
#include "linkqueue.h"

//1----表示回到原来状态
int check(linkqueue * lq)
{
	linknode * p = lq->front->next;
	while(p != NULL && p->next != NULL)
	{
		if(p->data > p->next->data)
			return 0;
		else
			p = p->next;
	}

	return 1;
}

int main(int argc, const char *argv[])
{
	int t = 0;  //记录时间
	int i;
	linkqueue * lq = NULL;
	sqstack * min,*five,*hour;

	if((lq = queue_create()) == NULL)
		return -1;
	for(i = 1;i <= 27;i++)
		enqueue(lq,i);
	if((min = stack_create()) == NULL)
		return -1;
	if((five = stack_create()) == NULL)
		return -1;
	if((hour = stack_create()) == NULL)
		return -1;
	
	while(1)
	{
		t++;
		i = dequeue(lq);
		if(min->top < 3)
		{
			push(min,i);
		}
		else
		{
			while(!empty(min))
			{
				enqueue(lq,pop(min));
			}
			if(five->top < 10)
			{
				push(five,i);
			}
			else
			{
				while(!empty(five))
				{
					enqueue(lq,pop(five));
				}
				if(hour->top < 10)
				{
					push(hour,i);
				}
				else
				{
					while(!empty(hour))
					{
						enqueue(lq,pop(hour));
					}
					enqueue(lq,i);
					if(check(lq))
						break;
				}
			}
		}

	}

	printf("time = %d\n",t / 60 );
	
	return 0;
}
