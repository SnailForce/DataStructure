 #include <iostream>
using namespace std;
typedef struct
{
    float coef;
    int expn;
}term;
typedef struct polynomial
{
    term data;
    polynomial *next;
}*Link;
void InitList(Link &L)
{
    L=new polynomial;
    L->next=NULL;
}
int Create(Link &L)
{
    Link p,s;
    int i=0;
    p=new polynomial;
    L->next=p;
    s=p;
    cin>>p->data.coef>>p->data.expn;
    while(p->data.coef!=0)
    {
        i++;
        p=new polynomial;
        s->next=p;
        cin>>p->data.coef>>p->data.expn;
        if(p->data.coef!=0)
            s=p;
    }
    s->next=NULL;
    L->data.expn=i;
    return 0;
}
int Output(Link L)
{
    Link a=L;
    cout<<a->data.expn<<" ";
    while(a)
    {
        a=a->next;
        if(a&&a->data.coef!=0)
        {
            cout<<a->data.coef<<" "<<a->data.expn<<" ";
        }
    }
    a=NULL;
    cout<<endl;
    return 0;
}
Link PriorElem(Link L,int t)
{
   Link a=L,b=L->next,p;
   while(b)
   {
       if(b->data.expn==t)
       {
          p=a;
          return p;
       }
           a=b;
           b=b->next;
    }
    return 0;
}
int sort(Link &L)
{
    Link p,q,r=L,s=L->next;
    int t=0,i=0;
    while(s)
    {
        i=0;
        t=s->data.expn;
        while(s)
        {
            if(s->data.expn<t)
            {
                t=s->data.expn;
                p=s;
                i=1;
            }
            s=s->next;
        }
        if(i)
        {
            q=PriorElem(L,p->data.expn);
            q->next=p->next;
            p->next=r->next;
            r->next=p;
        }
        r=r->next;
        s=r->next;
    }
    return 0;
}
int compare(int a,int b)
{
    if(a==b)
       return 0;
     else
     {
         if(a>b)
            return 1;
         else
            return -1;
     }
}
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
Link AddPolyn(Link p,Link q)
{
    Link r=p,s=q,t,u=r->next,v=s->next;
    InitList(t);
    Link w=t,x;
    int i;
    while(u&&v)
    {
        switch(compare(u->data.expn,v->data.expn))
        {
            case -1:
                x=new polynomial;
                x->data.coef=u->data.coef;
                x->data.expn=u->data.expn;
                x->next=NULL;
                w->next=x;
                w=x;
                u=u->next;
                break;
            case 0:
                i=u->data.coef+v->data.coef;
                if(i)
                {
                    x=new polynomial;
                    x->data.coef=i;
                    x->data.expn=u->data.expn;
                    x->next=NULL;
                    w->next=x;
                    w=x;
                }
                u=u->next;
                v=v->next;
                break;
            case 1:
                x=new polynomial;
                x->data.coef=v->data.coef;
                x->data.expn=v->data.expn;
                x->next=NULL;
                w->next=x;
                w=x;
                v=v->next;
                break;
        }
    }
    if(u)
        w->next=u;
    else
    {
        if(v)
            w->next=v;
        else
            w->next=NULL;
    }
    t->data.expn=ListLength(t);
    return t;
}
int formaloutput(Link L)
{
    Link p=L->next;
    //常数
    if(p->data.coef!=0&&p->data.expn==0)
        cout<<p->data.coef;
    //一次项
    if(p->data.coef!=0&&p->data.expn==1)
    cout<<p->data.coef<<"x";
    //高次项
    if(p->data.coef!=0&&p->data.coef!=1&&(p->data.expn>1||p->data.expn<-1))
    cout<<p->data.coef<<"x^"<<p->data.expn;
    if(p->data.coef==1&&(p->data.expn>1||p->data.expn<-1))
    cout<<"x^"<<p->data.expn;
    if(p->data.coef==-1&&(p->data.expn>1||p->data.expn<-1))
    cout<<"x^"<<p->data.expn;
    while(p->next)
    {
        p=p->next;
        if(p->data.coef>0&&p->data.coef!=1&&p->data.expn==1)
            cout<<"+"<<p->data.coef<<"x";
        if(p->data.coef==1&&p->data.expn==1)
            cout<<"+x";
        if(p->data.coef>0&&p->data.coef!=1&&p->data.expn!=1)
            cout<<"+"<<p->data.coef<<"x^"<<p->data.expn;
        if(p->data.coef==1&&p->data.expn!=1)
            cout<<"+x^"<<p->data.expn;
        if(p->data.coef<0&&p->data.coef!=-1&&p->data.expn==1)
            cout<<p->data.coef<<"x";
        if(p->data.coef==-1&&p->data.expn==1)
            cout<<"-x";
        if(p->data.coef<0&&p->data.coef!=-1)
            cout<<p->data.coef<<"x^"<<p->data.expn;
        if(p->data.coef==-1&&p->data.expn!=1)
            cout<<"-x^"<<p->data.expn;
    }
    cout<<endl;
    return 0;
}
Link Derivation(Link L)
{
    Link p=L->next,s;
    InitList(s);
    Link r=s,t;
    while(p)
    {
        if(p->data.expn!=0)
        {
            t=new polynomial;
            t->data.coef=p->data.coef*p->data.expn;
            t->data.expn=p->data.expn-1;
            r->next=t;
            r=t;
            t->next=NULL;
        }
        p=p->next;
    }
    s->data.expn=ListLength(s);
    return s;
}
Link Multiplication(Link p,Link q)
{
    Link r,s=p->next,t=q->next;
    InitList(r);
    Link u=r,v;
    while(s)
    {
        t=q->next;
        while(t)
        {
            v=new polynomial;
            v->data.coef=s->data.coef*t->data.coef;
            v->data.expn=s->data.expn+t->data.expn;
            v->next=NULL;
            u->next=v;
            u=v;
            t=t->next;
        }
        s=s->next;
    }
    return r;
}
void combine(Link &L)
{
    Link p=L->next,q,s;
    while(p)
    {
        s=p;
        q=s->next;
        while(q)
        {
            if(q->data.expn==p->data.expn)
            {
                p->data.coef=q->data.coef+p->data.coef;
                s->next=q->next;
                delete q;
            }
            s=q;
            q=q->next;
        }
        p=p->next;
    }
    L->data.expn=ListLength(L);
}
int main()
{
    Link L1,L2,p,q,r,s;
    cout<<"输入多项式1的系数和指数为："<<endl;
    InitList(L1);
    Create(L1);
    cout<<"输入多项式2的系数和指数为："<<endl;
    InitList(L2);
    Create(L2);
    cout<<"链表1的长度、系数和指数为："<<endl;
    Output(L1);
    cout<<"链表2的长度、系数和指数为："<<endl;
    Output(L2);
    cout<<"排序后链表1的长度、系数和指数为："<<endl;
    sort(L1);
    Output(L1);
    cout<<"排序后链表2的长度、系数和指数为："<<endl;
    sort(L2);
    Output(L2);
    cout<<"多项式相加所得的结果为："<<endl;
    p=AddPolyn(L1,L2);
    Output(p);
    cout<<"多项式相加规范输出结果为："<<endl;
    formaloutput(p);
    cout<<"多项式求导的结果为："<<endl;
    q=Derivation(p);
    formaloutput(q);
    cout<<"多项式相乘的结果为："<<endl;
    r=Multiplication(L1,L2);
    combine(r);
    sort(r);
    formaloutput(r);
    delete L1;
    delete L2;
    delete p;
    delete q;
    delete r;
    delete s;
    return 0;
}
