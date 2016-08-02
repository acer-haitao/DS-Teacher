#include <stdio.h>
#include "sqstack.h"

int main(int argc, const char *argv[])
{
	int i = 1,x,y;
	sqstack * sq = NULL;

	if((sq = stack_create()) == NULL)
		return -1;
	
	while(*argv[i] != 'p')
	{
		if(*argv[i] >= '0' && *argv[i] <= '9')
		{
			push(sq,*argv[i] - '0');
		}
		if(*argv[i] == '+' || *argv[i] == '-' || *argv[i] == '*' || *argv[i] == '/')
		{
			y = pop(sq);
			x = pop(sq);
			switch(*argv[i])
			{
				case '+':
					push(sq,x + y);
					break;
				case '-':
					push(sq,x - y);
					break;
				case '*':
					push(sq,x * y);
					break;
				case '/':
					if(y == 0)
					{
						puts("Your input error\n");
						break;
					}
					push(sq,x / y);
					break;
				default:
					puts("sorry!!!");
			}
		}

		i++;
	}

	printf(">>>%d\n",pop(sq));

	return 0;
}
