/*顺序查找-哨兵*/
#include<stdio.h>
/*	用一个结构指向数组,该结构有两个分量:
		1.指向数组的头
		2.该数组里面总共放了多少个元素
*/
# define maxsize 50
typedef struct SequentialNode *PtrNode;
struct SequentialNode{
	/*指向数组的头*/ 
	int elements[maxsize];  
	/*该数组里面总共放了多少个元素*/ 
	int length; 
};

int SequentialSearch(PtrNode p ,int searchKey); 

int main(){
	struct SequentialNode SNode = {
		/*数组的第一个元素为哨兵,真正的元素从下标1开始*/ 
		{0,2,5,6,9,1,7,4,8,66,42,10,41,86,74,213},
		15
	};
	printf("请输入要找的关键值:\n"); 
	int searchKey ;
	scanf("%d",&searchKey);
	int k = SequentialSearch(&SNode,searchKey);
	if(k){
		printf("您要查找的数值在第%d个元素!\n",k);
	}else{
		printf("您要查找的数值未找到!\n");
	}
	return 0;
}


int SequentialSearch(PtrNode p ,int searchKey){
	/*在表Tbl[1]~Tbl[n]中查找关键字为K的数据元素*/
	int i ;
	/*建立哨兵*/ 
	p->elements[0] = searchKey; 
	
	for(i=p->length;p->elements[i] != searchKey;i--); 	
	return i;
} 
