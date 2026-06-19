#include <stdio.h>
#include <stdlib.h>

#define OK	1
#define ERROR	0
#define MAXSIZE	100

typedef int Status;
typedef char ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SqList, L;		//SqList* L 是指针 

Status ListInsert(SqList* L, int i, ElemType e)
{
	//1.如果线性表长度大于等于数组长度，则抛出异常或动态增加容量；
	if( L->length == MAXSIZE )
		return ERROR;
		
	//2.如果插入位置不合理，抛出异常；
	if(i < 1 || i > L->length + 1)
		return ERROR;

	//3.从最后个元素开始向前遍历到第个位置，分别将它们都向后移动一个位置；
	if(i <= L->length){
		for(int j = L->length - 1; j >= i-1 ;j--){
			L->data[j+1] = L->data[j];
		}
	}
	
	//4.将要插入元素填入位置处：
	L->data[i-1] = e; 
	
	//5.表长加1。
	L->length = L->length + 1;	
	
	return OK;
}

