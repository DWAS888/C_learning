typedef int SElemType; 

typedef struct
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

//SqDoubleStack 初始化函数，可加 
Status StatusInit(SqDoubleStack *S)
{
	top1 = -1;			//栈 1 栈顶指向 -1,表示空栈
	top2 = MAXSIZE;		//栈 2 栈顶指向 MAXSIZE(越右端一格),表示空栈
	return OK;
}

Status Push(SqDoubleStack *S,SElemType e,int StackNumber)
{
	if(S->top1 + 1 == S->top2)
		return ERROR;
	if(StackNumber == 1)
		S->data[++S->top1] = e;
	else if(StackNumber == 2)
		S->data[--S->top2] = e;
	return OK;
}

Status Pop(SqDoubleStack *S,SElemType *e,int StackNumber)
{
	if(StackNumber == 1)
	{
		if(S->top1 == -1)
			return ERROR;
		*e = S->data[S->top1--];
	}
	else if(StackNumber == 2)
	{
		if(S->top2 == MAXSIZE)
			return ERROR;
		*e = S->data[S->top2++];
	}
	return OK;
}
