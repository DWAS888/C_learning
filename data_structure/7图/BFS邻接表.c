typedef enum { FALSE, TRUE } Boolean;
Boolean visited[MAXVEX];

//----------------邻接表定义---------------------
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode			//边表结点
{
    int adjvex;					//邻接点域，存储该结点下标
    EdgeType info;				//存储权值（可有可无）
    struct EdgeNode *next;		//链域，指向下一个邻接点
}EdgeNode; 

typedef struct VertexNode		//顶点表结点
{
    VertexType data;			//顶点域，存储顶点信息
    EdgeNode *firstedge;		//边表头指针
}VertexNode,AdjList[MAXVEX];

typedef struct					//图结构
{
    AdjList adjList;
    int numNodes,numEdges;
}GraphAdjList;

//----------------------BFS邻接表-----------------------------------
void BFSTraverse(GraphAdjList *GL)
{
	int i,j;
	EdgeNode *p;
	Queue Q;
	InitQueue(&Q);
	for(i = 0;i < GL->numNodes;i++)
		visited[i] = 0;	
	for(i = 0;i < GL->numNodes;i++)
	{
		if(!visited[i])
		{
			visited[i] = TRUE;
			printf("%c\n",GL->adjList[i].data);
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&j);
				p = GL->adjList[j].firstedge;
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex] = TRUE;
						printf("%c\n",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);
					}
					p = p->next;
				}
			}
		} 
	}	
}
