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
//ջ
void InitStack(SqStack *L,int maxs)
{
	L->base=(SElemType*)malloc(maxs*sizeof(SElemType));
	L->top=L->base;
	L->stacksize=maxs;
	return;
}
//��ȡջ��Ԫ��
int Gettop(SqStack L,SElemType *e)
{
	if(L.top==L.base) return 0;
	*e=*(L.top-1);
	return 1;
}
//������Ԫ��fΪջ��Ԫ��
int Push(SqStack *S,SElemType e)
{
	if(S->top-S->base>=S->stacksize) return 0;
	*(S->top)=e;
	S->top++;
	return 1;
}
//ɾ��ջ��Ԫ�أ���g������ֵ
int Pop(SqStack *L,SElemType *e)
{
	if(L->top==L->base) return 0;
	*e=*(L->top-1);
	L->top--;
	return 1;
}
//����
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
//����Ԫ��eΪ�µĶ�βԪ��,���г��Ȳ������仯
int EnQueue(Queue *L,SElemType e)
{
	if(L->rear->next==L->first) return 0;
	L->rear->data=e;
	L->rear=L->rear->next;
	return 1;
}
//ɾ����ͷԪ�أ���g������ֵ.���г��Ȳ������仯
int DeQueue(Queue *L,SElemType *e)
{
	if(L->first==L->rear) return 0;
	e->CN=L->first->data.CN;
	e->hour=L->first->data.hour;
	e->pos=L->first->data.pos;
	L->first=L->first->next;
	return 1;
}
//������Ϊ��,����1,�ǿ�,����0
int QueueEmpty(Queue L)
{
	if(L.first==L.rear) return 1;
	else return 0;
}
//���ض���Ԫ�ظ���
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
    }//��ȡ��λ��ͣ����
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
		if(i<=QueueLength(*L)&&i!=0){//��ͣ����λ��first
		    pre->next=u->next;
		    u->next=L->rear->next;
		    L->rear->next=u;
		    return 2;//��ȡ��λ�ں򳵵�
		}
        else if(i==0){//��ͣ��λ��first
			DeQueue(L,&e);
			return 2;//��ȡ��λ�ں򳵵�
        }
		else return 0;//��ȡ������
    }
}
int main()
{
	int maxstacksize,maxqueuesize,i,tip;
	SElemType e,f,g,quche;
	ElemType time;
	SqStack S;
	Queue Q;
	cout<<"������ʱͣ�������ܵȺ���:"<<endl;
	cin>>maxqueuesize;
	InitQueue(&Q,maxqueuesize+1);
    cout<<"����ͣ��������ͣ�ų���:"<<endl;
	cin>>maxstacksize;
	InitStack(&S,maxstacksize);
	for(;;){
	    cout<<"ͣ��������1��ȡ��������2����������������3"<<endl;
	    cin>>tip;
		if(tip==1){
			if(S.top-S.base<maxstacksize){//ͣ����δ��
				cout<<"�����복�ƺ�"<<endl;
				cin>>S.top->CN;
				cout<<"�����뵱ǰʱ��"<<endl;
				cin>>S.top->hour;
				S.top->pos=S.top-S.base+1;
				cout<<"���ڳɹ�����ͣ����ͣ�����ڵ�"<<S.top->pos<<"λ"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
				S.top++;
			}
			else if(S.top-S.base==maxstacksize&&QueueLength(Q)<maxqueuesize){//ͣ�����������򳵵�δ��
				cout<<"�����복�ƺ�"<<endl;
				cin>>Q.rear->data.CN;
				cout<<"�����뵱ǰʱ��"<<endl;
				cin>>Q.rear->data.hour;
				Q.rear->data.pos=QueueLength(Q)+1;
				cout<<"����λ�ں򳵵���"<<Q.rear->data.pos<<"λ"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
				Q.rear=Q.rear->next;
			}
			else if(S.top-S.base==maxstacksize&&QueueLength(Q)==maxqueuesize){
				cout<<"��ʾ:ͣ�����ͺ򳵵���������ǰ������ͣ����ͣ��"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
			}
		}
		else if(tip==2){
				cout<<"�����복�ƺ�"<<endl;
				cin>>quche.CN;
				cout<<"�����뵱ǰʱ��"<<endl;
				cin>>quche.hour;
				quche.pos=0;
				if(S.top-S.base<=maxstacksize&&QueueLength(Q)==0){//�򳵵��޳��Ⱥ�
					if(QucheS(&S,quche,&time)==1){
					cout<<"���ƺ�:"<<quche.CN<<endl;
					cout<<"ȡ��ʱ��:"<<quche.hour<<"ʱ"<<endl;
					cout<<"ͣ��ʱ��:"<<time.hour<<"ʱ"<<endl;
					cout<<"Ӧ��ȡ����:"<<time.money<<"Ԫ"<<endl;
					}
					else if(QucheS(&S,quche,&time)==0){
						cout<<"�ó�δͣ��ͣ����"<<endl;
						cout<<"Ӧ��ȡ����:0Ԫ"<<endl;
					}
				}
				else if(QueueLength(Q)!=0){//�򳵵��г��Ⱥ�
					i=QucheQ(&S,&Q,quche,&time);
					if(i==1){
					cout<<"<<<<<1<<<<<"<<endl;
					cout<<"���ƺ�:"<<quche.CN<<endl;
					cout<<"ȡ��ʱ��:"<<quche.hour<<"ʱ"<<endl;
					cout<<"ͣ��ʱ��:"<<time.hour<<"ʱ"<<endl;
					cout<<"Ӧ��ȡ����:"<<time.money<<"Ԫ"<<endl;
					}
					else if(i==2){
						cout<<"<<<<<3<<<<<"<<endl;
						cout<<"�ó�λ�ں򳵵�"<<endl;
						cout<<"Ӧ��ȡ����:0Ԫ"<<endl;
					}
                    else if(i==0){
						cout<<"<<<<<2<<<<<"<<endl;
						cout<<"�ó�δͣ��ͣ�������򳵵�"<<endl;
						cout<<"Ӧ��ȡ����:0Ԫ"<<endl;
					}
				}
		}
		else if(tip==3){
			cout<<"��������"<<endl;
			break;
		}
    }
	return 0;
}
