#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct HTNode{
  char c;
  double weight;//权
  int parent,lchild,rchild;
};
typedef struct Node{
  char c;
  double weight;//权
  Node *n;
};
typedef char **HuffmanCode;
void Select(HTNode *HT,int i,int *s1,int *s2)//在HT[1...i-1]选择parent为0并且weight最小的两个结点
{
	int j,p,q,qq;
	for(j=2,p=1;j<=i;){
		if(HT[p].parent==0&&HT[j].parent==0){
			if(HT[p].weight<=HT[j].weight) j++;
			else {
				p=j;
				j++;
			}
		}
        else if(HT[p].parent==0&&HT[j].parent!=0) j++;
		else if(HT[p].parent!=0&&HT[j].parent==0) {
			p=j;
			j++;
		}
        else if(HT[p].parent!=0&&HT[j].parent!=0) {
			p=j+1;
			j=j+2;
        }
	}
	*s1=p;
	if(p==1){
		for(j=3,q=2;j<=i;){
			if(HT[q].parent==0&&HT[j].parent==0){
				if(HT[q].weight<=HT[j].weight) j++;
				else {
					q=j;
					j++;
				}
			}
			else if(HT[q].parent==0&&HT[j].parent!=0) j++;
		    else if(HT[q].parent!=0&&HT[j].parent==0) {
				q=j;
				j++;
			}
			else if(HT[q].parent!=0&&HT[j].parent!=0) {
				q=j+1;
				j=j+2;
			}
		}
	}
	else if(p==2){
		for(j=3,q=1;j<=i;){
			if(HT[q].parent==0&&HT[j].parent==0){
				if(HT[q].weight<=HT[j].weight) j++;
				else {
					q=j;
					j++;
				}
			}
			else if(HT[q].parent==0&&HT[j].parent!=0) j++;
		    else if(HT[q].parent!=0&&HT[j].parent==0) {
				q=j;
				j++;
			}
			else if(HT[q].parent!=0&&HT[j].parent!=0) {
				q=j+1;
				j=j+2;
			}
		}
	}
	else if(p>2){
		for(j=2,q=1;j<p;){
				qq=q;
				if(HT[q].parent==0&&HT[j].parent==0){
					if(HT[q].weight<=HT[j].weight) j++;
					else {
						q=j;
						j++;
					}
				}
				else if(HT[q].parent==0&&HT[j].parent!=0) {
						j++;
				}
				else if(HT[q].parent!=0&&HT[j].parent==0) {
					q=j;
					j++;
				}
				else if(HT[q].parent!=0&&HT[j].parent!=0) {
					q=j+1;
				    j=j+2;
				}
		}
		j=p+1;
		q=qq;
		for(;j<=i;){
				if(HT[q].parent==0&&HT[j].parent==0){
					if(HT[q].weight<=HT[j].weight) j++;
					else {
						q=j;
						j++;
					}
				}
				else if(HT[q].parent!=0&&HT[j].parent==0){
					q++;
				}
				else if(HT[q].parent==0&&HT[j].parent!=0) j++;
				else if(HT[q].parent!=0&&HT[j].parent!=0) {
					q=j+1;
				    j=j+2;
				}
		}
        if(p==q) q++;
	}
	*s2=q;
	return;
}
void BulidHuffman(HTNode *H,Node *p,int n)//建立HuffmanTree
{
	int m,i,s1,s2;
	m=2*n-1;//结点数
	for(i=1;i<=n;i++){
		H[i].c=p[i].c;
		H[i].weight=p[i].weight;
		H[i].parent=0;
		H[i].lchild=0;
		H[i].rchild=0;
	}
	for(;i<=m;i++){
		H[i].c='0';
		H[i].weight=0;
		H[i].parent=0;
		H[i].lchild=0;
		H[i].rchild=0;
	}
	for(i=n+1;i<=m;i++){
		Select(H,i-1,&s1,&s2);
		H[s1].parent=i;
		H[s2].parent=i;
		H[i].lchild=s1;
		H[i].rchild=s2;
		H[i].weight=H[s1].weight+H[s2].weight;
	}

}
void Code(HTNode *HT,HuffmanCode HC,int n)//编码
{
	char cd[n];
	int i,c,start,f;
	cd[n-1]=0;
	for(i=1;i<=n;i++){
		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent){
			if(HT[f].lchild==c) cd[--start]='0';
			else cd[--start]='1';
		}
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
    free(cd);

}
/*void ReCode()//译码
{

}*/


int main()
{
	int i,n,j,h,w,lb;
	HTNode *HT;
	Node *n1;
	HuffmanCode HC;
	char *bw,*bm;
	char z[13],bj[13];


	//报文(明文)输入---------------------------------------------------------------------------- Q:为和报名输入放在最后输入不了
	/*cout<<"请输入报文(明文)"<<endl;
	bw=(char*)malloc((100)*sizeof(char));
    cin.getline(bw,100);*/

    //报文(暗文)输入
	cout<<"请输入报文(暗文)"<<endl;
	bm=(char*)malloc((100)*sizeof(char));
	cin.getline(bm ,100);

    //频度表输入
    cout<<" "<<endl;
	cout<<"请输入字符个数"<<endl;
	cin>>n;
	n1=(Node*)malloc((n+1)*sizeof(Node));
	cout<<"请输入各个字符及其权值"<<endl;
	for(i=1;i<=n;i++){
		cin>>n1[i].c>>n1[i].weight;
	}

	//建立HuffmanTree
	HT=(HTNode*)malloc((2*n)*sizeof(HTNode));
	BulidHuffman(HT,n1,n);//---------------------------------------------------------------Q：为啥不能将上面代码放入函数

	//Code
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
	Code(HT,HC,n);

	//输出Code
	cout<<"输出Code"<<endl;
	for(i=1;i<=n;i++){
	    cout<<HT[i].c<<"的编码:"<<HC[i]<<endl;
	}

	//报文编码
	/*cout<<" "<<endl;
	cout<<"报文编码:";
    for(i=0;bw[i]!='\0';i++){//字符数组最后一位为休 \0
		for(j=1;j<=n;j++){
			if(HT[j].c==bw[i])  {
				cout<<HC[j];
			    break;
			}
		}
    }*/

    //报文译码
	cout<<" "<<endl;
	cout<<"报文译码:";
    for(lb=0;bm[lb]!=0&&bm[lb]!=1;lb++);//------------------------------------------------Q:不能用if---break代替for中间的条件
	for(w=0;w<=lb-1;){
		for(j=0;j<=n;j++){
			strcpy(z,HC[j]);
			for(h=0;z[h]!='\0';h++);//计算z的长度
			for(i=w;(i-w)<=h-1;){
			   if(bm[i]==z[i-w]) i++;
			   else break;
			}
			if((i-w)==h){
				cout<<HT[j].c;
				w=w+h;
				break;
			}
		}
	}
	//报文编译部分 Q:为和报名输入放在最后输入不了
	/*bw=(char*)malloc((20)*sizeof(char));
    cin.getline(bw,20);
    cout<<bw;*/

	return 0;
}
