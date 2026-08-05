typedef enum { FALSE, TRUE } Boolean;
Boolean visited[MAXVEX];

//----------------邻接矩阵定义---------------------
#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;

typedef struct 
{
	VertexType vex[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numNodes,numEdges;
}MGraph;

//----------------BFS-------------------------------
void BFSTraverse(MGraph *G)
{
	int i,j;
	Queue Q;
	for(i = 0; i < G->numNodes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);
	for(i = 0; i < G->numNodes; i++)
	{
		if(!visited[i])
		{
			visited[i] = TRUE;
			printf("%c\n",G->vex[i]);
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))	//BFS本体 	所有顶点都访问完就队空 
			{
				DeQueue(&Q,&i);
				for(j = 0; j < G->numNodes; j++)
				{
					if(G->arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;
						printf("%c\n",G->vex[j]);
						EnQueue(&Q,j);
					}
				}
			}
		}
	}
}
