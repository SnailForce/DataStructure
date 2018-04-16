#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}*BiTree;
struct Stack
{
	BiTree *base;
	int top;
};
void InitStack(Stack &s)
{
	s.base=new BiTree[30];
	s.top=0;
}
void push(Stack &s,BiTree e)
{
    *(s.base+s.top)=e;
    s.top++;
}
void pop(Stack &s,BiTree &e)
{
		s.top--;
		e=*(s.base+s.top);
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
void CreatBiTree(BiTree &T)
{
    char ch;
    cin>>ch;
    if(ch=='#')
        T=NULL;
    else
    {
        T=new BiTNode;
        T->data=ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
}
int BiTreeEmpty(BiTree T)
{
    int l,r;
    if(T)
    {
        l=BiTreeEmpty(T->lchild);
        r=BiTreeEmpty(T->rchild);
        return (l>r)?(l+1):(r+1);
    }
    else
        return 0;
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
void InsertChild(BiTree &T,char a,int LR,char c)
{
    if(T)
    {
        if(T->data==a)
        {
            if(LR==0)
            {
                BiTree p=new BiTNode;
                p->data=c;
                p->lchild=p->rchild=NULL;
                T->lchild=p;
            }
            else
            {
                BiTree p=new BiTNode;
                p->data=c;
                p->lchild=p->rchild=NULL;
                T->rchild=p;
            }
        }
        else
        {
            InsertChild(T->lchild,a,LR,c);
            InsertChild(T->rchild,a,LR,c);
        }
    }
}
void InOrderTraverse(BiTree T)
{
    Stack s;
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
    int LR,L;
    char a,c;
    BiTree T;
    InitBiTree(T);
    cout<<"请输入二叉树的数据"<<endl;
    CreatBiTree(T);
    L=BiTreeEmpty(T);
    cout<<"二叉树的深度为"<<L<<endl;
    InOrderTraverse(T);
    cout<<endl;
    cout<<"请输入要在哪里插入"<<endl;
    cin>>a;
    cout<<"请输入左还是右(0=左,1=右)"<<endl;
    cin>>LR;
    cout<<"请输入插入二叉树的数据"<<endl;
    cin>>c;
    InsertChild(T,a,LR,c);
    L=BiTreeEmpty(T);
    cout<<"二叉树的深度为"<<L<<endl;
    InOrderTraverse(T);
    cout<<123;
    DestroyBiTree(T);
    return 0;
}
