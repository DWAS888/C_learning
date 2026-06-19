Status ListInsert(LinkList *L,int i,ElemType e) 
{
	LinkList p,s;
	p = *L;		//p指向第一个结点 
	int j = 1;
	
	while(j < i-1)
	{
		p = p->next;
		j++;
	 } 
	if( !p || j > i-1)
		return ERROR;
	
	s = (LinkList)malloc(sizeof(Node));
	if (!s) return OVERFLOW; // 内存分配失败，返回溢出错误
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
