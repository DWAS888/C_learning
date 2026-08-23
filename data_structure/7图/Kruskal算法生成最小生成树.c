typedef enum { FALSE, TRUE } Boolean;
Boolean visited[MAXVEX];

//----------------邻接矩阵定义---------------------
#define MAXVEX 100
#define INFINITY 63655
typedef char VertexType;
typedef int EdgeType;

typedef struct 
{
	VertexType vex[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numNodes,numEdges;
}MGraph;

//----------------Kruskal最小生成树---------------------
typedef struct
{
	int begin;
	int end;
	int weight; 
}Edge;

void MiniSpanTree_Kruskal(MGraph *G)
{
	int i,n,m;
	Edge edges[MAXVEX];			//定义边集数组 
	int parent[MAXVEX];			//定义一数组，判断边与边是否形成环
	
	//省略将邻接矩阵G转化为边集数组edges并按权从小到大排序的代码
	
	for(i = 0;i < G->numNodes; i++)
		parent[i] = 0;
	for(i = 0;i < G->numEdges; i++)
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if(n != m)				//未形成环路 
		{
			parent[n] = m;
			printf("(%d,%d)%d\n",edges[i].begin,edges[i].end,edges[i].weight);
		}
	}
}

//查找连线顶点的尾部下标 
int Find(int* parent ,int f)
{
	while(parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}
