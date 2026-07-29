Status GetElem(LinkList L, int i, ElemType *e)
{
	//1. 定义指针p和计时器j
	LinkList p;
	p = L->next;
	int j = 1; 
	//2. 用p遍历，j累加1
	while( p&&j < i){
		p = p->next;
		j++;
	}
	//3. p为空指针时或计时器超过i时，跳出循环
	if( !p||j > i)
		return ERROR;
	//4. 返回 
	*e = p->data;
	return OK;
}
