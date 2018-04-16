#include <stdio.h>
#include  <string.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 4
#define STACK_INCREMENT 1
#define MAXQSIZE 6
 typedef struct
{
	int a;//����Ϊ1����ȥΪ0
	int b;//���ƺ�
	double c;
}ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}Stack;
typedef struct
{
	ElemType *base;
	int front;
	int rear;
}Queue;
//����һ����ջ
void InitStack(Stack *S)
{
	S->base = (ElemType  * ) malloc(STACK_INIT_SIZE * sizeof(ElemType));
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}
//����ջ
void DestroyStack(Stack *S)
{
	free(S->base);
	S->base = S->top = NULL;
	S->stacksize = 0;
}
//��S��Ϊ��ջ
void ClearStack(Stack *S)
{
	if (S != NULL) S->top = S->base;
}
//��SΪ��ջ���򷵻�1�����򷵻�0
int StackEmpty(Stack S)
{
	return S.top==S.base;
}
//��ջ�ĳ���
int StackLength(Stack S)
{
	return S.top-S.base;
}
//����ջ��Ԫ��
int GetTop(Stack S,ElemType *e)
{
	if(S.base == S.top)
		return 0;
	*e=*(S.top-1);
	return 1;
}
//����Ԫ��
void Push(Stack *S,ElemType * e)
{
   * (S->top)= *e;
    S->top = S->top+1;
}
//ɾ��ջ��Ԫ��
int Pop(Stack *S,ElemType * e)
{
	if(S->base==S->top)
		return 0;
	*e = *(--S->top);
	return 1;
}
//����ջ�������
void StackTraverse(Stack S)
{
	printf("ͣ�����ڳ���\n");
	while(S.top!= S.base)
	{
		S.top--;
		printf("%d,%d,%.2lf\n",S.top->a,S.top->b,S.top->c);
	}
}
//���г�ʼ��
void  InitQueue(Queue *Q)
{
	Q->base=(ElemType *) malloc(MAXQSIZE * sizeof(ElemType));
	Q->front=Q->rear=0;
}
//���ٶ���
void DestroyQueue(Queue *Q)
{
	if(Q->base)
		free(Q->base);
	Q->base=NULL;
	Q->front=Q->rear=0;
}
//��ն���
void ClearQueue(Queue *Q)
{
	Q->front=Q->rear=0;
}
//�ж϶����Ƿ�Ϊ��
int  QueueEmpty(Queue Q)
{
	if(Q.front==Q.rear) return 1;
	return 0;
}
//����г�
int QueueLength(Queue Q)
{
	return (Q.rear+MAXQSIZE-Q.front)/MAXQSIZE;
}
//���ض���ͷԪ��
int GetHead(Queue Q,ElemType *e)
{
	if(Q.rear==Q.front)
		return 0;
	if(e != NULL)
		*e = Q.base[Q.front];
	return 1;
}
//����Ԫ������β
int  EnQueue(Queue *Q,ElemType e)
{
	if((Q->rear+1)%MAXQSIZE==Q->front)
	{
		printf("ERROR!\n");
		return 0;
	}
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQSIZE;
	return 1;
}
//ɾ������ͷԪ��
int DeQueue(Queue *Q,ElemType *e)
{
	if(Q->rear==Q->front)
		return 0;
	*e = Q->base[Q->front];
	Q->front=(Q->front+1)%MAXQSIZE;
	return 1;
}
//��������
void QueueTraverse(Queue Q)
{
	printf("��ʱ�Ⱥ����ϵĳ���\n");
	int i = Q.front;
	while(i != Q.rear)
	{
		printf("%d,%d,%.2lf\n",Q.base[i].a,Q.base[i].b,Q.base[i].c);
		i=(i+1)%MAXQSIZE;
	}
}
int main()
{
	Stack S;
	InitStack(&S);
	Queue Q;
	InitQueue(&Q);
	Stack S1;
	InitStack(&S1);
	ElemType E;
	scanf("%d%d%lf",&E.a,&E.b,&E.c);
	while(E.a != 2)
	{
		if(E.a == 1)
		{
			if(S.top-S.base<S.stacksize)
			{
				Push(&S,&E);
				printf("�����ɹ�����ͣ����\n");
			}
		    else
			{
				EnQueue(&Q,E);
				printf("������ʱͣ�ڵȺ�����\n");
			}
			StackTraverse(S);
	        QueueTraverse(Q);
		}
		if(E.a == 0)
		{
			ElemType * FLAG;
			FLAG = S.base;
			for( ;FLAG<=S.top && FLAG->b !=  E.b;FLAG++);
			if(FLAG<=S.top)
			{
				ElemType x,y;
				while(FLAG+1 != S.top)
				{
					Pop(&S,&x);
					Push(&S1,&x);
				}
				Pop(&S,&y);
				int money=(int)(E.c-y.c)*10;
				printf("���ƺ�Ϊ%d�ĳ����շ�Ϊ%d\n",E.b,money);
				while(S1.top != S1.base)
				{
					Pop(&S1,&y);
					Push(&S,&y);
				}
				if(!QueueEmpty(Q))
				{
					DeQueue(&Q,&x);
					Push(&S,&x);
				}
				StackTraverse(S);
	            QueueTraverse(Q);
			}
			if(FLAG>S.top)
				printf("�ó�������ͣ������\n");
		}
		scanf("%d%d%lf",&E.a,&E.b,&E.c);
	}
	char x[0]="w";
	if(x[0]!="@") return 0;
	DestroyStack(&S);
	DestroyQueue(&Q);
	DestroyStack(&S1);
	return 0;
}
