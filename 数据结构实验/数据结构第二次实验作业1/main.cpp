#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct LNode
{
   double data;
   LNode *next;
}LNode,*Link;
//定义结构体
void InitList(Link &L)
{
    L=new LNode;
    L->next=NULL;
}
//初始化链表
void DestroyList(Link &L)
{
    Link a;
    while(L)
    {
        a=L;
        L=L->next;
        delete a;
    }
    L=NULL;
}
//销毁链表
int ListLength(Link L)
{
    int i=0;
    Link p=L;
    while(p)
    {
        p=p->next;
        i++;
    }
    i--;
    return i;
}
//求链表长度
bool GetElem(Link L,int i,double *e)
{
    Link p;
    p=L->next;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i)
        return false;
    else
    {
        *e=p->data;
        return true;
    }
}
//获得链表的第i个值
int compare(Link &a,Link b)
{
    if(a->data==b->data)
       return 1;
     else
       return 0;
}
//比较函数
int LocateElem(Link L,LNode e)
{
   int i=1;
   Link p=L->next;
   while(p)
         {
             if(!(compare(p,&e)))
             {
               i++;
               p=p->next;
             }
             else
                return i;
         }
   return 0;
}
//定位具有比较函数性质的函数
int PriorElem(Link L,LNode cur_e,Link &pre_e)
{
   Link a=L,b=L->next;
   while(b)
   {
       if(b->data==cur_e.data)
       {
          pre_e=a;
          return 1;
       }

           a=b;
           b=b->next;
    }
    return 0;
}
//求链表某个元素的前驱
void ListTraverse(Link L)
{
    Link a;
    a=L->next;
    while(a)
    {
        cout<<a->data<<" ";
        a=a->next;
    }
    cout<<endl;
}
//遍历链表并输出链表数据
int ListInsert(Link L,int i,int c)
{
    Link b=L->next,p;
    p=new LNode;
    p->data=c;
    p->next=NULL;
    int j=1;
    if(i==1)
    {
      p->next=b;
      L->next=p;
      return 1;
    }
    else
    {
       while(b)
     {
         if(j<i-1)
         {
            b=b->next;
            j++;
         }
         else
             break;
     }
     if(b)
     {
         p->next=b->next;
         b->next=p;
         return 1;
     }
     else
         return 0;
    }

}
//在链表的第i个位置插入e
int ListDelete(Link L,int i)
{
    Link a,b=L->next;
    int j=1;
    if(i==1)
    {
        L->next=b->next;
    }
    else
    {
        while(b)
     {
         if(j<i-1)
           {
             b=b->next;
             j++;
           }
           else
             break;
     }
     if(b)
     {
         a=b->next;
         b->next=a->next;
         delete a;
         return 1;
     }
     else
     {
         return 0;
     }
    }

}
//删除链表的第i个元素
void input(double *p)
{
    cin>>*p;
}
void Create(Link L,int n)
{
    Link p=L,s;
    cout<<"输入链表数据为：";
    for(;n>0;n--)
    {
        s=new LNode;
        input(&s->data);
        p->next=s;
        p=s;
    }
    p->next=NULL;
}
int main()
{
    Link L,pre_e;
    int a,c,i,p,n;
    double e;
    LNode cur_e,b;
    InitList(L);//初始化链表
    cout<<"输入数据长度：";
    cin>>n;
    Create(L,n);//创建长度为n的链表
    a=ListLength(L);
    cout<<"链表的长度为："<<a<<endl;
    cout<<"输入要获得元素值的位置为：";
    cin>>i;//输入要获得哪一个元素值
    GetElem(L,i,&e);//得到第i个元素值
    cout<<"该位置的元素值为：";
    cout<<e<<endl;//输出第i个元素值
    cout<<"输入要进行比较的data值：";
    cin>>b.data;//输入要进行比较的data值
    b.next=NULL;
    p=LocateElem(L,b);
    if(!p)
       cout<<"没有与e满足compare关系的元素"<<endl;
    else
       cout<<"满足比较关系的元素位置为："<<p<<endl;//输出满足比较关系的元素位置
    cout<<"输入cur_e的data为：";
    cin>>cur_e.data;
    cur_e.next=NULL;
    PriorElem(L,cur_e,pre_e);//链表cur_e的前驱
    cout<<"链表cur_e前驱的data为："<<pre_e->data<<endl;
    cout<<"链表L的data为：";
    ListTraverse(L);//遍历L
    cout<<"输入插入数值的位置：";
    cin>>i;
    cout<<"输入要插入的数值：";
    cin>>c;//输入插入的值
    ListInsert(L,i,c);
    cout<<"链表L的data为：";
    ListTraverse(L);//遍历L
    cout<<"输入销毁数值的位置：";
    cin>>i;//输入销毁的位置
    ListDelete(L,i);
    ListTraverse(L);//遍历L
    cout<<"链表L的data为：";
    DestroyList(L);//销毁链表
    if(L==NULL)
        cout<<"链表已销毁"<<endl;
    return 0;
}
