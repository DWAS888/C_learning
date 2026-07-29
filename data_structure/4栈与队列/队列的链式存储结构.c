typedef int QElemType ;
//定义结点
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;

//定义链队列
typedef struct
{
	QueuePtr front,rear;
} LinkQueue;

//初始化 
Status InitQueue(LinkQueue *Q) 
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front) 
		return ERROR;
    Q->front->next = NULL;
    return OK;
}

//入队
Status EnQueue(LinkQueue *Q,QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if(!s)
		return ERROR;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}

//出队
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
} 
