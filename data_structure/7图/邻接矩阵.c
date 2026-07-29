#define MAXTEX 100
#define INFINITY 65535
typedef char VertexType;
typedef int EdgeType;

typedef struct 
{
	VertexType vex[MAXTEX];
	EdgeType arc[MAXTEX][MAXTEX];
	int numNodes,numEdges;
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i,j,v,w;
	printf("请输入结点个数和边个数：\n");
	scanf(" %d,%d",&G->numNodes,&G->numEdges);
	for(int i = 0;i < G->numNodes; i++)
		scanf("%c",&vex[i]);
	for(int i = 0;i < G->numNodes; i++)
		for(int j = 0;j < G->numNodes; j++)
			arc[i][j] = INFINITY;
	for(int i = 0;i < G->numEdges)
	{
		printf("请输入(v_i,v_j)的上标、下标和权值：\n");
		scanf("%d,%d,%d",i,j,w);
		arc[i][j] = w;
		arc[j][i] = arc[i][j];
	}
}
