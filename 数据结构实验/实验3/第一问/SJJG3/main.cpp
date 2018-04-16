#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct SElemType{
    int CN;
    int hour;
    /*int minute;
    int pos;*/
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

int main()
{
	int maxstacksize,maxqueuesize,i;
	SElemType e,f,g;
	SqStack S;
	Queue Q;
//����
	cout<<"������г���:"<<endl;
	cin>>maxqueuesize;
//��������
	InitQueue(&Q,maxqueuesize+1);
//�������
	cout<<"�������"<<endl;
	for(i=1;i<=maxqueuesize;i++){
	    cin>>Q.rear->data.CN>>Q.rear->data.hour;
	    Q.rear=Q.rear->next;
	}
	cout<<"QueueEmpty:"<<QueueEmpty(Q)<<endl;
    cout<<"QueueLength:"<<QueueLength(Q)<<endl;
//ɾ����ͷԪ�أ���g������ֵ.����Ԫ�ظ�����1
    DeQueue(&Q,&g);
    cout<<"g:"<<g.CN<<" "<<g.hour<<endl;
    cout<<"QueueEmpty:"<<QueueEmpty(Q)<<endl;
    cout<<"QueueLength:"<<QueueLength(Q)<<endl;


//����Ԫ��eΪ�µĶ�βԪ��
    f={0,0};
    EnQueue(&Q,f);
    for(i=1;Q.first!=Q.rear;i++){
    cout<<Q.first->data.CN<<" "<<Q.first->data.hour<<endl;
    Q.first=Q.first->next;
    }
//ջ
	/*cout<<"����ջ����:"<<endl;
	cin>>maxstacksize;
//����ջ
	InitStack(&S,maxstacksize);
//����ջ
	cout<<"����ջ"<<endl;
	for(i=1;i<=maxstacksize-1;i++){
	    cin>>S.top->CN>>S.top->hour;
	    S.top++;
	}
	for(;S.top!=S.base;){
		cout<<"CN:"<<(S.top-1)->CN<<"  hour:"<<(S.top-1)->hour<<endl;
	    S.top--;
    }*/
//��ȡջ��Ԫ��
	/*Gettop(S,&e);
	cout<<e.CN<<" "<<e.hour<<endl;
	for(;S.top!=S.base;){
		cout<<"CN:"<<(S.top-1)->CN<<"  hour:"<<(S.top-1)->hour<<endl;
	    S.top--;
    }*/
//������Ԫ��fΪջ��Ԫ��
	/*f={0,0};
	Push(&S,f);
	for(;S.top!=S.base;){
		cout<<"CN:"<<(S.top-1)->CN<<"  hour:"<<(S.top-1)->hour<<endl;
	    S.top--;
    }
//ɾ��ջ��Ԫ�أ���g������ֵ
	/*Pop(&S,&g);
	cout<<g.CN<<" "<<g.hour<<endl;
	for(;S.top!=S.base;){
		cout<<"CN:"<<(S.top-1)->CN<<"  hour:"<<(S.top-1)->hour<<endl;
	    S.top--;
    }*/



	cout << "Hello world!" << endl;
	return 0;
}
