/*二分查找*/
#include<stdio.h> 
#define unfind -1
/*假设n个数据元素的关键字满足有序（比如：小到大）并且是连续存放（数组），那么可以进行二分查找。*/
int BinarySearch(int arr[],int length,int searchKey);

int main(){
	
	int arr[]={5,16,39,45,51,98,100,202,226,321,368,444,501}; 
	int arrLength = sizeof(arr)/sizeof(arr[0]);
	int result = BinarySearch(arr,arrLength,100);
	if(result!=-1){
		printf("您要查找的数值在第%d个元素!\n",result);
	}else{
		printf("您要查找的数值未找到!\n");
	}
	return 0;
}

int BinarySearch(int arr[],int length,int searchKey){
	int left = 0 , right = length-1, mid;
	mid = (right + left)/2;
	while(left < right){
		if(arr[mid] < searchKey ){
			left = mid -1;
		}else if(arr[mid] > searchKey ){
			right = mid +1;
		}else{
			return mid;
		}
		mid = (right + left)/2;
	}
	return unfind;
	
}
