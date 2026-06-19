#define MAXSIZE 1000

typedef struct 
{
	ElemType data;
	int cur;
}Component,StaticLinkList[MAXSIZE];

Status ListInit(StaticLinkList space)
{
	for(int i = 0;i<MAXSIZE-1; i++)
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0;
	return OK;
}

int Malloc_SSL(StaticLinkList space)
{
	int i = space[0].cur;
	if(space[0].cur)
		space[0].cur = space[i].cur; 
	return i;
}

Status ListInsert(StaticLinkList L,int i , ElemType e)
{
	int k = MAXSIZE - 1;
	if( i < 1 || i > ListLength(L) +1)
		return ERROR;
	int j = Malloc_SSL(L);
	if(j)
	{
		L[j].data = e;
		for(int l = 1; l <= i-1; l++)
			k = L[k].cur;
		L[j].cur = L[k].cur;
		L[k].cur = j;
	}
	return OK;
}
