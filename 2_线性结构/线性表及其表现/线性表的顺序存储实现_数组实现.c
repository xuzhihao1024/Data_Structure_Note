#include<stdio.h>
#define MAXSIZE 100

typedef struct LNode *List;
typedef int Position;
struct LNode{
	ElementType Data[MAXSIZE];
	Position Last;
} L ;

/*初始化(建立空的顺序表)*/
List makeEmpty(){
	List PtrL; 
	PtrL = (List)malloc(sizeof(struct LNode)); 
	PtrL -> Last = -1;
	return PtrL;
}

/*查找*/
#define ERROR -1
int find(ElementType data,List ptrl){
	int i = 0;
	while(i<=ptrl->last && ptrl->Data[i] != data){
		i++;
	}
	if(i > ptrl->last){
		return ERROR;
	}
	return i;
}

/*插入*/


/*删除*/
