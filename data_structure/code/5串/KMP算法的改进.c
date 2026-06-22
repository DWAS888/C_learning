void get_nextval(String T,int* next)
{
	int i = 1;
	int j = 0;
	nextval[1] = 0;
	while(i<T[0])
	{
		if(j==0 || T[i] == T[j])
		{
			i++;
			j++;
			if(T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	 } 
}
