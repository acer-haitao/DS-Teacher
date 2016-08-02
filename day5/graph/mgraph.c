#include <stdio.h>
#include <stdlib.h>
#include "mgraph.h"
#include "linkqueue.h"

mgraph * mgraph_create(int n, int a[][n]) {
	int i, j;
	mgraph * mg;

	if ((mg = (mgraph *)malloc(sizeof(mgraph))) == NULL) {
		printf("malloc failed\n");
		return NULL;
	}

	for (i = 0; i < n; i++) {
		mg->vertex[i] = i;
		for (j = 0; j < n; j++) {
			mg->edge[i][j] = a[i][j];
		}
	}
	
	mg->n = n;

	return mg;
}

void DFS(mgraph  * mg, int v) {
	static int visited[MAXN];
	int i;

	printf("V%d ", v);//mg->vertex[v]
	visited[v] = 1;

	for (i = 0; i < mg->n; i++)
	{
		if (mg->edge[v][i] == 1 && visited[i] == 0)
			DFS(mg, i);
	}
}

void BFS(mgraph  * mg, int v) {
	linkqueue * lq ;
	int visited[MAXN] = {0}, i;

	if ((lq = queue_create()) == NULL) 
		return;

	printf("V%d ", mg->vertex[v]);
	visited[v] = 1;
	enqueue(lq, v);
	
	while (queue_empty(lq) == 0) {
		v = dequeue(lq);

		for (i = 0; i < mg->n; i++ ) {
			if (mg->edge[v][i] && !visited[i]) {
				printf("V%d ", mg->vertex[i]);
				visited[i] = 1;
				enqueue(lq, i);
			}
		}
	}
	puts("");

}
