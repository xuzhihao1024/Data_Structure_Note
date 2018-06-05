#include<stdio.h>
#include<time.h>
#include<math.h>
/*
	给定多项式在给定点x处的值
	f(x)= 1*x1+2*x2+....+n-1*xn-1 +n*xn; 
*/
/*
	pow(x,y);//其作用是计算x的y次方。x、y及函数值都是double型 
	要加入头文件 math.h 
*/
/*
	clock()：捕捉从程序开始运行到clock()被调用时所耗费的时间。
	这个时间单位是clock_t，即"时钟打点"。
	常数CLK_TCK(或CLOCKS_PER_SEC)：机器时钟每秒所走的时钟打点数。
*/
double sumFun1(int n ,double x);
double sumFun2(int n ,double x);
clock_t start , end;
double duration;
#define Maxk 1e7  //define 后面不加; 
int main(){
	int i ;
	
	start = clock();
	for(i = 0 ; i<Maxk ;i++){
		sumFun1(10,1.1);
	} 
	end = clock();
	duration = (double)(end-start)/CLK_TCK/Maxk;
	printf("程序一运行了:%5.2e秒钟\n",duration);
	
	start = clock();
	for(i = 0 ; i<Maxk ;i++){
		sumFun2(10,1.1);
	} 
	end = clock();
	duration = (double)(end-start)/CLK_TCK/Maxk;
	//%e 用科学计数法输出 
	/*
		%e是按指数的形式输出  比如  4.22e5          
		e表示10的N次方
		5.2长度为5，小数点精确度为2，这个本身和%e没有关系，C语言的输出就是标准就这样
		详细点的说明就是 %m.ne 指定输出的数值共占m位，其中有n位小数。
		若数值长度小于m，则左端补空格。若数值长度大于m，则按实际数值输出，小数位保留n位
	*/ 
	printf("程序二运行了:%5.2e秒钟\n",duration);
	
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
