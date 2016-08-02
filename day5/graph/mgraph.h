
#ifndef MGRAPH_H_
#define MGRAPH_H_

#define MAXN 64

typedef struct {
	int vertex[MAXN];   //V0 V1 V2 V3
	int edge[MAXN][MAXN];
	int n;
}mgraph;

//mgraph * mgraph_create(int n, int (*a)[n]);
mgraph * mgraph_create(int n, int a[][n]);
void DFS(mgraph  * mg, int v);
void BFS(mgraph  * mg, int v);

#endif

