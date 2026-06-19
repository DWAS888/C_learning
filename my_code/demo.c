#include <stdio.h>
#include <stdlib.h>

int main(){

	//malloc	 申请连续空间			常用
	//calloc 	 申请空间+数据初始化     了解，效率不如malloc
	//realloc    修改空间大小			了解
	//free       释放空间			   常用
	//stdlib.h

	//1. 利用malloc申请一片连续的空间
	//存储10个int类型整数
	//返回这片空间的首地址
	int* p = malloc( 10 * sizeof(int));
	//int* p = calloc( 10 , sizeof(int));	  	//定义后直接自动初始化（0，0，0，0，0，0，0，0，0，0）

	//2.赋值
	for(int i=0;i<10;i++)
	{
		//两种不同的赋值方式
		// *(p + i) = (i + 1) * 10;  //1
		 p[i] = (i + 1) * 10;  //2
		//p[i] --->  *(p + i)
		//i[p] = (i + 1) * 10;	//3(阅读性差，一般不用)
		//p[i] --->  *(p + i)
	}
	
	//4.扩容	扩容时会把前面的数据赋值过来
	int* pp = realloc(p,20 * sizeof(int));

	//3.遍历
	for(int i=0;i<20;i++)
	{
		// printf("%d\n",*(p + i));
		printf("%d\n",p[i]);
	}

	//5.释放空间
	//如果申请的空间不用了一定记得释放！
	free(pp);

return 0;
}
