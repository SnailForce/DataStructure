#include <iostream>
#include <malloc.h>
#include <cstdlib>
using namespace std;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}*BiTree;
struct Stack
{
	BiTree base;
	int top;
};
void InitStack(Stack &s)
{
	s.base=new BiTNode[100];
	s.top=0;
}
void push(Stack &s,BiTree e)
{
    BiTree a;
    a=s.base+s.top;;
    a=e;
    s.top++;
}
void pop(Stack &s,BiTree e)
{
		s.top--;
		e=s.base+s.top;
}
bool StackEmpty(Stack s)
{
    if(s.top==0)
        return true;
    else
        return false;
}
void InitBiTree(BiTree &T)
{
    T=NULL;
}
bool CreatBiTree(BiTree &T)
{
    char ch;
    if(ch==' ')
        T=NULL;
    else
    {
        if(!(T=(BiTree)malloc(sizeof(BiTNode))))
            return false;
        T->data=ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
    return true;
}
int BiTreeEmpty(BiTree T)
{
    int l=0,r=0;
    if(T)
    {
        l=BiTreeEmpty(T->lchild);
        r=BiTreeEmpty(T->rchild);
    }
    else
        return 0;
    if(l>r)
        return ++l;
    else
        return ++r;
}
void DestroyBiTree(BiTree &T)
{
    if(T)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        delete T;
        T=NULL;
    }
}
int InsertChild(BiTree &T,BiTree &p,int LR,BiTree &C)
{
    BiTree m=T;
    if(m==NULL)
    {
        m=C;
        return 0;
    }
    while(m)
    {
        if(LR==0)
        {
            if(m->data==p->data&&m->lchild==NULL)
            {
                m->lchild=C;
                return 1;
            }
            else
            {
                if(p->data<m->data)
                    m=m->lchild;
                else
                    m=m->rchild;
            }
        }
        if(LR==1)
        {
            if(m->data==p->data&&m->rchild==NULL)
            {
                m->rchild=C;
                return 1;
            }
            else
            {
                if(p->data<m->data)
                    m=m->lchild;
                else
                    m=m->rchild;
            }
        }
    }
    if(m==NULL)
        cout<<"未找到"<<endl;
    return 0;
}
void InOrderTraverse(BiTree T)
{
    Stack s;
    int i=0;
    InitStack(s);
    BiTree p=T;
    while(p||!StackEmpty(s))
    {
        if(p)
        {
            push(s,p);
            p=p->lchild;
        }
        else
        {
            pop(s,p);
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}
int main()
{
    int LR;
    char a;
    BiTree p,T,C;
    InitBiTree(T);
    cout<<"请按照中根顺序输入数据"<<endl;
    CreatBiTree(T);
    BiTreeEmpty(T);
    InOrderTraverse(T);
    cout<<"请输入要在哪里插入"<<endl;
    cin>>a;
    p->data=a;
    cout<<"请输入左还是右(0=左,1=右)"<<endl;
    cin>>LR;
    InitBiTree(C);
    CreatBiTree(C);
    InsertChild(T,p,LR,C);
    BiTreeEmpty(T);
    InOrderTraverse(T);
    DestroyBiTree(T);
    DestroyBiTree(C);
    return 0;
}
