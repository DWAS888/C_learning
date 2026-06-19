int Index(string S,string T,int pos)
{
	int m,n,i;
	string sub;
	if(pos > 0)
	{
		m = StrLength(S);
		n = StrLength(T);
		i = pos;
		while( i <= m-n+1 )
		{
			SubString(sub,S,i,n);
			if( StrCompare(sub,T) != 0)
				i++;
			else
				return i;
		}
	}
	return 0;
 } 
