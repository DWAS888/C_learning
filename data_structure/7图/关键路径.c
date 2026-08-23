typedef enum { FALSE, TRUE } Boolean;
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode			//边表结点
{
    int adjvex;					//邻接点域，存储该结点下标
    EdgeType weight;				//存储权值（可有可无）
    struct EdgeNode *next;		//链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode		//顶点表结点
{
    int in;				//顶点入度
    VertexType data;			//顶点域，存储顶点信息
    EdgeNode *firstedge;		//边表头指针
}VertexNode,AdjList[MAXVEX];

typedef struct					//图结构
{
    AdjList adjList;
    int numNodes,numEdges;
}GraphAdjList;

//求关键路径
void CriticalPath(GraphAdjList GL)
{
    EdgeNode *e;
    int i, gettop, k, j;
    int ete, lte;       /* 声明活动最早发生时间和最迟发生时间变量 */
    TopologicalSort(GL); /* 求拓扑序列，计算数组etv和stack2的值 */
    ltv = (int *)malloc(GL->numNodes * sizeof(int)); /* 事件最晚发生时间数组 */
    for(i = 0; i < GL->numNodes; i++)
        ltv[i] = etv[GL->numNodes - 1];              /* 初始化ltv */

    while(top2 != 0)                                    /* 计算ltv */
    {
        gettop = stack2[top2--];
        for(e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if(ltv[k] - e->weight < ltv[gettop])        /* 求各顶点事件最晚发生时间ltv */
                ltv[gettop] = ltv[k] - e->weight;
        }
    }

    for(j = 0; j < GL->numNodes; j++)                /* 求ete, lte和关键活动 */
    {
        for(e = GL->adjList[j].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            ete = etv[j];                               /* 活动最早发生时间 */
            lte = ltv[k] - e->weight;                   /* 活动最迟发生时间 */
            if(ete == lte)                              /* 两者相等即在关键路径上 */
                printf("<v%d - v%d> length: %d \n",
                       GL->adjList[j].data, GL->adjList[k].data, e->weight);
        }
    }
}

//拓扑排序，若GL无回路，啧输出拓扑排序序列并返回1，若有回路返回0
Status TopologicalSort(GraphAdjList *GL)
{
	EdgeNode *e;
	int i,k,gettop;
	int top = 0;			//栈的指针下标 
	int count = 0;			//统计输出顶点的个数 
	int *stack;				//建栈  将入度为0的顶点入栈 
	stack = (int *)malloc(GL->numNodes * sizeof(int));
	for(i = 0; i < GL->numNodes; i++)
		if(0 == GL->adjList[i].in)	//将入度为0的顶点入栈 
			stack[++top] = i; 
    top2 = 0;
    etv = (int *)malloc(GL->numNodes * sizeof(int));//时间最早发生时间数组
    for(i = 0; i < GL->numNodes; i++)
        etv[i] = 0;
    stack2 = (int *)malloc(GL->numNodes * sizeof(int));//初始化拓扑序列栈
	while(top != 0)
	{
		gettop = stack[top--];		//出栈
		printf("%d -> ",GL->adjList[gettop].data);	//打印顶点
		count++;			//统计输出顶点数

        stack2[++top2] = gettop;			//将弹出的顶点序号压入拓扑序列的栈
		for(e = GL->adjList[gettop].firstedge;e;e = e->next)	//对此顶点弧表遍历 
		{
			k = e->adjvex;
			if(!(--GL->adjList[k].in))		//将k号顶点邻接点的入度-1 
				stack[++top] = k;			//若为0则入栈 
            if( (etv[gettop] + e->weight) > etv[k] )
                etv[k] = etv[gettop] + e->weight;	//各顶点事件的最早发生时间etv
		 } 
	 }
	if(count < GL->numNodes)		//若count小于顶点数，则存在环
		return ERROR;
	else
		return OK;
} 
