//结构定义 
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild,*rchild;
	PointerTag LTag;
	PointerTag RTag; 
}BiThrNode,*BiThrTree;

//线索化递归函数
BiThrTree pre;
void InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lchild);
		if(!p->lchild)
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if(!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}

//遍历
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;
	while(p!=T)
	{
		while(p->LTag == Link)
			p = p->lchild;
		printf("%c",p->data);
		while(p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c",p->data);
		}
		p = p->rchild;
	}
	return OK;
} 
