#include <stdio.h>
#include <stdlib.h> 	//malloc要用 
#define MAXVEX 100
#define INFINITY 65535
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
	int adjvex;
	EdgeType info;			//存储权值，可有可无 
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode *firstEdge;
} VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes,numEdges;
}GraphAdjList;

void CreateGraphAdjList(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	EdgeType w;
	printf("请输入顶点数和边数：\n");
	scanf(" %d,%d",&G->numNodes,&G->numEdges); 
	for(i = 0; i < G->numNodes; i++)
	{
		printf("请输入第%d个顶点的信息：\n",i);
		scanf(" %c",&G->adjList[i].data);
		G->adjList[i].firstEdge = NULL;
	}
	for(k = 0;k < G->numEdges; k++)
	{
		printf("请输入(v_i,v_j)的下标及边的值：\n");
		scanf(" %d,%d,%d",&i,&j,&w);
		
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex  = j;
		e->info = w;
		e->next = G->adjList[i].firstEdge;
		G->adjList[i].firstEdge = e;
		
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex  = i;
		e->info = w;
		e->next = G->adjList[j].firstEdge;
		G->adjList[j].firstEdge = e;
	} 
}
