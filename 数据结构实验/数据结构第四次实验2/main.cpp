#include <iostream>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
using namespace std;
typedef struct HTNode
{
	 int weight;
	 int parent,lchild,rchild;
}*HuffmanTree;
typedef char **HuffmanCode;
void Select(HuffmanTree &HT,int n,int &s1,int &s2)
{
    int min1,min2;
	int i;
	min1=INT_MAX;
	min2=INT_MAX;
	s1=0;
	s2=0;
	for(i=1;i<=n;++i)
	{
		if(HT[i].parent==0)
		{
			if(HT[i].weight<min1)
			{
				min2=min1;
				s2=s1;
				min1=HT[i].weight;
				s1=i  ;
			}
			else
            {
                if((HT[i].weight>=min1)&&(HT[i].weight<min2))
				{
					min2=HT[i].weight;
					s2=i;
				}
            }
		}
	}
	cout<<s1<<" "<<s2<<endl;
	/*
	int a,b;
	for(a=1;a<=n;a++)
    {
        if(HT[a].parent==0)
        {
            b=a;
            break;
        }
    }
    for(a=1;a<=n;a++)
    {
        if(HT[a].parent==0&&HT[a].weight<HT[b].weight)
        {
            b=a;
        }
    }
    s1=b;
    for(a=1;a<=n;a++)
    {
        if(HT[a].parent==0&&a!=s1)
        {
            b=a;
            break;
        }
    }
    for(a=1;a<=n;a++)
    {
        if(HT[a].parent==0&&HT[a].weight<HT[b].weight&&a!=s1)
        {
            b=a;
        }
    }
    s2=b;
    int j;
    s1=0;
    s2=0;
    for(j=1;j<n;j++)
    {
        while(HT[j].parent==0)
        {
            if(HT[j].weight<HT[s1].weight)
                s1=j;
        }
    }
    for(j=1;j<n;j++)
    {
        while(HT[j].parent==0&&j!=s1)
        {
            if(HT[j].weight<HT[s2].weight)
                s2=j;
        }
    }*/
}
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{
	int m=2*n-1,i,s1,s2,start,c,f;
	char *cd;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(i=1;i<=n;++i)HT[i]={w[i],0,0,0};
	for(i=n+1;i<=m;++i)HT[i]={0,0,0,0};
	for(i=n+1;i<=m;i++)
	{
		Select(HT,i-1,s1,s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	for(i=1;i<=m;i++)
    {
        cout<<"/**********"<<endl;
        cout<<HT[i].weight<<" "<<HT[i].parent<<" "<<HT[i].lchild<<" "<<HT[i].rchild<<endl;
        cout<<"**********/"<<endl;
    }
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
        start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
			if(HT[f].lchild==c)
				cd[--start]='0';
            else
                cd[--start]='1';
        HC[i]=(char *)malloc((n-start)*sizeof(char));
        strcpy(HC[i],&cd[start]);
	}
	free(cd);
}
int main()
{
	char key[28]={'0','#','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int i,w1[9]={0,7,19,2,6,32,3,21,10},w2[28]={0,186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};
	for(i=0;i<9;i++)cout<<w1[i]<<" ";
	cout<<endl;
	HuffmanTree HT;
	HuffmanCode HC1,HC2;
	HuffmanCoding(HT,HC1,w1,8);
	HuffmanCoding(HT,HC2,w2,27);
	for(i=1;i<9;i++)
		cout<<w1[i]<<":"<<HC1[i]<<endl;
    cout<<"/**********************************************/"<<endl;
    for(i=1;i<28;i++)
		cout<<key[i]<<w2[i]<<":"<<HC2[i]<<endl;
    char y[100];
    for(i=0;i<100;i++)
    {
        cin>>y[i];
        if(y[i]=='*')
            break;
    }
    for(i=0;y[i]!='*';i++)
    {
        int j;
        if(y[i]=='#')
            cout<<HC2[1];
        else
        {
            j=y[i]-'A'+2;
            cout<<HC2[j];
        }
    }
    cout<<endl;
    char s[1000];
    int j;
    for(i=0;i<1000;i++)
    {
        cin>>s[i];
        if(s[i]=='*')
            break;
    }
    int m=0;
    for(int k=0;s[k]!='*';)
    {
        for(i=0;i<28;i++)
        {
            int l=strlen(HC2[i]);
            m=k;
            for( j=0;j<l;j++,m++)
            {
            	if(s[m]==HC2[i][j])
					continue;
				else
					break;
            }
            if(j==l)
            {
                cout<<key[i];
                k=k+l-1;
                break;
            }
        }
        k++;
    }
	return 0;
}

