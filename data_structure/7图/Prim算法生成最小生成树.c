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

//----------------Prim最小生成树---------------------
void MiniSpanTree_Prim(MGraph *G) 
{
	int min,i,j,k;
	int adjvex[MAXVEX];			//保存相关顶点间边的权值点下标
	int lowcost[MAXVEX];		//保存相关顶点间边的权值
	lowcost[0] = 0;				//初始化第一个权值为0，即v_0加入生成树 
	adjvex[0] = 0;				//初始化第一个顶点下标为0
	for(i = 1;i < G->numNodes; i++)
	{
		lowcost[i] = G->arc[0][i];	//将v_0顶点与之有边的权值存入数组 
		adjvex[i] = 0; 			//初始化都为v_0的下标
	} 
	for (i = 1;i < G->numNodes; i++)	//构造最小生成树
	{
		min = INFINITY;			//初始化最小权值为∞ 
		j = 1;k = 0;			//j 顶点下标循环的变量；k 最小权值的顶点下标
		//在还没入树的顶点中找到一个lowcost最小的。循环结束后，k就是要加入的顶点
        while(j < G->numNodes)	//循环全部顶点 
		{
			if(lowcost[j] != 0 && lowcost[j] < min)	//lowcost[j]!=0表明已经是生成树的顶点不再参与最小权值的查找
			{					//如果权值不为0且权值小于min 
				min = lowcost[j];//则让当前权值称为最小值 
				k = j;			//将当前最小值的下标存入k 
			}
			j++; 
		}
		printf("(%d,%d)\n",adjvex[k],k);//打印：边 (来源, 新顶点)
		lowcost[k] = 0;			//标记此顶点已进入树
		//用新顶点k更新其他顶点的lowcost
        for(j = 1;j < G->numNodes; j++)	//循环所有顶点 
		{		//如果下标为k的顶点的各边权值小于此前这些顶点未被加入生成树的权值 
			if(lowcost[j] != 0 && G->arc[k][j] < lowcost[j])
			{
				lowcost[j] = G->arc[k][j];//将较小的权值存入lowcost相应位置 
				adjvex[j] = k;	//将下标为k的顶点存入adjvex 
			}
		}
	}
}
