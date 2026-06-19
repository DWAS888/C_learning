Status CreateListHead(LinkList *L,int n)
{
	LinkList p;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		p->next = (*L)->next; 
		(*L)->next = p;
	}
	return OK;
}

Status CreateListTail(LinkList *L,int n)
{
	LinkList p,r;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(int i = 0;i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 +1;
		r->next = p;
		r = p;
	}
	r ->next = NULL;
	return OK;
}
