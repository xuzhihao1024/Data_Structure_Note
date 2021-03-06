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
	
	/*读入两行多项式*/
	p1 = readPoly();
	p2 = readPoly();
	
	/*进行加法与乘法运算*/
	ps = polySumFun(p1,p2); 
	pm = polyMultFun(p1,p2);
	
	/*输出多项式*/ 
	printPoly(pm); 
	printPoly(ps);
	return 0;
} 

/*输出多项式*/ 
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
 
/*多项式加法运算*/
Polynomial polySumFun(Polynomial t1, Polynomial t2){
	//构造结果多项式链表头空节点
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
	//释放空节点
	t = front;
	front = front -> link;
	free(t);
	return front;
}

/*多项式乘法运算*/
Polynomial polyMultFun(Polynomial p1, Polynomial p2){
	if(!p1 && !p2){
		return null;
	}
	int c,e;
	Polynomial ps,t,front,rear,t1,t2;
	t1=p1; t2=p2;
	//构造结果多项式链表头空节点
	ps = (Polynomial)malloc(sizeof(struct Polynode));
	ps -> link = null; 
	front = ps; 
	rear = ps;
	//构造一个结果多项式p1的第一个节点乘以p2    //coef : 系数//expon : 指数
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
			//节点插入结果多项式
			if( rear->link && e == rear->link->expon){ /*指数相等,只需修改系数*/
				if(c + rear->link->coef){
					rear->link->coef += c;
				}else{
					/*删除该节点*/
					t = rear->link;				
					rear->link = t->link;
					free(t);
				}
			}else{/*指数小于rear->expon ,构造新节点插入*/ 
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
	//释放空节点
	t = front;
	front = front -> link;
	free(t);
	return front;
}

Polynomial readPoly(){
	int count, c, e;
	Polynomial t,front,rear;
	
	scanf("%d",&count);
	//构造一个链表头空节点
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
	//释放空节点
	t = front;
	front = front -> link;
	free(t);
	return front;
}

void attach(int c,int e, Polynomial* pRear){
	if(! *pRear){
		return ;
	}
	//新构造一个节点,并拼接到链表后面去
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



