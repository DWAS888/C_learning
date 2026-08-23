//------------------------邻接矩阵结构定义------------------------- 
typedef char VertexType;			//顶点类型
typedef int EdgeType;				//边上的权值类型
#define MAXVEX 100					//最大顶点数
#define INFINITY 65535				//65535代表∞
#define MAXEDGE 100

typedef struct
{
    VertexType vexs[MAXVEX];		//顶点表
    EdgeType arc[MAXVEX][MAXVEX];	//邻接矩阵，可看作边表
    int numNodes,numEdges;			//图中当前的顶点数和边数
}MGraph;

//------------------------Dijkstra算法---------------------------------
typedef int Patharc[MAXVEX];		//存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX];	//存储到各点最短路径的权值和

//Dijkstra算法  求有向网G的v_0顶点到其余顶点v的最短路径P[v]及带权长度D[v]
//P[v]的值为前驱顶点下标，D[v]表示v_0到v的最短路径长度和
void ShortestPath_Dijkstra(MGraph *G,int v0,Patharc *P,ShortPathTable *D)
{
	int v,w,k,min;
	int final[MAXVEX];
	for(v = 0; v < G->numNodes; v++)
	{
		final[v] = 0;
		(*P)[v] = -1;
		(*D)[v] = G->arc[v0][v];
	 } 
	(*D)[0] = 0;
	final[0] = 1;
	for(v = 1; v < G->numNodes; v++)
	{
		min = INFINITY;
		for(w = 0; w < G->numNodes; w++)
		{
			if(!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;
		for(w = 1; w < G->numNodes; w++)
		{
			if(!final[w] && (min + G->arc[k][w]) < (*D)[w])
			{
				(*P)[w] = k;
				(*D)[w] = min + G->arc[k][w];
			}
		}
	}
} 
