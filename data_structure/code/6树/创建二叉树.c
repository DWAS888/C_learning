#define TElemType char 
#define OVERFLOW -2				// exit() 的退出码

char str[] = "AB#D##C##";
int  index = 0;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree *T)
{
	TElemType ch;
	ch = str[index++];
	
	if(ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);		
	}
}

// 调用时：
//BiTree root = NULL;
//CreateBiTree(&root);	// 传根指针的地址
