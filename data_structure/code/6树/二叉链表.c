typedef char TElemType;

typedef struct BiTNode		//结点结构 
{
	TElemType data;
	struct BiTNode *lchild,*rchild;	//左右孩子结点 
}BiTNode,*BiTree;

//新建结点 
BiTree NewNode(TElemType x)
{
	BiTree p = (BiTree)malloc(sizeof(BiTNode));
	p->data = x;
	p->lchild = p->rchild = NULL;
	return p;
 } 
 
int main()
{
	//新建一棵树！ 
	BiTree A = NewNode('A');
	BiTree B = NewNode('B');
	BiTree C = NewNode('C');
	BiTree D = NewNode('D');
	BiTree E = NewNode('E');
	BiTree F = NewNode('F');
	
	A->lchild = B;A->rchild = C;
	B->lchild = D;B->rchild = E;
	C->rchild = F;
	
	return 0; 
 } 
