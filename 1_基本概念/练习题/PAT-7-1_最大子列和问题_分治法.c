#include<stdio.h>
int separateAndGovern(int arr[],int left,int right);
int max(int a,int b, int c); 

int main (){
	
	int i,j;
	int num,maxSum ;
	//��ȡ���и��� 
	int k = 0 ;
	scanf("%d",&k);
	
	//��������
	int* nums = (int*)malloc( k * sizeof(int));
	for(i=0 ;i<k ;i++){
		scanf("%d",&num);
		nums[i]=num;
	}
	
	maxSum = separateAndGovern(nums,0,k-1);
	
	printf("%d",maxSum);
	return 0;
} 

/*���η�*/ 
int separateAndGovern(int arr[],int left,int right){
	int rightSumMax=0, leftSumMax=0;
	int center = (left + right) / 2;
	int a,b;
	//�ݹ�����������
	if(left == right){
		if(arr[left] > 0){
			return arr[left];
		}else{
			return 0 ;
		}
	} 
	//�ݹ����������
	leftSumMax = separateAndGovern(arr,left,center); 
	//�ݹ����ұ����� 
	rightSumMax = separateAndGovern(arr,center+1,right); 
	
	//����ɨ��
	int currentLeftSum=0,currentMaxLeftSum=0;
	for(a = center; a>=left; a--){
		currentLeftSum += arr[a];
		if(currentLeftSum >currentMaxLeftSum){
			currentMaxLeftSum = currentLeftSum;
		}
	}
	int currentRightSum=0,currentMaxRightSum=0;
	//����ɨ�� 
	for(b = center+1; b<=right; b++){
		currentRightSum += arr[b];
		if(currentRightSum >currentMaxRightSum){
			currentMaxRightSum = currentRightSum;
		}
	}
	return max(leftSumMax,rightSumMax,(currentMaxLeftSum+currentMaxRightSum)); 
}

/*��ȡ���������е����ֵ*/
int max(int a ,int b, int c){
	return a>b?a>c?a:c:b>c?b:c;
}
 
