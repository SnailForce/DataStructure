#include <stdio.h>
#include  <string.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 4
#define STACK_INCREMENT 1
#define MAXQSIZE 6
 typedef struct
{
	int a;//到达为1，离去为0
	int b;//车牌号
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
//构造一个空栈
void InitStack(Stack *S)
{
	S->base = (ElemType  * ) malloc(STACK_INIT_SIZE * sizeof(ElemType));
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}
//销毁栈
void DestroyStack(Stack *S)
{
	free(S->base);
	S->base = S->top = NULL;
	S->stacksize = 0;
}
//把S置为空栈
void ClearStack(Stack *S)
{
	if (S != NULL) S->top = S->base;
}
//若S为空栈，则返回1，否则返回0
int StackEmpty(Stack S)
{
	return S.top==S.base;
}
//求栈的长度
int StackLength(Stack S)
{
	return S.top-S.base;
}
//返回栈顶元素
int GetTop(Stack S,ElemType *e)
{
	if(S.base == S.top)
		return 0;
	*e=*(S.top-1);
	return 1;
}
//插入元素
void Push(Stack *S,ElemType * e)
{
   * (S->top)= *e;
    S->top = S->top+1;
}
//删除栈顶元素
int Pop(Stack *S,ElemType * e)
{
	if(S->base==S->top)
		return 0;
	*e = *(--S->top);
	return 1;
}
//遍历栈，并输出
void StackTraverse(Stack S)
{
	printf("停车场内车辆\n");
	while(S.top!= S.base)
	{
		S.top--;
		printf("%d,%d,%.2lf\n",S.top->a,S.top->b,S.top->c);
	}
}
//队列初始化
void  InitQueue(Queue *Q)
{
	Q->base=(ElemType *) malloc(MAXQSIZE * sizeof(ElemType));
	Q->front=Q->rear=0;
}
//销毁队列
void DestroyQueue(Queue *Q)
{
	if(Q->base)
		free(Q->base);
	Q->base=NULL;
	Q->front=Q->rear=0;
}
//清空队列
void ClearQueue(Queue *Q)
{
	Q->front=Q->rear=0;
}
//判断队列是否为空
int  QueueEmpty(Queue Q)
{
	if(Q.front==Q.rear) return 1;
	return 0;
}
//求队列长
int QueueLength(Queue Q)
{
	return (Q.rear+MAXQSIZE-Q.front)/MAXQSIZE;
}
//返回队列头元素
int GetHead(Queue Q,ElemType *e)
{
	if(Q.rear==Q.front)
		return 0;
	if(e != NULL)
		*e = Q.base[Q.front];
	return 1;
}
//插入元素至队尾
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
//删除队列头元素
int DeQueue(Queue *Q,ElemType *e)
{
	if(Q->rear==Q->front)
		return 0;
	*e = Q->base[Q->front];
	Q->front=(Q->front+1)%MAXQSIZE;
	return 1;
}
//遍历队列
void QueueTraverse(Queue Q)
{
	printf("临时等候便道上的车辆\n");
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
				printf("车辆成功进入停车场\n");
			}
		    else
			{
				EnQueue(&Q,E);
				printf("车辆暂时停在等候便道上\n");
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
				printf("车牌号为%d的车辆收费为%d\n",E.b,money);
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
				printf("该车辆不在停车场内\n");
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
