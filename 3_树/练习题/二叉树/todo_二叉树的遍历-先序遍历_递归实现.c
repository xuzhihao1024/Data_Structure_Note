/*二叉树的遍历-先序遍历-递归实现*/
#include<stido.h>

/*定义用链表定义二叉树*/
typedef struct TreeNode *BinTree;
struct TreeNode {
	int date;
	BinTree left;
	BinTree right;
};

/*初始化一颗二叉树*/
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

/*先序遍历 ---> 根-左-右*/
void PreOrderTraversal(BinTree bt){
	if(bt){
		printf(bt->date);
		PreOrderTraversal(bt->left);
		PreOrderTraversal(bt->right);
	}
}