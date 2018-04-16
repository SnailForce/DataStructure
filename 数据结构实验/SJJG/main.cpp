#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct HTNode{
  char c;
  double weight;//Ȩ
  int parent,lchild,rchild;
};
typedef struct Node{
  char c;
  double weight;//Ȩ
  Node *n;
};
typedef char **HuffmanCode;
void Select(HTNode *HT,int i,int *s1,int *s2)//��HT[1...i-1]ѡ��parentΪ0����weight��С���������
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
void BulidHuffman(HTNode *H,Node *p,int n)//����HuffmanTree
{
	int m,i,s1,s2;
	m=2*n-1;//�����
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
void Code(HTNode *HT,HuffmanCode HC,int n)//����
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
/*void ReCode()//����
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


	//����(����)����---------------------------------------------------------------------------- Q:Ϊ�ͱ����������������벻��
	/*cout<<"�����뱨��(����)"<<endl;
	bw=(char*)malloc((100)*sizeof(char));
    cin.getline(bw,100);*/

    //����(����)����
	cout<<"�����뱨��(����)"<<endl;
	bm=(char*)malloc((100)*sizeof(char));
	cin.getline(bm ,100);

    //Ƶ�ȱ�����
    cout<<" "<<endl;
	cout<<"�������ַ�����"<<endl;
	cin>>n;
	n1=(Node*)malloc((n+1)*sizeof(Node));
	cout<<"����������ַ�����Ȩֵ"<<endl;
	for(i=1;i<=n;i++){
		cin>>n1[i].c>>n1[i].weight;
	}

	//����HuffmanTree
	HT=(HTNode*)malloc((2*n)*sizeof(HTNode));
	BulidHuffman(HT,n1,n);//---------------------------------------------------------------Q��Ϊɶ���ܽ����������뺯��

	//Code
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
	Code(HT,HC,n);

	//���Code
	cout<<"���Code"<<endl;
	for(i=1;i<=n;i++){
	    cout<<HT[i].c<<"�ı���:"<<HC[i]<<endl;
	}

	//���ı���
	/*cout<<" "<<endl;
	cout<<"���ı���:";
    for(i=0;bw[i]!='\0';i++){//�ַ��������һλΪ�� \0
		for(j=1;j<=n;j++){
			if(HT[j].c==bw[i])  {
				cout<<HC[j];
			    break;
			}
		}
    }*/

    //��������
	cout<<" "<<endl;
	cout<<"��������:";
    for(lb=0;bm[lb]!=0&&bm[lb]!=1;lb++);//------------------------------------------------Q:������if---break����for�м������
	for(w=0;w<=lb-1;){
		for(j=0;j<=n;j++){
			strcpy(z,HC[j]);
			for(h=0;z[h]!='\0';h++);//����z�ĳ���
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
	//���ı��벿�� Q:Ϊ�ͱ����������������벻��
	/*bw=(char*)malloc((20)*sizeof(char));
    cin.getline(bw,20);
    cout<<bw;*/

	return 0;
}
