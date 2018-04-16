#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	int stuID;
	char stuName[21];
	double dsScore;
	}student,*point;
void  Input(point p)
{
        scanf("%d%s%lf",&(*p).stuID,p->stuName,&p->dsScore);
}
student  * Create()
{
    point pStu;
	pStu = (point) malloc(sizeof(student));
	return pStu;
}
void setData(point p,point q)
{
	q->stuID=p->stuID;
	strcpy(q->stuName,p->stuName);
	q->dsScore=p->dsScore;
}
void print(point p)
{
	printf("%d %s %.2lf\n",(*p).stuID,p->stuName,p->dsScore);
}
void swap(point p, point q)
{
	student T;
	 T= (*p);
	 (*p)=(*q);
	 (*q)=T;
}
int main()
{
	student student1,student2;
	Input(&student1);
	Input(&student2);
	point a= Create();
	setData(&student1,a);
	swap(&student1,&student2);
	print(&student1);
	print(&student2);
	print(a);
	free(a);
	a=NULL;
	return 0;
}
