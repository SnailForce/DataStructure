#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
typedef struct
{
	int stuID;
	string stuName;
	double dsScore;
}student,*ss;//studentΪ�ṹ�壬ssΪ�ṹ��ָ��
void Input(ss a)
{
	cin>>a->stuID>>a->stuName>>a->dsScore;
}
ss  Create()
{
	ss pStu;
	pStu=(ss) malloc(sizeof(student));
	return pStu;
}
void setData(ss p,ss s)
{
	p->stuID=s->stuID;
	p->stuName=s->stuName;
	p->dsScore=s->dsScore;
}
void swap(ss p,ss s)
{
    student m;
    m=*p;
    *p=*s;
    *s=m;
}
void print(ss p)
{
    cout<<p->stuID<<" "<<p->stuName<<" "<<p->dsScore<<endl;
}
int main()
{
	student student1,student2;
	ss b;
	cout<<"������student��ID���������ɼ�"<<endl;
	Input(&student1);
	Input(&student2);
	b=Create();
	setData(b,&student1);;
	swap(&student1,&student2);
	cout<<"student1��ֵΪ��"<<endl;
    print(&student1);
    cout<<"student2��ֵΪ��"<<endl;
    print(&student2);
    cout<<"pStu��ֵΪ��"<<endl;
    print(b);
    delete(b);
	return 0;
}
