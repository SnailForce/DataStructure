#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXQSIZE 20
typedef struct
{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char * *HuffmanCode;
typedef int ElemType;
typedef struct
{
	ElemType *base;
	int front;
	int rear;
}Queue;
void  InitQueue(Queue *Q)
{
	Q->base=(ElemType *) malloc(MAXQSIZE * sizeof(ElemType));
	Q->front=Q->rear=0;
}
void DestroyQueue(Queue *Q)
{
	if(Q->base)
		free(Q->base);
	Q->base=NULL;
	Q->front=Q->rear=0;
}
int  QueueEmpty(Queue Q)
{
	if(Q.front==Q.rear) return 1;
	return 0;
}
int  EnQueue(Queue *Q,ElemType e)
{
	if((Q->rear+1)%MAXQSIZE==Q->front)
	{
		printf("ERROR!\n");
		return 0;
	}
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQSIZE;
	return 1;
}
int DeQueue(Queue *Q,ElemType *e)
{
	if(Q->rear==Q->front)
		return 0;
	*e = Q->base[Q->front];
	Q->front=(Q->front+1)%MAXQSIZE;
	return 1;
}
void Select(HuffmanTree  *HT, int k, int *s1, int *s2)
{
    int i;
    for(i=1; i<=k &&(*HT)[i].parent != 0; ++i);
	*s1 = i;
	int j=i+1;
	for(;j<=k&&(*HT)[j].parent !=0;++j);
    *s2 = j;
    if((*HT)[i].weight>(*HT)[j].weight)
	{
		*s1=j;
		*s2=i;
	}
    for(j=j+1; j<=k; ++j)
	{
        if((*HT)[j].parent==0 && (*HT)[j].weight<(*HT)[*s2].weight)
		{
			if((*HT)[j].weight<(*HT)[*s1].weight)
			{
				*s2=*s1;
				*s1=j;
			}
			else *s2=j;
		}
    }
}
void InitHTree(HuffmanTree *HT,HuffmanCode  *HC,int *w,int n)
{
	if(n<=1) return;
	int m=2*n-1;
	*HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	int i;
	HuffmanTree p;
	for( p = *HT,i=1;i<=n;++i,++w)//存入字符权重
	{
		p[i].weight=*w;
		p[i].parent =p[i].lchild=p[i].rchild= 0;
	}
	for(;i<=m;++i)//n+1至m初始化
			p[i].parent=p[i].weight=p[i].lchild=p[i].rchild=0;
	int s1=1,s2=1;
	for(i=n+1;i<=m;++i)//由权重生成哈夫曼树
	{
		Select(HT,i-1,&s1,&s2);
		(*HT)[s1].parent =(*HT)[s2].parent=i;
		(*HT)[i].lchild=s1;
		(*HT)[i].rchild=s2;
		(*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
	}
	*HC=(HuffmanCode)malloc((n+1)*sizeof(char *));//哈夫曼编码
	char * cd;
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]= '\0';
	for(i=1;i<=n;++i)
	{
		int start=n-1;
		for(int c=i,f=(*HT)[i].parent;f!=0;c=f,f=(*HT)[f].parent)
		{
			if((*HT)[f].lchild==c) cd[--start]='0';
			else cd[--start]='1';
		}
		(*HC)[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy((*HC)[i],&cd[start]);
	}
	free(cd);
}
void  ReadFile(char* A,int* B)
{
    FILE *fp;
    fp=fopen("source.txt","rt");
    while(!feof(fp))
    {
    	fgets(A,29,fp);
    	for(int i=0;i<27;i++)
				fscanf(fp,"%d",&B[i]);
    }
    fclose(fp);
}
int  Encode(char *A,HuffmanCode *HC)
{
	FILE *fp1,*fp2;
	fp1=fopen("CodedFile.txt","wt");
	fp2=fopen("data.txt","rt");
	if (fp2==NULL) return -1;
	char c;
	while(fscanf(fp2,"%c",&c)>0)
	{
		int i;
		for( i=0;A[i] != c &&i<27 ;i++);
		fputs((*HC)[i+1],fp1);
		fputs("\n",fp1);
	}
	fclose(fp1);
	fclose(fp2);
	return 1;
}
void Decode(HuffmanTree *HT,char *A)
{
	FILE *fp1,*fp2;
	fp1=fopen("CodedFile.txt","rt");
	fp2=fopen("PlainFile.txt","wb");
	int j;
	for( j=1;(*HT)[j].parent;j++);
	while(1)
	{
		char str[20];
		fgets(str,19,fp1);
		if(feof(fp1)) break;
		int k=j;
		int i=0;
		while(str[i] != '\n')
		{
			if(str[i]=='0') k=(*HT)[k].lchild;
			else k=(*HT)[k].rchild;
			i++;
		}
		fputc(A[k-1],fp2);
	}
    fclose(fp1);
	fclose(fp2);
}
void Print()
{
	FILE * fp1,*fp2;
	fp1=fopen("CodedFile.txt","rt");
	fp2=fopen("CodedPrint.txt","wt");
	int i=0,j;
	while(1)
	{
		char str[20];
		fgets(str,19,fp1);
		if(feof(fp1)) break;
		for(j=0;str[j]!='\n';j++)
		{
			if(i<50)
			{
				printf("%c",str[j]);
				fprintf(fp2,"%c",str[j]);
				i++;
			}
			else
			{
				printf("\n");
				fputs("\n",fp2);
				printf("%c",str[j]);
				fprintf(fp2,"%c",str[j]);
				i=1;
			}
		}
	}
	fclose(fp1);
	fclose(fp2);
}
void TreePrinting(int flag,HuffmanTree *HT,char *A)
{
	FILE *fp;
	fp=fopen("TreePrint.txt","wt");
	if(flag == 0) return;
	Queue Q;
	InitQueue(&Q);
	EnQueue(&Q,flag);
	EnQueue(&Q,233);
	while(!QueueEmpty(Q))
	{
		int e;
		DeQueue(&Q,&e);
		if(e !=0 && e!=233)
		{
			if((*HT)[e].lchild !=0 )  EnQueue(&Q,(*HT)[e].lchild);
			if((*HT)[e].rchild !=0 ) EnQueue(&Q,(*HT)[e].rchild);
			if(e<28)
			{
				printf("%d-%c   ",(*HT)[e].weight,A[e-1]);
				fprintf(fp,"%d-%c  ",(*HT)[e].weight,A[e-1]);
			}
			else
			{
				printf("%d  ",(*HT)[e].weight);
				fprintf(fp,"%d  ",(*HT)[e].weight);
			}
		}
		else if(e==233 &&!QueueEmpty(Q) )
		{
				printf("\n");
				fputs("\n",fp);
				EnQueue(&Q,233);
		}
	}
	fclose(fp);
}
int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	char A[30];
	int B[27];
	printf("I:初始化哈夫曼树\n");
	printf("E:编码(在编码前先将待编码内容存入文件)\n");
	printf("D:译码\n");
	printf("P:打印编码后的文件\n");
	printf("T:打印哈夫曼树\n");
	printf("Q:结束操作\n");
	char c;
	scanf("%c",&c);
	while(c != 'Q')
	{
		if(c=='I')
		{
			ReadFile(A,B);
			InitHTree(&HT,&HC,B,27);
		}
		if(c=='E') Encode(A,&HC);
		if(c=='D') Decode(&HT,A);
		if(c=='P') Print();
		if(c=='T') TreePrinting(53,&HT,A);
		scanf("%c",&c);
	}
    FILE *fp;
    fp=fopen("HuffmanTree.txt","wb");
    for(int i=1;i<=27;++i)
    {
        fprintf(fp,"%c--",A[i-1]);
        fputs(HC[i],fp);
		fputs("\t",fp);
		fprintf(fp,"\t");
		fprintf(fp,"\n");
    }
    fclose(fp);
	return 0;
}
