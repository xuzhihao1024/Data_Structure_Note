#include<stdio.h>
#define MAXSIZE 100

typedef struct LNode *List;
typedef int Position;
struct LNode{
	ElementType Data[MAXSIZE];
	Position Last;
} L ;

/*��ʼ��(�����յ�˳���)*/
List makeEmpty(){
	List PtrL; 
	PtrL = (List)malloc(sizeof(struct LNode)); 
	PtrL -> Last = -1;
	return PtrL;
}

/*����*/
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

/*����*/


/*ɾ��*/
