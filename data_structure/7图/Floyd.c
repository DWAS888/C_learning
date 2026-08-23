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

//----------------------------Floyd---------------------------------- 
//求网图G中各顶点v到其余顶点w的最短路径P[v][w]及带权长度D[v][w] 
typedef int Patharc[MAXVEX][MAXVEX];		//顶点到顶点的最短路径：均为二维数组
typedef int ShortPathTable[MAXVEX][MAXVEX];	

void ShortestPath_Floyd(MGraph *G,Patharc *P,ShortPathTable *D)
{					//P：最短路径的前驱矩阵，用来存储路径 
	int v,w,k;
	for(v = 0;v < G->numNodes;++v)		//初始化D与P
	{
		for(w = 0;w < G->numNodes;++w)
		{
			(*D)[v][w] = G->arc[v][w];		//(*D)[v][w]即为对应顶点间权值 
			  if (v == w) 
			  {
			      (*D)[v][w] = 0;
			      (*P)[v][w] = -1;          // 自己到自己，没有下一个点
			  } 
			  else if (G->arc[v][w] < INFINITY) 
			  {
			      (*P)[v][w] = w;           // 有直接边，下一步就是 w
			  } 
			  else 
			  {
			      (*P)[v][w] = -1;          // 不可达
			  }				 
		}
	}
	for(k = 0;k < G->numNodes;++k)			//必须是k在最外层！
	{
		for(v = 0;v < G->numNodes;++v)
		{
			for(w = 0;w < G->numNodes;++w)
			{		//若经过k的路径比原两顶点间路径更短 
				if( (*D)[v][w] > (*D)[v][k] + (*D)[k][w] )
				{	//则更新为经过k的路径 
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = (*P)[v][k];
				}
			}
		}
	}
 } 
//----------------------------打印路径---------------------------------- 
void PrintShortestPath(MGraph *G,Patharc *P,ShortPathTable *D)
{
	int v,k,w; 
	printf("各顶点间的最短路径如下：\n");
	for(v = 0;v < G->numNodes;++v)
	{
		for(w = v + 1;w < G->numNodes;w++)
		{
			printf("v%d-v%d	weight:%d",v,w,(*D)[v][w]);
			k = (*P)[v][w];				//第一个路径顶点下标 
			printf(" path:%d",v);		//打印源点 
			while(k != w)				//如果路径顶点下标不是终点 
			{
				printf(" -> %d",k);		//打印路径顶点 
				k = (*P)[k][w];			//获得下一个路径顶点下标 
			}
			printf(" -> %d\n",w);		//打印终点 
		}
		printf("\n");
	}
}
