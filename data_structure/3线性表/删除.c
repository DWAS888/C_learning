Status ListDelete(LinkList *L,int i,ElemType *e)
{
	int j = 1;
	LinkList p,q;
	p = *L;
	while ( p->next && j < i){
		p = p->next;
		j++;
	}						//j = i,为 a_i-1，p指向 a_i-1 
	if( !p->next || j > i)
		return ERROR;
	q = p->next;			//q指向a_i 
	p->next = q->next;		//让p指向a_i 
	*e = q->data;			//取第 i 个结点的数据
	free(q);
	return OK; 
}
