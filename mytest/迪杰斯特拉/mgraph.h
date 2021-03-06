#ifndef MGRAPH_H_
#define MGRAPH_H_

#define MAXN 64
#define M 1<<10

typedef struct 
{
    int vertex[MAXN];
    int edge[MAXN][MAXN];
    int n;
}mgraph;

typedef struct
{
    int pi[MAXN]; //存经历的点
    int end;  //存储经过了几个点
}pathtype;

mgraph *mgraph_create(int n, int matrix[][n]);
void dijkstra(mgraph *mg, int v, int *s, int *dist, pathtype *path);

#endif
