#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct ElemType{
    int hour;
    int money;
};
typedef struct SElemType{
    int CN;
    int hour;
    int pos;
};
typedef struct SqStack{
    SElemType *base;
    SElemType *top;
    int stacksize;
};
typedef struct QNode{
    SElemType data;
    QNode *next;
};
typedef struct Queue{
	QNode *first;
    QNode *rear;
};
//栈
void InitStack(SqStack *L,int maxs)
{
	L->base=(SElemType*)malloc(maxs*sizeof(SElemType));
	L->top=L->base;
	L->stacksize=maxs;
	return;
}
//获取栈顶元素
int Gettop(SqStack L,SElemType *e)
{
	if(L.top==L.base) return 0;
	*e=*(L.top-1);
	return 1;
}
//插入新元素f为栈顶元素
int Push(SqStack *S,SElemType e)
{
	if(S->top-S->base>=S->stacksize) return 0;
	*(S->top)=e;
	S->top++;
	return 1;
}
//删除栈顶元素，用g返回其值
int Pop(SqStack *L,SElemType *e)
{
	if(L->top==L->base) return 0;
	*e=*(L->top-1);
	L->top--;
	return 1;
}
//队列
void InitQueue(Queue *L,int maxq)
{
	int i;
	QNode *q;
	L->rear=new QNode;
	L->first=L->rear;
	L->first->next=NULL;
	for(i=2;i<=maxq;i++){
		L->rear->next=new QNode;
		L->rear=L->rear->next;
		L->rear->next-NULL;
	}
	L->rear->next=L->first;
	L->rear=L->first;
	return;
}
//插入元素e为新的队尾元素,队列长度不发生变化
int EnQueue(Queue *L,SElemType e)
{
	if(L->rear->next==L->first) return 0;
	L->rear->data=e;
	L->rear=L->rear->next;
	return 1;
}
//删除队头元素，用g返回其值.队列长度不发生变化
int DeQueue(Queue *L,SElemType *e)
{
	if(L->first==L->rear) return 0;
	e->CN=L->first->data.CN;
	e->hour=L->first->data.hour;
	e->pos=L->first->data.pos;
	L->first=L->first->next;
	return 1;
}
//若队列为空,返回1,非空,返回0
int QueueEmpty(Queue L)
{
	if(L.first==L.rear) return 1;
	else return 0;
}
//返回队列元素个数
int QueueLength(Queue L)
{
	int i;
	QNode *q;
	q=L.first;
	for(i=0;q!=L.rear;){
		q=q->next;
		i++;
	}
	return i;
}
int QucheS(SqStack *S,SElemType q,ElemType *T)
{
	SElemType *p;
	p=S->base;
	int i,length;
	length=S->top-S->base+1;
    for(i=1;p->CN!=q.CN&&i<=length;){
		p++;
		if(p->CN!=q.CN) i++;
    }
    if(i<=length){
    T->hour=p->hour;
    T->money=(q.hour-p->hour)*10;
    for(i=1;i<=S->top-p-1;i++){
		p->hour=(p+1)->hour;
		p->CN=(p+1)->CN;
		p++;
    }
    p->CN=0;
    p->hour=0;
    S->top=S->top-1;
    return 1;
    }
    else return 0;
}
int QucheQ(SqStack *S,Queue *L,SElemType q,ElemType *T)
{
	cout<<"--------1-------"<<endl;
	SElemType *p,e;
	p=S->base;
	QNode *u,*pre;
	int i=0,length;
	length=S->top-S->base+1;
    for(i=1;p->CN!=q.CN&&i<=length;){
		p++;
		if(p->CN!=q.CN) i++;
    }
    if(i<=length){
		T->hour=p->hour;
		T->money=(q.hour-p->hour)*10;
		for(i=1;i<=S->top-p-1;i++){
			p->hour=(p+1)->hour;
			p->CN=(p+1)->CN;
			p++;
		}
		p->CN=0;
		p->hour=0;
		S->top=S->top-1;
		DeQueue(L,&e);
		Push(S,e);
		return 1;
    }//所取车位于停车场
    else{
		i=0;
		u=L->first;
        if(u->data.CN!=q.CN){
			for(i=1;u->data.CN!=q.CN&&i<=QueueLength(*L);){
				pre=u;
				u=u->next;
				if(u->data.CN!=q.CN) i++;
		    }
	    }
		if(i<=QueueLength(*L)&&i!=0){//所停车不位于first
		    pre->next=u->next;
		    u->next=L->rear->next;
		    L->rear->next=u;
		    return 2;//所取车位于候车道
		}
        else if(i==0){//所停车位于first
			DeQueue(L,&e);
			return 2;//所取车位于候车道
        }
		else return 0;//所取车不在
    }
}
int main()
{
	int maxstacksize,maxqueuesize,i,tip;
	SElemType e,f,g,quche;
	ElemType time;
	SqStack S;
	Queue Q;
	cout<<"输入临时停车道所能等候车数:"<<endl;
	cin>>maxqueuesize;
	InitQueue(&Q,maxqueuesize+1);
    cout<<"输入停车场所能停放车数:"<<endl;
	cin>>maxstacksize;
	InitStack(&S,maxstacksize);
	for(;;){
	    cout<<"停车请输入1，取车请输入2，操作结束请输入3"<<endl;
	    cin>>tip;
		if(tip==1){
			if(S.top-S.base<maxstacksize){//停车场未满
				cout<<"请输入车牌号"<<endl;
				cin>>S.top->CN;
				cout<<"请输入当前时间"<<endl;
				cin>>S.top->hour;
				S.top->pos=S.top-S.base+1;
				cout<<"您于成功将车停放于停车场内第"<<S.top->pos<<"位"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
				S.top++;
			}
			else if(S.top-S.base==maxstacksize&&QueueLength(Q)<maxqueuesize){//停车场已满，候车道未满
				cout<<"请输入车牌号"<<endl;
				cin>>Q.rear->data.CN;
				cout<<"请输入当前时间"<<endl;
				cin>>Q.rear->data.hour;
				Q.rear->data.pos=QueueLength(Q)+1;
				cout<<"您正位于候车道第"<<Q.rear->data.pos<<"位"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
				Q.rear=Q.rear->next;
			}
			else if(S.top-S.base==maxstacksize&&QueueLength(Q)==maxqueuesize){
				cout<<"提示:停车场和候车道已满，请前往其他停车场停车"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
			}
		}
		else if(tip==2){
				cout<<"请输入车牌号"<<endl;
				cin>>quche.CN;
				cout<<"请输入当前时间"<<endl;
				cin>>quche.hour;
				quche.pos=0;
				if(S.top-S.base<=maxstacksize&&QueueLength(Q)==0){//候车道无车等候
					if(QucheS(&S,quche,&time)==1){
					cout<<"车牌号:"<<quche.CN<<endl;
					cout<<"取车时间:"<<quche.hour<<"时"<<endl;
					cout<<"停车时间:"<<time.hour<<"时"<<endl;
					cout<<"应收取费用:"<<time.money<<"元"<<endl;
					}
					else if(QucheS(&S,quche,&time)==0){
						cout<<"该车未停入停车场"<<endl;
						cout<<"应收取费用:0元"<<endl;
					}
				}
				else if(QueueLength(Q)!=0){//候车道有车等候
					i=QucheQ(&S,&Q,quche,&time);
					if(i==1){
					cout<<"<<<<<1<<<<<"<<endl;
					cout<<"车牌号:"<<quche.CN<<endl;
					cout<<"取车时间:"<<quche.hour<<"时"<<endl;
					cout<<"停车时间:"<<time.hour<<"时"<<endl;
					cout<<"应收取费用:"<<time.money<<"元"<<endl;
					}
					else if(i==2){
						cout<<"<<<<<3<<<<<"<<endl;
						cout<<"该车位于候车道"<<endl;
						cout<<"应收取费用:0元"<<endl;
					}
                    else if(i==0){
						cout<<"<<<<<2<<<<<"<<endl;
						cout<<"该车未停入停车场、候车道"<<endl;
						cout<<"应收取费用:0元"<<endl;
					}
				}
		}
		else if(tip==3){
			cout<<"操作结束"<<endl;
			break;
		}
    }
	return 0;
}
