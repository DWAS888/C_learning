#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct PTNode
{
	TElemType data;		//结点数据 
	int parent;			//双亲域 
};

typedef struct			//树结构 
{
	PTNode nodes[MAX_TREE_SIZE];	//结点 
	int r,n;			//根的位置和结点树 
}PTree;
