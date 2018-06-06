/*
�����ʽ:
�����2�У�ÿ�зֱ��ȸ�������ʽ������ĸ���������ָ���ݽ���ʽ����һ������ʽ������ϵ����ָ��������ֵ��Ϊ������1000����������
���ּ��Կո�ָ���
��������:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
�����ʽ:
�����2�У��ֱ���ָ���ݽ���ʽ����˻�����ʽ�Լ��Ͷ���ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�
�����ʽӦ���0 0��
�������:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
coef : ϵ��
expon : ָ��
 
*/
# define null 0
typedef struct Polynode *Polynomial;
struct Polynode{
	int coef;
	int expon;
	Polynomial link;
};

Polynomial readPoly();
void attach(int c,int e, Polynomial* pRear);
Polynomial polySumFun(Polynomial p1, Polynomial p2); 
Polynomial polyMultFun(Polynomial p1, Polynomial p2);
void printPoly(Polynomial ps); 

int main(){
	
	Polynomial p1, p2,ps,pm;
	
	/*�������ж���ʽ*/
	p1 = readPoly();
	p2 = readPoly();
	
	/*���мӷ���˷�����*/
	ps = polySumFun(p1,p2); 
	pm = polyMultFun(p1,p2);
	
	/*�������ʽ*/ 
	printPoly(ps);
	printPoly(pm); 
	return 0;
} 

/*�������ʽ*/ 
void printPoly(Polynomial ps){
	int flag = 0;
	while(ps){
		if(!flag){
			printf(" ");
		}else{
			flag = 1;
		}
		
		printf("%d %d",ps->coef,ps->expon);
		flag ++;
		ps = ps->link;
	}
	printf("\n");
}
 
/*����ʽ�ӷ�����*/
Polynomial polySumFun(Polynomial p1, Polynomial p2){
	//����������ʽ����ͷ�սڵ�
	Polynomial rear,t,front;
	rear = (Polynomial)malloc(sizeof(struct Polynode));
	rear -> link = null; 
	front = rear; 
	
	while(p1 && p2){
		if(p1->expon == p2->expon){
			int c = p1->coef + p2->coef;
			if(c == 0 ){
				p1 = p1->link;
				p2 = p2->link;
			}else{
				attach(c,p1->expon, &rear);
				p1 = p1->link;
				p2 = p2->link;
			}
		}else if(p1->expon < p2->expon){
			attach(p2->coef,p2->expon, &rear);
			p2 = p2->link;
		}else if(p1->expon > p2->expon){
			attach(p1->coef,p1->expon, &rear);
			p1 = p1->link;
		}
	}
	while(p1){
		attach(p1->coef,p1->expon, &rear);
		p1 = p1->link;
	}
	while(p2){
		attach(p2->coef,p2->expon, &rear);
		p2 = p2->link;
	}
	//�ͷſսڵ�
	t = front;
	front = front -> link;
	free(t);
	return front;
}

/*����ʽ�˷�����*/
Polynomial polyMultFun(Polynomial p1, Polynomial p2){
	int c,e;
	Polynomial ps,t,front,rear,t1,t2;
	t1=p1; t2=p2;
	//����������ʽ����ͷ�սڵ�
	ps = (Polynomial)malloc(sizeof(struct Polynode));
	ps -> link = null; 
	front = ps; 
	
	//����һ���������ʽp1�ĵ�һ���ڵ����p2    //coef : ϵ��//expon : ָ��
	while(t2){
		c = t1->coef * t2->coef;
		e = t1->expon + t2->expon;
		attach(c,e,&rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	
	while(t1){
		t2 = p2;rear = ps;
		while(t2){
			c = t1->coef * t2->coef;
			e = t1->expon + t2->expon;
			while( rear->link && (rear->link->expon) > e){
				rear = rear->link;
			}
			//�ڵ����������ʽ
			if(e == rear->expon){ /*ָ�����,ֻ���޸�ϵ��*/
				if(c + rear->coef){
					rear->coef = c + rear->coef;
				}else{
					/*ɾ���ýڵ�*/
					t = rear;
					if(rear -> link){
						rear = rear -> link;
					}
					free(t);
				}
			}else if(){/*ָ��С��rear->expon ,�����½ڵ����*/ 
				
				
			} 
			
			
			t2=t2->link;
		}
		t1 = t1->link;
	}
	
	
	
	
	//�ͷſսڵ�
	t = front;
	front = front -> link;
	free(t);
	return front;
}

Polynomial readPoly(){
	int count, c, e;
	Polynomial p,t,front,rear;
	
	scanf("%d",&count);
	//����һ������ͷ�սڵ�
	rear = (Polynomial)malloc(sizeof(struct Polynode));
	//rear -> coef = 0;
	//rear -> expon = 0;
	rear ->link = null;
	front = rear; 
	while(count){
		scanf("%d %d",&c,&e);
		attach(c,e, &rear);
		count--;
	}
	//�ͷſսڵ�
	t = front;
	front = front -> link;
	free(t);
	return front;
}

void attach(int c,int e, Polynomial* pRear){
	//�¹���һ���ڵ�,��ƴ�ӵ��������ȥ
	Polynomial p;
	p = (Polynomial)malloc(sizeof(struct Polynode));
	p -> coef = c;
	p -> expon = e;
	p -> link = null;
	(*pRear) -> link = p;
	*pRear = p; 
}



