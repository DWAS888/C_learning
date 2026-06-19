#include <stdio.h>

int main(){
	/*
	练习：
		利用代码拷贝文件
	要求:
		把桌面上的a.Wmv拷贝到桌面的aaa文件夹中
	*/ 
	
	//1.打开文件
	//	打开数据源 
	FILE* file1 = fopen("E:\\aaa.Code\\dev_c.c\\demo.exe","rb");
	//	打开目的地 
	FILE* file2 = fopen("E:\\aaa.Code\\dev_c.c\\aaa\\copy.exe","wb");
	
	//2.利用循环读取数据源，读完之后，再写到目的地
	char arr[1024];
	int n;
	while((n = fread(arr,1,1024,file1)) != 0){
		fwrite(arr,1,n,file2);
	}
	 

	//3.关闭文件
	fclose(file1) ;
	fclose(file2) ;
	return 0 ;
}
