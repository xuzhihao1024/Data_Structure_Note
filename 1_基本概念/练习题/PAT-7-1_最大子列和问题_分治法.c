#include<stdio.h>
int separateAndGovern(int arr[],int left,int right);
int max(int a,int b, int c); 

int main (){
	
	int i,j;
	int num,maxSum ;
	//获取序列个数 
	int k = 0 ;
	scanf("%d",&k);
	
	//构造数组
	int* nums = (int*)malloc( k * sizeof(int));
	for(i=0 ;i<k ;i++){
		scanf("%d",&num);
		nums[i]=num;
	}
	
	maxSum = separateAndGovern(nums,0,k-1);
	
	printf("%d",maxSum);
	return 0;
} 

/*分治法*/ 
int separateAndGovern(int arr[],int left,int right){
	int rightSumMax=0, leftSumMax=0;
	int center = (left + right) / 2;
	int a,b;
	//递归跳出的条件
	if(left == right){
		if(arr[left] > 0){
			return arr[left];
		}else{
			return 0 ;
		}
	} 
	//递归检查左边数组
	leftSumMax = separateAndGovern(arr,left,center); 
	//递归检查右边数组 
	rightSumMax = separateAndGovern(arr,center+1,right); 
	
	//向左扫描
	int currentLeftSum=0,currentMaxLeftSum=0;
	for(a = center; a>=left; a--){
		currentLeftSum += arr[a];
		if(currentLeftSum >currentMaxLeftSum){
			currentMaxLeftSum = currentLeftSum;
		}
	}
	int currentRightSum=0,currentMaxRightSum=0;
	//向右扫描 
	for(b = center+1; b<=right; b++){
		currentRightSum += arr[b];
		if(currentRightSum >currentMaxRightSum){
			currentMaxRightSum = currentRightSum;
		}
	}
	return max(leftSumMax,rightSumMax,(currentMaxLeftSum+currentMaxRightSum)); 
}

/*获取三个整数中的最大值*/
int max(int a ,int b, int c){
	return a>b?a>c?a:c:b>c?b:c;
}
 
