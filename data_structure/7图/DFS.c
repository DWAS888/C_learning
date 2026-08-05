#define MAXVEX 100
typedef enum { FALSE, TRUE } Boolean;
typedef char VertexType;
typedef int EdgeType;

typedef struct 
{
	VertexType vex[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numNodes,numEdges;
}MGraph;

Boolean visited[MAXVEX];

void DFS(MGraph G,int i)	//一图递归 
{
	int j;
	visited[i] = TRUE;
	printf("%c\n",G.vex[i]);
	for(j = 0;j < G.numNodes;j++)
		if(G.arc[i][j] && !visited[j])
			DFS(G,j);
}

void DFSTraverse(MGraph G)	
{
	int i;
	for(i = 0;i < G.numNodes;i++)	//初始化 
		visited[i] = FALSE;
	for(i = 0;i < G.numNodes;i++)	//可能不连续：扫所有图 
		if(!visited[i])
			DFS(G,i);
}
