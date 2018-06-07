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
	printPoly(pm); 
	printPoly(ps);
	return 0;
} 

/*�������ʽ*/ 
void printPoly(Polynomial ps){
	int flag = 0;
	if (!ps) {
		printf("0 0\n");
		return;
	}
		
	while(ps){
		if(!flag){
			flag = 1;
		}else{
			printf(" ");
		}
		printf("%d %d",ps->coef,ps->expon);
		ps = ps->link;
	}
	printf("\n");
}
 
/*����ʽ�ӷ�����*/
Polynomial polySumFun(Polynomial t1, Polynomial t2){
	//����������ʽ����ͷ�սڵ�
	Polynomial rear,t,front,p1,p2;
	if(!t1 && !t2){
		return null;
	}
	rear = (Polynomial)malloc(sizeof(struct Polynode));
	rear -> link = null; 
	front = rear;
	p1 = t1;p2=t2;
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
	if(!p1 && !p2){
		return null;
	}
	int c,e;
	Polynomial ps,t,front,rear,t1,t2;
	t1=p1; t2=p2;
	//����������ʽ����ͷ�սڵ�
	ps = (Polynomial)malloc(sizeof(struct Polynode));
	ps -> link = null; 
	front = ps; 
	rear = ps;
	//����һ���������ʽp1�ĵ�һ���ڵ����p2    //coef : ϵ��//expon : ָ��
	while(t2){
		c = t1->coef * t2->coef;
		e = t1->expon + t2->expon;
		attach(c,e,&rear);
		t2 = t2->link;
	}
	if(t1->link){
		t1 = t1->link;
	}
	while(t1){
		t2 = p2; rear = ps;
		while(t2){
			c = t1->coef * t2->coef;
			e = t1->expon + t2->expon;
			while( rear->link && (rear->link->expon) > e){
				rear = rear->link;
			}
			//�ڵ����������ʽ
			if( rear->link && e == rear->link->expon){ /*ָ�����,ֻ���޸�ϵ��*/
				if(c + rear->link->coef){
					rear->link->coef += c;
				}else{
					/*ɾ���ýڵ�*/
					t = rear->link;				
					rear->link = t->link;
					free(t);
				}
			}else{/*ָ��С��rear->expon ,�����½ڵ����*/ 
				t = (Polynomial)malloc(sizeof(struct Polynode));
				t->coef = c ;
				t->expon =e ;
				t->link = rear->link;
				rear->link = t;
				rear = t;
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
	Polynomial t,front,rear;
	
	scanf("%d",&count);
	//����һ������ͷ�սڵ�
	rear = (Polynomial)malloc(sizeof(struct Polynode));
	//rear -> coef = 0;
	//rear -> expon = 0;
	rear ->link = null;
	front = rear; 
	if(!count){
		return null;
	} 
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
	if(! *pRear){
		return ;
	}
	//�¹���һ���ڵ�,��ƴ�ӵ��������ȥ
	Polynomial p;
	p = (Polynomial)malloc(sizeof(struct Polynode));
	p -> coef = c;
	p -> expon = e;
	p -> link = null;
	if((*pRear) -> expon == e){
		(*pRear) -> coef += c;
	}
	(*pRear) -> link = p;
	*pRear = p; 
}



