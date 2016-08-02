#include <stdio.h>  
#include <stdlib.h>  
  
#define  MaxVertexNum 100  
  
typedef char VertexType;  
typedef struct node   //边表节点  
{  
   int adjvex;  
   struct node* next;  
}EdgeNode;  
  
typedef struct     //顶点表节点  
{  
   VertexType vertex;  
   EdgeNode* firstedge;  
}VertexNode;  
  
typedef VertexNode AdjList[MaxVertexNum];  
  
typedef struct   
{   
    AdjList adjlist;  
    int n,e;  
  
}ALGraph;  
  
void create(ALGraph*);  
  
void main()  
{
	int i;
   ALGraph* G= (ALGraph*)malloc(sizeof(ALGraph));  
   create(G);  
   for (i=0;i< G->n;i++)  
   {  
       printf("%d->",i);  
       while(G->adjlist[i].firstedge!=NULL)  
       {  
            printf("%d->",G->adjlist[i].firstedge->adjvex);  
            G->adjlist[i].firstedge=G->adjlist[i].firstedge->next;  
  
       }  
       printf("\n");  
   }  
}  
void create(ALGraph* G)  
{  
    int i,j,k,w,v;  
    EdgeNode *s;  
    printf("读入顶点数和边数");  
    scanf("%d,%d",&G->n,&G->e);  
 	getchar(); 
    
   for (i=0;i<G->n;i++)  
   {  
       printf("建立顶点表");  
       G->adjlist[i].vertex=getchar();  //输入顶点的信息
	   getchar();
       G->adjlist[i].firstedge=NULL;  
   }  
   printf("建立边表\n");  
   for (k=0;k<G->e;k++)  
   {  
       printf("读入(vi-vj)的顶点对序号");  
       scanf("%d,%d",&i,&j);  
       s=(EdgeNode*)malloc(sizeof(EdgeNode));  
       s->adjvex=j;  
       s->next=G->adjlist[i].firstedge;  //插入表头  
       G->adjlist[i].firstedge=s;  
	   
       s=(EdgeNode*)malloc(sizeof(EdgeNode));  //无向的是双方面的
       s->adjvex=i;  
       s->next=G->adjlist[j].firstedge;  
       G->adjlist[j].firstedge=s;  
  
   }  
}
