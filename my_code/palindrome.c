#include <stdio.h>
	int main()
	{
		int num , i , temp ,rev=0;
		printf("请输入一个整数：\n");
		scanf("%d",&num);
			temp = num ;
			while (temp != 0)
			{
				i = temp % 10;
				temp = temp / 10;
				rev = rev*10 + i;
			}
			if(num == rev)
			{
				printf("%d是回文数",num); 
			}
			else 
			{
				printf("%d不是回文数",num);
			}
			return 0 ;	
						
	}
