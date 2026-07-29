//循环队列的顺序存储结构
typedef int QElemType;

typedef struct
{
	QElemType data[MAXSIZE];
	int front,rear;
}SqQueue;

//初始化空队列
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

//求队列长度
int QueueLength(SqQueue Q)
{
	return( (Q.rear - Q.front + MAXSIZE) % MAXSIZE );		//注意，这里传入的是Q不是*Q，所以用. ！！！ 
}

//入队列操作
Status EnQueue(SqQueue *Q, QElemType e)
{
	if((Q->rear + 1)%MAXSIZE == Q->front)	//判断是否满队 
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE; 
	return OK;
}

//出队列操作 
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if(Q->rear == Q->front)					//判断是否队空 
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}
