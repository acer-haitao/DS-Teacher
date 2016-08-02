#include <stdio.h>
#include <stdlib.h>
#include "mgraph.h"

mgraph *mgraph_create(int n, int matrix[][n])
{
    int i, j;

    mgraph *mg;
    mg = (mgraph *)malloc(sizeof(mgraph));
    mg->n = n;
    
    for (i = 0; i < n; i++)
    {
        mg->vertex[i] = i;
        for (j = 0; j < n; j++)
            mg->edge[i][j] = matrix[i][j];
    }
    
    return mg;
}
//已经经历的点放到s中没有经过记为0
void dijkstra(mgraph *mg, int v, int *s, int *dist, pathtype *path)
{
    int i, count, min, u, w;

    for (i = 0; i < mg->n; i++)
    {
        s[i] = 0;//先都初始化为0
        dist[i] = mg->edge[v][i]; //v=0从主函数传入表示从v0开始，将初始点到各店的
		                          //距离进行记录
        path[i].pi[0] = v;   //存到每个点经过的第一个点的下标（就是这个初始点）
        path[i].end = 0;    // v0点到每个点经历的点先都初始化为0
    }
    s[v] = 1;  //v0点已经经过，记为1
	
    count = 1; //第一个点

    while (count < mg->n)  //遍历其他点看v0到哪个最短
    {
        min = M;  //先认为最短的是M
        for (u = 0; u < mg->n; u++)
        {
            if (!s[u] && min > dist[u])  //满足两个条件的找出来，没有标记且距离小于min
            {
                min = dist[u];
                w = u;  //记录这个点的下标
            }
        }
        s[w] = 1;   //把这个点标记
        dist[w] = min;    //记v0到这个点的最短距离
        path[w].end++;  //经历的点的个数加1
        path[w].pi[path[w].end] = w;//存经历的第end个点的下标
        count++; //点数加1，其实是剩余的点少了一个，即循环少了一次

        for (u = 0; u < mg->n; u++)
        {
            if (!s[u] && dist[w]+ mg->edge[w][u] < dist[u])  //找到从dist[w]这个点
			                                                 //到一个未标记点的最小情况
            {
                dist[u] = dist[w] + mg->edge[w][u];
                path[u] = path[w];                            //将经过的这个点w的信息付给这个经过的结构体
            }
        }
    }
	//先后确定0 2 5 1 4 3的距离
}
