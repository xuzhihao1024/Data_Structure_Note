/*˳�����-�ڱ�*/
#include<stdio.h>
/*	��һ���ṹָ������,�ýṹ����������:
		1.ָ�������ͷ
		2.�����������ܹ����˶��ٸ�Ԫ��
*/
# define maxsize 50
typedef struct SequentialNode *PtrNode;
struct SequentialNode{
	/*ָ�������ͷ*/ 
	int elements[maxsize];  
	/*�����������ܹ����˶��ٸ�Ԫ��*/ 
	int length; 
};

int SequentialSearch(PtrNode p ,int searchKey); 

int main(){
	struct SequentialNode SNode = {
		/*����ĵ�һ��Ԫ��Ϊ�ڱ�,������Ԫ�ش��±�1��ʼ*/ 
		{0,2,5,6,9,1,7,4,8,66,42,10,41,86,74,213},
		15
	};
	printf("������Ҫ�ҵĹؼ�ֵ:\n"); 
	int searchKey ;
	scanf("%d",&searchKey);
	int k = SequentialSearch(&SNode,searchKey);
	if(k){
		printf("��Ҫ���ҵ���ֵ�ڵ�%d��Ԫ��!\n",k);
	}else{
		printf("��Ҫ���ҵ���ֵδ�ҵ�!\n");
	}
	return 0;
}


int SequentialSearch(PtrNode p ,int searchKey){
	/*�ڱ�Tbl[1]~Tbl[n]�в��ҹؼ���ΪK������Ԫ��*/
	int i ;
	/*�����ڱ�*/ 
	p->elements[0] = searchKey; 
	
	for(i=p->length;p->elements[i] != searchKey;i--); 	
	return i;
} 
