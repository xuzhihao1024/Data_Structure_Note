#include<stdio.h>

int main (){
	
	int i ;
	int j ;
	int num ;
	//��ȡ���и��� 
	int k = 0 ;
	scanf("%d",&k);
	
	//��������
	int* nums = (int*)malloc( k * sizeof(int));
	for(i=0 ;i<k ;i++){
		scanf("%d",&num);
		nums[i]=num;
	}
	
	int currentSum = 0,maxSum = 0;
	for(j=0; j<k; j++){
		currentSum += nums[j];
		if(currentSum >= maxSum){
			maxSum = currentSum;
		}
		if(currentSum < 0){
			currentSum=0;
		}
	} 
	printf("%d",maxSum);
	return 0;
} 
