#include<stdio.h>
#include<time.h>
#include<math.h>
/*
	��������ʽ�ڸ�����x����ֵ
	f(x)= 1*x1+2*x2+....+n-1*xn-1 +n*xn; 
*/
/*
	pow(x,y);//�������Ǽ���x��y�η���x��y������ֵ����double�� 
	Ҫ����ͷ�ļ� math.h 
*/
/*
	clock()����׽�ӳ���ʼ���е�clock()������ʱ���ķѵ�ʱ�䡣
	���ʱ�䵥λ��clock_t����"ʱ�Ӵ��"��
	����CLK_TCK(��CLOCKS_PER_SEC)������ʱ��ÿ�����ߵ�ʱ�Ӵ������
*/
double sumFun1(int n ,double x);
double sumFun2(int n ,double x);
clock_t start , end;
double duration;
#define Maxk 1e7  //define ���治��; 
int main(){
	int i ;
	
	start = clock();
	for(i = 0 ; i<Maxk ;i++){
		sumFun1(10,1.1);
	} 
	end = clock();
	duration = (double)(end-start)/CLK_TCK/Maxk;
	printf("����һ������:%5.2e����\n",duration);
	
	start = clock();
	for(i = 0 ; i<Maxk ;i++){
		sumFun2(10,1.1);
	} 
	end = clock();
	duration = (double)(end-start)/CLK_TCK/Maxk;
	//%e �ÿ�ѧ��������� 
	/*
		%e�ǰ�ָ������ʽ���  ����  4.22e5          
		e��ʾ10��N�η�
		5.2����Ϊ5��С���㾫ȷ��Ϊ2����������%eû�й�ϵ��C���Ե�������Ǳ�׼������
		��ϸ���˵������ %m.ne ָ���������ֵ��ռmλ��������nλС����
		����ֵ����С��m������˲��ո�����ֵ���ȴ���m����ʵ����ֵ�����С��λ����nλ
	*/ 
	printf("�����������:%5.2e����\n",duration);
	
	return 0;
}

double sumFun1(int n ,double x){
	double sum = 0;
	int i;
	for(i = 1; i <= n; i++){
		sum += i*pow(x,i);
	}
	return sum;
}

double sumFun2(int n ,double x){
	double sum = n;
	int i;
	for(i = n; i >= 1; i--){
		sum = (n-1) + x*sum ;
	}
	return sum;
}
