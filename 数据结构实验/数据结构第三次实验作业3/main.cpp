/*#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;
#define maxstacksize 4
#define maxSqQueuesize 5
typedef struct DataType
{
	string s;
	int j;
	int time;
}*Links;
typedef struct SqStack
{
	Links base;
	int top;
	int stacksize;
}*SLink;
typedef struct SqQueue
{
	Links base;
	int first;
    int rear;
}*QLink;
void InitStack(SqStack &s)
{
	s.base=new DataType[4];
	s.top=0;
	s.stacksize=4;
}//������ջ
void InitSqQueue(SqQueue &q)
{
	q.base = new DataType[6];
	q.first = q.rear = 0;
}//�����ն���
void push(SqStack &s,DataType e)
{
    *(s.base+s.top)=e;
    s.top++;
}//��ջ
void enSqQueue(SqQueue &q, DataType e)
{
	*(q.base+q.rear)=e;
	q.rear=(q.rear+1)%6;
}//�����
bool pop(SqStack &s, DataType e)
{
	if (s.top == 0)
		return false;
		--s.top;
		e = *(s.base+s.top);
		return true;
}//��ջ
void DeSqQueue(SqQueue &q,DataType &e)
{
	e=*(q.base+q.first);
	q.first=(q.first+1)%6;
	cout<<"1."<<q.first;
}//������
void Input(DataType &e,int i)
{
	e.j=i;
	cout<<"���복�����ƺ�"<<endl;
	cin>>e.s;
}//���복����Ϣ
Links search(SqStack s, DataType e)
{
	Links t;
	for(int i=0;i<4;i++)
	{
        t=s.base+i;
		if(t->s==e.s)
		{
			return t;
		}
	}
	return 0;
}
void arrange(SqStack &s, SqQueue &q,DataType e)
{
	Links t=s.base;
	int n=s.top,m;
	DataType f;
	while(1)
	{
		if(t->time<=e.time)
		{
			t++;
		}
		else
		{
		    int i=t-s.base;
		    if(i==1)
               {
                   if(n==1)
                      s.base=NULL;
                   else
                   {
                       if(n==2)
                       {
                           *(s.base)=*(s.base+1);
                           t=s.base+1;
                           t=NULL;
                       }
                       else
                        {
                            if(n==3)
                            {
                                *(s.base)=*(s.base+1);
                                *(s.base+1)=*(s.base+2);
                                t=s.base+2;
                                t=NULL;
                            }
                            else
                            {
                                if(n==4)
                                {
                                    *(s.base)=*(s.base+1);
                                    *(s.base+1)=*(s.base+2);
                                    *(s.base+2)=*(s.base+3);
                                    t=s.base+3;
                                    t=NULL;
                                }
                            }
                        }
                   }
               }
               if(i==2)
               {
                   if(n==2)
                   {
                       t=s.base+1;
                       t=NULL;
                   }
                   else
                   {
                       if(n==3)
                       {
                          *(s.base+1)=*(s.base+2);
                          t=s.base+2;
                          t=NULL;
                       }
                       else
                       {
                           if(n==4)
                           {
                                *(s.base+1)=*(s.base+2);
                                *(s.base+2)=*(s.base+3);
                                t=s.base+3;
                                t=NULL;
                           }
                       }
                   }
               }
               if(i==3)
               {
                   if(n==3)
                   {
                       t=s.base+2;
                       t=NULL;
                   }
                   else
                   {
                       if(n==4)
                       {
                           *(s.base+2)=*(s.base+3);
                            t=s.base+3;
                            t=NULL;
                       }
                   }
               }
               if(i==4)
               {
                  t=s.base+3;
                  t=NULL;
               }
            if(q.first!=q.rear)
            {
                DeSqQueue(q,f);
                f.time=e.time;
                s.top--;
                push(s,f);
            }
            break;
		}
	}
}
int get(SqStack s,SqQueue q,string r)
{
    DataType e;
    Links j;
    for(int i=0;i<=3;i++)
    {
        j=s.base;
        j+=i;
        if(j->s==r)
        {
            cout<<"���ƺ�Ϊ"<<r<<"��ͣ����"<<i+1<<"��λ"<<endl;
            return 0;
        }
    }
    for(int i=0;i<6;i++)
    {

        j=q.base;
        j+=i;
        if(j->s==r)
        {
            cout<<"���ƺ�Ϊ"<<r<<"�ó�����ʱͣ���"<<i+1-q.first<<"��λ"<<endl;
            return 0;
        }
    }
}
int main()
{
	SqStack s;
	SqQueue q;
	Links f,n;
	int t,j=0,k=0,l=0;
	string r;
	InitStack(s);
	InitSqQueue(q);
	while (1)
	{
		cout<<"1:���" <<"2:����"<<"3.����"<<"4.�˳�"<<endl;
		cout<<"������Ҫ���еĲ���"<<endl;
		cin>>t;
		if(t==1)
		{
			if(s.top==4)
			{
				cout<<"ͣ��������"<<endl;
				if((q.rear+1)%6==q.first)
				{
					cout<<"��ʱ�Ⱥ�������"<<endl;
				}
				else
				{
					cout<<"�ó���������ʱ�Ⱥ���"<<" "<<"����ó��������Ϣ"<<endl;
					DataType e;
					Input(e,++l);
					enSqQueue(q,e);
					get(s,q,e.s);
				}
			}
            else
			{
                DataType e;
				Input(e,++j);
				cout<<"����ó�������ͣ������ʱ��"<<endl;
				cin>>e.time;
				push(s,e);
				get(s,q,e.s);
			}
		}
		if(t==2)
		    {
				cout<<"����Ҫ����ĳ��ƺ�"<<endl;
				DataType e;
				cin>>e.s;
				cout<<"�������ʱ��"<<endl;
				cin>>e.time;
				f=search(s,e);
				cout<<e.time-f->time<<"dollars"<<endl;
				arrange(s,q,*f);
		    }
        if(t==3)
        {
            cout<<"����Ҫ���ҵĳ��ƺ�"<<endl;
            cin>>r;
            get(s,q,r);
        }
		if(t==4)
		{
		    cout<<"���Ѿ��˳���ϵͳ"<<endl;
			break;
		}
    for(int a=0;a<=3;a++)
    {
        Links b;
        b=s.base;
        b+=a;
        cout<<b->s<<" ";
    }
    cout<<endl;
        int b;
        b=q.first;
    for(;b<5;b++)
    {
        Links c;
        c=q.base+b;
        cout<<c->s<<" ";
	}
	cout<<endl;
	}
	return 0;
}*/
typedef struct SqQueue
{
	Elemtype *base;
	int first;
    int rear;
    bool tag;
};//���нṹ��
void InitSqQueue(SqQueue &q)
{
    int i;
    cout<<"����ѭ������Ҫ����Ŀռ�"<<endl;
    cin>>i;
	q.base = new DataType[i];
	q.first = q.rear = 0;
}//�����ն���
