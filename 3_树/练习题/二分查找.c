/*���ֲ���*/
#include<stdio.h> 
#define unfind -1
/*����n������Ԫ�صĹؼ����������򣨱��磺С���󣩲�����������ţ����飩����ô���Խ��ж��ֲ��ҡ�*/
int BinarySearch(int arr[],int length,int searchKey);

int main(){
	
	int arr[]={5,16,39,45,51,98,100,202,226,321,368,444,501}; 
	int arrLength = sizeof(arr)/sizeof(arr[0]);
	int result = BinarySearch(arr,arrLength,100);
	if(result!=-1){
		printf("��Ҫ���ҵ���ֵ�ڵ�%d��Ԫ��!\n",result);
	}else{
		printf("��Ҫ���ҵ���ֵδ�ҵ�!\n");
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

