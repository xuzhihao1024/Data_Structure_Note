/*�������ı���-�������-�ݹ�ʵ��*/
#include<stido.h>

/*�����������������*/
typedef struct TreeNode *BinTree;
struct TreeNode {
	int date;
	BinTree left;
	BinTree right;
};

/*��ʼ��һ�Ŷ�����*/
BinTree initialBinTree(){
	int i;
	for(i=1;i<=7;i++){
		BinTree bt ;
		bt=(BinTree)malloc(sizeof(struct TreeNode));
		bt->date = 1;
	}
	
}
int main(){
	
	


	return 0;
}

/*������� ---> ��-��-��*/
void PreOrderTraversal(BinTree bt){
	if(bt){
		printf(bt->date);
		PreOrderTraversal(bt->left);
		PreOrderTraversal(bt->right);
	}
}