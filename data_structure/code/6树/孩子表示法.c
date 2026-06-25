#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct CTNode		//孩子结点 
{
	int child;
	struct CTNode* next; 
} *ChildPtr;

typedef struct 				//表头
{
	TElemType data;
	ChildPtr firstchild;
} CTBox;

typedef struct				//树结构 
{
	CTBox nodes[MAX_TREE_SIZE];
	int r,n;				//根结点的下标和结点数
} CTree;
