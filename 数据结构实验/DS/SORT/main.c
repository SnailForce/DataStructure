#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
int  SeqSearch(int  A[],int key,int N)
{
	int i=0;
	while(i<N && A[i] != key) i++;
	if(i<N)
	{
		printf("Location: %d\n",i);
		printf("Times: %d\n",i+1);
		return 1;
	}
	printf("Location: Error\n");
	printf("Times: %d\n",i+1);
	return 0;
}//˳�����
int BinSearch(int A[],int key,int high,int low)
{
	int mid,sum=0;
	high--;
	while(low<high)
	{
		mid=(low+high)/2;
		sum++;
		if(A[mid]==key)
		{
			printf("Location: %d\n",mid);
			printf("Times: %d\n",sum);
			return 1;
		}
		else if(A[mid]<key) low=mid+1;
		else if(A[mid]>key) high=mid-1;
	}
	printf("Location: Error\n");
	printf("Times: %d\n",sum+1);
	return 0;
}//�۰���ң�Ҫ��Ϊ������������
void maopao(int A[],int N)
{
	printf("ð������:\n");
	int t;
	int com=0,sum=0;
	int exchange;//�ж��Ƿ񽻻�
	for(int i=0;i<N-1;i++)
	{
		exchange=0;
		for(int j=0;j<N-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
				sum=sum+3;
				exchange=1;
				for(int k=0;k<j;k++) printf("   ");//��@����һ��Ԫ��
				printf("%d %d\n",A[j],A[j+1]);
			}
			com++;
		}
		if(!exchange) break;
	}
	printf("Ԫ�رȽϴ���: %d\n",com);
	printf("Ԫ���ƶ�����: %d\n",sum);
	for(int i=0;i<N;i++) printf("%d ",A[i]);
	printf("\n");
}
 void SelectionSort(int A[],int N)
 {
 	printf("ѡ������:\n");
 	int t,k;
 	int com=0,sum=0;
 	for(int i=0;i<N-1;i++)
	{
		k=i;
		for(int j=i+1;j<N;j++)//j=i+1 ������i<N-1;
		{
			com++;
			if(A[j]<A[k]) k=j;
		}
		if(k != i)
		{
			t=A[k];
			A[k]=A[i];
			A[i]=t;
			sum=sum+3;
			for(int m=0;m<i;m++) printf("   ");
			printf("%d ",A[i]);
			for(int m=i+1;m<k;m++)printf("   ");
			printf("%d\n",A[k]);
		}
	}
	printf("Ԫ�رȽϴ���: %d\n",com);
	printf("Ԫ���ƶ�����: %d\n",sum);
	for(int i=0;i<N;i++) printf("%d ",A[i]);
 	printf("\n");
 }
 void InsertSort(int A[],int N)
 {
	int k,t;
	printf("��������:\n");
	int com=0,sum=0;
	for(int i=1;i<N;i++)
	{
		t=A[i];
		k=i-1;
		while(t<A[k])
		{
			A[k+1]=A[k];
			sum++;
			k--;
			if(k==-1) break;
		}
		com=com+i-1-k+1;
		A[k+1]=t;
		sum=sum+2;
		for(int j=0;j<=i;j++) printf("%d ",A[j]);
		printf("\n");
	}
	printf("Ԫ�رȽϴ���: %d\n",com);
	printf("Ԫ���ƶ�����: %d\n",sum);
	for(int i=0;i<N;i++) printf("%d ",A[i]);
 	printf("\n");
 }
void QuickSort(int A[],int N,int low,int high,int *sum,int *com)
{
	int i,j,t;
	if(low<high)
	{
		i=low;
		j=high+1;
		while(1)
		{
			while(i<N-1)
			{
				(*com)++;
				 if(A[++i] < A[low]);
				 else break;

			}
			while(j-1 >-1)
			{
				(*com)++;
				if(A[--j]>A[low]);
				else break;
			}
			if(i>=j) break;
			t=A[i];
			A[i]=A[j];
			A[j]=t;
			for(int m=0;m<i;m++) printf("   ");
			printf("%d ",A[i]);
			for(int m=i+1;m<j;m++) printf("   ");
			printf("%d ",A[j]);
			printf("\n");
			(*sum)=(*sum)+3;
		}
		if(j != low)
		{
			t=A[low];
			A[low]=A[j];
			A[j]=t;
			(*sum)=(*sum)+3;
			for(int m=0;m<low;m++) printf("   ");
			printf("%d ",A[low]);
			for(int m=low+1;m<j;m++) printf("   ");
			printf("%d ",A[j]);
			printf("\n");
		}
		QuickSort(A,N,low,j-1,sum,com);
		QuickSort(A,N,j+1,high,sum,com);
	}
}
void ShellSort(int A[],int N)
{
	printf("ϣ������:\n");
	int sum=0,com=0;
	int temp,j;
	for(int gap=N/2;gap>=1;gap=gap/2)
	{
		printf("gap=%d\n",gap);
		for(int i=gap;i<N;i++)
		{
			for( j=i-gap;j>=0;)
			{
				com++;
				if(A[j]>A[j+gap])
				{
					temp=A[j];
					A[j]=A[j+gap];
					A[j+gap]=temp;
					sum+=3;
					for(int m=0;m<j;m++) printf("   ");
					printf("%d ",A[j]);
					for(int m=j+1;m<j+gap;m++) printf("   ");
					printf("%d ",A[j+gap]);
					printf("\n");
					j=j-gap;
				}
				else break;
			}
		}
	}
	printf("Ԫ�رȽϴ���: %d\n",com);
	printf("Ԫ���ƶ�����: %d\n",sum);
	for(j=0;j<N;j++) printf("%d ",A[j]);
}
void HeapAdjust(int A[],int i,int N,int *sum,int *com)
{
	int rc,j;
	(*sum)++;
	for(rc=A[i];(2*i+1)< N;i=j)
	{
		j=2*i+1;
		if(j != N-1)
		{
			(*com)++;
			if(A[j] < A[j+1]) j++;
		}
		(*com)++;
		if(rc < A[j])
		{
			A[i]=A[j];
			A[j]=rc;
			for(int m=0;m<i;m++) printf("   ");
			printf("%d ",A[i]);
			for(int m=i+1;m<j;m++) printf("   ");
			printf("%d\n",A[j]);
			(*sum) +=2;
		}
		else break;
	}
}
void HeapSort(int A[],int N)
{
	int i,temp;
	int sum=0,com=0;
	printf("������:\n");
	for(i=N/2;i>=0;i--) HeapAdjust(A,i,N,&sum,&com);
	for(i=N-1;i>0;i--)
	{
		 temp=A[0];
		 A[0]=A[i];
		 A[i]=temp;
		 printf("%d ",A[0]);
		 for(int m=1;m<i;m++) printf("   ");
		 printf("%d \n",A[i]);
		 sum=sum+3;
		 HeapAdjust(A,0,i,&sum,&com);
	}
	printf("Ԫ�رȽϴ���: %d\n",com);
	printf("Ԫ���ƶ�����: %d\n",sum);
	for(i=0;i<N;i++) printf("%d ",A[i]);
	printf("\n");
}
int main()
{
	int A[20],B[20],C[20];//С�Ŀ��ܳ��ֵ�����Խ������
	printf("���ң�1\n");
	printf("����2\n");
	printf("����������3\n");
	int n;
	scanf("%d",&n);
	while(n !=3)
	{
		if(n==1)
		{
			printf("˳����ң�11\n");
			printf("�۰���ң�12\n");
			printf("�˳����Ҳ�����31\n");
			int x;
			scanf("%d",&x);
			while( x != 31 )
			{
				int i,j;
				if(x==11)
				{
					printf("���������鳤�ȣ�\n");
					scanf("%d",&j);
					printf("���������飺\n");
					for(i=0;i<j;i++) scanf("%d",&(A[i]));
					printf("������Ҫ��ѯ�Ĺؼ��֣�\n");
					int key;
					scanf("%d",&key);
					SeqSearch(A,key,j);
				}
				else if(x == 12)
				{
					printf("�������������鳤�ȣ�\n");
					scanf("%d",&j);
					printf("�������������飺\n");
					for(i=0;i<j;i++) scanf("%d",&(B[i]));
					printf("������Ҫ��ѯ�Ĺؼ��֣�\n");
					int key;
					scanf("%d",&key);
					BinSearch(B,key,j,0);
				}
				scanf("%d",&x);
			}
			printf("���˳���ѯ����\n");
		}
		else if(n==2)
		{
			int i,j,y;
			printf("ð������21\n");
			printf("ѡ������22\n");
			printf("��������23\n");
			printf("��������24\n");
			printf("ϣ������25\n");
			printf("������26\n");
			printf("�˳����������32\n");
			scanf("%d",&y);
			while(y != 32)
			{
				if(y==21)
				{
					printf("���������������ĳ���:\n");
					scanf("%d",&j);
					printf("���������������:\n");
					for(i=0;i<j;i++) scanf("%d",&(C[i]));
					maopao(C,j);
				}
				else if(y== 22)
				{
					printf("���������������ĳ���:\n");
					scanf("%d",&j);
					printf("���������������:\n");
					for(i=0;i<j;i++) scanf("%d",&(C[i]));
					SelectionSort(C,j);
				}
				else if(y==23)
				{
					printf("���������������ĳ���:\n");
					scanf("%d",&j);
					printf("���������������:\n");
					for(i=0;i<j;i++) scanf("%d",&(C[i]));
					InsertSort(C,j);
				}
				else if (y==24)
				{
					printf("���������������ĳ���:\n");
					scanf("%d",&j);
					printf("���������������:\n");
					for(i=0;i<j;i++) scanf("%d",&(C[i]));
					int sum=0,com=0;
					printf("��������:\n");
					QuickSort(C,j,0,j-1, &sum,&com);
					printf("Ԫ�رȽϴ���: %d\n",com);
					printf("Ԫ���ƶ�����: %d\n",sum);
					for(i=0;i<j;i++)printf("%d ",C[i]);
				}
				else if(y==25)
				{
					printf("���������������ĳ���:\n");
					scanf("%d",&j);
					printf("���������������:\n");
					for(i=0;i<j;i++) scanf("%d",&(C[i]));
					ShellSort(C,j);
				}
				else if(y==26)
				{
					printf("���������������ĳ���:\n");
					scanf("%d",&j);
					printf("���������������:\n");
					for(i=0;i<j;i++) scanf("%d",&(C[i]));
					HeapSort(C,j);
				}
				scanf("%d",&y);
			}
			printf("�˳��������\n");
		}
		scanf("%d",&n);
	}
	printf("��������\n");
	return 0;
}
