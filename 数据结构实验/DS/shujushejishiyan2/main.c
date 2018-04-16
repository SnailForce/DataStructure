#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	double a;
	int b;
}ElemType;
typedef struct tagLNode
{
    ElemType data;
	struct tagLNode * next;
}LNode,*LinkList;
///初始化线性表 L
void InitList(LinkList *L)
{
	*L=(LinkList)malloc(sizeof(LNode));
	(*L)->next=NULL;
}
//销毁链表 L
void DestroyList(LinkList *L)
{
	LinkList q,p=*L;
	while(p!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
	*L = NULL;
}
//求 L 的长度
int   ListLength(LinkList L)
{
	int i=0;
	LinkList p=L->next;
	while(p != NULL)
	{
		p=p->next;
		i++;
	}
	return i;
}
//获得 L 的第 i 个元素值
int GetElem(LinkList L,int i,ElemType *e)
{
	LinkList p=L;
	while(p != NULL && i>0)
	{
		p=p->next;
		i--;
	}
	if (p==NULL ||  p==L)
		return  0;
	*e = p->data;
	return 1;
}
///返回 L 中与 e 满足 compare 关系的元素位置
int  LocateElem(LinkList L,ElemType e,int  (* compare)(ElemType *,ElemType *))
{
	int i=0;
	LinkList p=L->next;
	while(p!=NULL)
	{
		i++;
		if (compare(&(p->data),&e))
			return i;
		p=p->next;
	}
	return 0;
}
//比较关系
int compare(int ep1,int ep2)
{
	if(ep1<ep2)
		return -1;
	if(ep1==ep2)
		return 0;
	if(ep1 > ep2)
		return 1;
	return 2;
}
//找前驱
LinkList  PriorElem(LinkList L,int  cur_e)
{
	LinkList q,p=L->next;
	while(p != NULL)
	{
		q=p->next;
		if(q !=NULL &&(q->data.b==cur_e ))
		{
			return p;
		}
		p=q;
	}
	return NULL;
}
///遍历 L
void ListTraverse(LinkList L)
{
	LinkList p=L;
	while(p != NULL)
	{
		p=p->next;
	}
}
//在 L 的第 i 个位置插入 e
int  ListInsert(LinkList * L,int i,ElemType e)
{
	LinkList s,p = * L;
	while( p != NULL && i>1)
	{
		p=p->next;
		i--;
	}
	if(p == NULL || i<1) return 0;
	s=(LinkList)malloc(sizeof(LNode));
	s->next = p->next;
	p->next = s;
	s->data = e;
	return 1;
}
///删除 L 的第 i 个元素
int  ListDelete(LinkList *L,int i,ElemType *e)
{
	LinkList s=NULL,p= *L;
	while(p!=NULL && i>1)
	{
		s=p;
		p=p->next;
		i--;
	}
	if(p == NULL || s==NULL) return 0;
	if(e != NULL) *e=p->data;
	free(p);
	return 1;
}
//动态创建链表
LinkList  ListCreate(LinkList L)
{
	LinkList s,q;
	s = (LinkList)malloc(sizeof(LNode));
	L->next=s;
	q=s;
	int n=0;
	puts("请输入多项式的系数和指数");
	scanf("%lf%d",&(s->data.a),&(s->data.b));
	while(s->data.a != 0)
	{
		n++;
		s=(LinkList)malloc(sizeof(LNode));
		q->next=s;
		scanf("%lf%d",&(s->data.a),&(s->data.b));
		if(s->data.a != 0) q=s;
	}
	q->next=NULL;
	L->data.b=n;
	return L;
}
//
int Output (LinkList L)
{
	LinkList s=L;
	printf("%d, ",L->data.b);
	while(s)
	{
		s=s->next;
		if(s !=NULL && s->data.a != 0)
		printf("%.1lf,%d, ",s->data.a,s->data.b);
	}
	s = NULL;
	return 0;
}
//
LinkList AddPolyn(LinkList L,LinkList R)
{
	puts("求和：");
	LinkList q1=L->next;
	LinkList q2=R->next;
	LinkList T;
	InitList(&T);
	LinkList w=T,m;
    while(q1 && q2)
	{
		double sum = 0;
		switch(compare(q1->data.b,q2->data.b))
		{
		case -1:
			m= (LinkList)malloc(sizeof(LNode));
			m->data.a = q1->data.a;
			m->data.b = q1->data.b;
			w->next =m;
			w=m;
			q1=q1->next;
			break;
		case 0:
		     sum = q1->data.a+q2->data.a;
		     if(sum != 0)
			 {
			 	m= (LinkList)malloc(sizeof(LNode));
			 	m->data.a = sum;
			 	m->data.b = q1->data.b;
			 	w->next = m;
			 	w=m;
			 }
             q1=q1->next;
             q2=q2->next;
             break;
		case 1:
			m= (LinkList)malloc(sizeof(LNode));
			m->data.a = q2->data.a;
			m->data.b = q2->data.b;
			w->next =m;
			w=m;
			q2=q2->next;
			break;
		}
	}
	if(q1 != NULL)
		w->next = q1;
	if(q2 != NULL)
		w->next = q2;
	if(q1 == NULL && q2 == NULL)
		w->next=NULL;
	T->data.b=ListLength(T);
	return T;
}
void Woutput(LinkList L)
{
	LinkList s=L;
	s=L->next;
	if(s->data.a != 0 && s->data.b==0)
		printf("%.1lf",s->data.a);
	if(s->data.a !=0 && s->data.b !=0)
		printf("%.1lfx^%d",s->data.a,s->data.b);
	while(s)
	{
		s=s->next;
		if(s != NULL && s->data.a >0&&s->data.b==0)
			printf("+%.1lf",s->data.a);
		if(s != NULL && s->data.a <0&&s->data.b==0)
			printf("%.1lfx^%d",s->data.a,s->data.b);
		if(s!=NULL && s->data.a > 0 && s->data.b != 0)
		    printf("+%.1lfx^%d",s->data.a,s->data.b);
	    if(s!=NULL && s->data.a < 0 && s->data.b !=0)
			printf("%.1lfx^%d",s->data.a,s->data.b);
	}
}
LinkList Qiudao(LinkList L)
{
	puts("求导：");
	LinkList s=L->next;
	LinkList Q;
	InitList(&Q);
	LinkList w=Q,m;
	while(s)
	{
		if(s->data.b != 0)
		{
			m= (LinkList)malloc(sizeof(LNode));
			m->data.a = (s->data.a)*(s->data.b);
			m->data.b = s->data.b-1;
			w->next = m;
			w=m;
			s=s->next;
		}
	}
	w->next=NULL;
	Q->data.b=ListLength(Q);
	return Q;
}
LinkList  SelectionSort(LinkList L)
{
	LinkList w=L;
	LinkList q;
	LinkList s=L->next;
	LinkList F;
	int t=0;
	while(w->next)
	{
		t=w->next->data.b;
		int flag=0;
		while(s)
		{
			if((s->data.b)<t && s!= NULL)
			{
				t=s->data.b;
				F=s;
				flag=1;
			}
			s=s->next;
		}
		if(flag)
		{
			q=PriorElem(L,F->data.b);
			q->next=F->next;
			F->next=w->next;
			w->next=F;
		}
		w=w->next;
		s=w->next;
	}
	return L;
}
LinkList  CF(LinkList L,LinkList R)
{
	LinkList p=L->next;
	LinkList X;
	InitList(&X);
	LinkList w=X,m;
	while(p)
	{
		LinkList q=R->next;
		while(q)
		{
			m= (LinkList)malloc(sizeof(LNode));
			m->data.a =(p->data.a)*(q->data.a);
			m->data.b = (p->data.b)+(q->data.b);
			w->next=m;
			w=m;
			q=q->next;
		}
		p=p->next;
	}
	w->next = NULL;
	return X;
}
LinkList  Combine(LinkList L)
{
	LinkList p,q,F;
	p=L->next;
	while(p)
	{
		F=p;
	    q=F->next;
		while(q)
		{
			if(q->data.b == p->data.b )
			{
				p->data.a = p->data.a+q->data.a;
				F->next = q->next;
				free(q);
			}
			F=q;
			q=F->next;
		}
		p=p->next;
	}
	L->data.b = ListLength(L);
	return L;
}
int main()
{
	LinkList  L,R,T,Q,X;
	InitList(&L);
	ListCreate(L);
	SelectionSort(L);
	InitList(&R);
	ListCreate(R);
	SelectionSort(R);
	T=AddPolyn(L,R);
	Output(T);
	printf("\n");
	Woutput(T);
	printf("\n");
	Q=Qiudao(L);
	Output(Q);
	printf("\n");
	Woutput(Q);

	X=CF(L,R);
	X=Combine(X);
	SelectionSort(X);
	printf("\n");
	Output(X);
	printf("\n");
	Woutput(X);
	DestroyList(&L);
	DestroyList(&R);
	DestroyList(&T);
	DestroyList(&Q);
	DestroyList(&X);
	return 0;
}
