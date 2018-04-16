#include <iostream>
#include<stdlib.h>
#include<fstream>
#include<ctime>
using namespace std;
#define MAXSIZE 1000
int b1=0, b2=0, b3=0, b4=0, b5=0, b6=0, b7=0, y11=0, y2=0, y3=0, y4=0, y5=0, y6=0, y7=0;
int  a[MAXSIZE], cs[MAXSIZE][MAXSIZE], cs1[MAXSIZE][MAXSIZE];
int p = 0, q = 0, r = 0, s = 0, qs = 0, sq = 0, h = 0, d = 0;
void swap(int &a, int &b)
{
	int i;
	i = a;
	a = b;
	b = i;
}
void input(int *a, int n)
{
	int i;
	cout << "����������" << endl;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
}
void output(int *a, int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		cout << a[i] << '\t';
	}
	cout << endl;
}
void InsertionSort(int *a, int n)
{
	int i, j, k;
	int b, y;
	b = 0;
	y = 0;
	output(a, n);
	for (i = 2; i <= n; i++)
	{
		++b;
		if (a[i] < a[i - 1])
		{
			y += 2;
			a[0] = a[i];
			a[i] = a[i - 1];
			for (j = i - 2; a[0] < a[j]; --j)
			{
				++b;
				++y;
				a[j + 1] = a[j];
			}
			++y;
			a[j + 1] = a[0];
			for (k = 1; k <= j; k++)
			{
				cout << '\t';
			}
			for (; k <= i; k++)
			{
				cout << a[k] << '\t';
			}
			cout << endl;
		}
	}
	cout << "��������ıȽϴ���Ϊ" << b << endl;
	cout << "����������ƶ�����Ϊ" << y << endl;
}
void SelectionSort(int *a, int n)
{
	int i, j, k, m;
	int b, y;
	b = 0;
	y = 0;
	output(a, n);
	for (i = 1; i < n; i++)
	{
		k = i;
		for (j = i + 1; j <= n; j++)
		{
			b++;
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		y += 3;
		swap(a[k], a[i]);
		for (m = 1; m < i; m++)
		{
			cout << '\t';
		}
		cout << a[m] << '\t';
		m++;
		for (; m < k; m++)
		{
			cout << '\t';
		}
		cout << a[m] << endl;
	}
	cout << "ѡ������ıȽϴ���Ϊ" << b << endl;
	cout << "ѡ��������ƶ�����Ϊ" << y << endl;
}
void BubbleSort(int *a, int n)
{
	int i, j, k, m;
	int b, y;
	b = 0;
	y = 0;
	output(a, n);
	k = n;
	while (k)
	{
		j = k;
		k = 0;
		for (i = 1; i <= j - 1; i++)
		{
			b++;
			if (a[i] > a[i + 1])
			{
				y += 3;
				swap(a[i], a[i + 1]);
				for (m = 1; m < i; m++)
				{
					cout << '\t';
				}
				cout << a[i] << '\t' << a[i + 1];
				for (m = i + 2; m <= n; m++)
				{
					cout << '\t';
				}
				cout << endl;
				k = j - 1;
			}
		}
	}
	cout << "ð������ıȽϴ���Ϊ" << b << endl;
	cout << "ð��������ƶ�����Ϊ" << y << endl;
}
void ShellSort(int *a, int n)
{
	int i, j, k, gap, m, v, w;
	int b, y;
	b = 0;
	y = 0;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = 1; i <= gap; i++)
		{
			for (j = i + gap; j <= n; j += gap)
			{
				b++;
				if (a[j] < a[j - gap])
				{
					y++;
					k = a[j];
					m = j - gap;
					b++;
					while (m && a[m] > k)
					{
						b++;
						y++;
						a[m + gap] = a[m];
						m -= gap;
						if (m <= 0)
						{
							b--;
						}
					}
					y++;
					a[m + gap] = k;
				}
			}
			for (v = 1; v <= n; v++)
			{
				for (w = i; w <= n; w += gap)
				{
					if (v == w)
					{
						cout << a[v] << '\t';
						break;
					}
				}
				if (w > n)
				{
					cout << '\t';
				}
			}
			cout << endl;
		}
	}
	cout << "ϣ������ıȽϴ���Ϊ" << b << endl;
	cout << "ϣ��������ƶ�����Ϊ" << y << endl;
}
void HeapAdjust(int *a, int s, int m)
{
	int i, j;
	p++;
	i = a[s];
	for (j = 2 * s; j <= m; j *= 2)
	{
		q++;
		if (j < m && a[j] < a[j + 1])
		{
			q++;
			j++;
			if (j >= m)
			{
				q--;
			}
		}
		q++;
		if (!(i < a[j]))
		{
			break;
		}
		p++;
		a[s] = a[j];
		s = j;
	}
	p++;
	a[s] = i;
}
void HeapSort(int *a, int n)
{
	int i,j,k=0;
	for (i = n / 2; i > 0; i--)
	{
		HeapAdjust(a, i, n);
	}
	for (i = n; i > 1; i--)
	{
		p += 3;
		swap(a[1], a[i]);
		HeapAdjust(a, 1, i - 1);
		for (j = 1; j <= i - 1; j++)
		{
			cout << a[j] << '\t';
		}
		cout << "|" << '\t';
		for (; j <= n; j++)
		{
			cout << a[j] << '\t';
		}
		cout << endl;
	}      
	cout << "������ıȽϴ���Ϊ" << q << endl;
	cout << "��������ƶ�����Ϊ" << p << endl;
	b5 += q, y5 += p;
}
int Partition(int *a, int low, int high)
{
	int  i, j, k;
	j = low;
	k = high;
	r += 2;
	a[0] = a[low];
	i = a[low];
	while (low < high)
	{
		s++;
		while (low < high && a[high] >= i)
		{
			s++;
			--high;
			if (low >= high)
			{
				s--;
			}
		}
		s++;
		if (a[low] == a[high])
		{
			break;
		}
		r += 3;
		swap(a[low], a[high]);
		for (j = 1; j <= k; j++)
		{
			if (a[j] == a[low] || a[j] == a[high])
			{
				cout << a[j] << '\t';
			}
			else
			{
				cout << '\t';
			}
		}
		cout << endl;
		s++;
		while (low < high && a[low] <= i)
		{
			s++;
			++low;
			if (low >= high)
			{
				s--;
			}
		}
		s++;
		if (a[low] == a[high])
		{
			break;
		}
		r += 3;
		swap(a[low], a[high]);
		for (j = 1; j <= k; j++)
		{
			if (a[j] == a[low] || a[j] == a[high])
			{
				cout << a[j] << '\t';
			}
			else
			{
				cout << '\t';
			}
		}
		cout << endl;
	}
	r++;
	a[low] = a[0];
	return low;
}
void QuickSort(int *a, int low, int high)
{
	int i;
	if (low < high)
	{
		i = Partition(a, low, high);
		QuickSort(a, low, i - 1);
		QuickSort(a, i + 1, high);
	}
}
void merge(int *initlist, int *templist, int left, int mid, int right,int &anum,int &bnum)
{
	int i = left, j = mid + 1, k = left;
	while (i <= mid&&j <= right)
	{
		anum++,bnum++;
		if (initlist[i] <= initlist[j])
		{
			templist[k] = initlist[i];
			k++; 
			i++;
		}
		else
		{
			templist[k] = initlist[j];
			k++;
			j++;
		}
	}
	if (i <= mid)
	{
		for (; i <= mid; i++, k++)
		{
			templist[k] = initlist[i];
			bnum++;
		}
	}
	else
	{
		for (; j <= right; j++, k++)
		{
			templist[k] = initlist[j];
			bnum++;
		}
	}
}
void MergePass(int *initlist, int *templist, int len, int n,int &anum,int &bnum)
{
	int i = 1,j;
	while (i + 2 * len - 1 <= n )
	{
		merge(initlist, templist, i, i + len - 1, i + 2 * len - 1,anum,bnum);
		for (j = i; j <= i + len - 1; j++)
			cout << initlist[j] << '\t';
		cout << "|" << "\t";
		for (; j <= i + 2 * len - 1; j++)
			cout << initlist[j] << '\t';
		cout << "|" << '\t';
		i = i + 2 * len;
	}
	if (i + len-1 <= n )
	{
		merge(initlist, templist, i, i + len - 1, n,anum,bnum );
		for (j = i; j <= i + len - 1; j++)
			cout << initlist[j] << '\t';
		cout << "|" << "\t";
		for (; j <= n; j++)
			cout << initlist[j] << '\t';
	}
	else
	{
		for (; i <= n ; i++)
		{
			templist[i] = initlist[i],bnum++;
		}
		for (j = i; j <= n; j++)
			cout << initlist[j] << '\t';
	}
	cout << endl;
}
void MergeSort(int *initlist, int n)
{
	int templist[MAXSIZE];
	int anum = 0, bnum = 0; //anum�Ƚϴ�����bnum�ƶ�����
	int len = 1;
	while (len < n)
	{
		MergePass(initlist, templist, len, n, anum, bnum);
		len *= 2;
		MergePass(templist, initlist, len, n, anum, bnum);
		len = len * 2;
	}
	cout << "�鲢����ıȽϴ���Ϊ" << anum << endl;
	cout << "�鲢������ƶ�����Ϊ" << bnum << endl;
}
void randarray(int *a, int len)
{
	int i;
	for (i = 1; i <= len; i++)
	{
		a[i] = rand()%1000;
	}
}
void InsertionSort2(int *a, int n)
{
	int i, j;
	int b, y;
	b = 0;
	y = 0;
	for (i = 2; i <= n; i++)
	{
		++b;
		if (a[i] < a[i - 1])
		{
			y += 2;
			a[0] = a[i];
			a[i] = a[i - 1];
			for (j = i - 2; a[0] < a[j]; --j)
			{
				++b;
				++y;
				a[j + 1] = a[j];
			}
			++y;
			a[j + 1] = a[0];
		}
	}
	b1 += b, y11 += y;
}
void SelectionSort2(int *a, int n)
{
	int i, j, k;
	int b, y;
	b = 0;
	y = 0;
	for (i = 1; i < n; i++)
	{
		k = i;
		for (j = i + 1; j <= n; j++)
		{
			++b;
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		y += 3;
		swap(a[k], a[i]);
	}
	b2 += b, y2 += y;
}
void BubbleSort2(int *a, int n)
{
	int i, j, k;
	int b, y;
	b = 0;
	y = 0;
	k = n;
	while (k)
	{
		j = k;
		k = 0;
		for (i = 1; i <= j - 1; i++)
		{
			++b;
			if (a[i] > a[i + 1])
			{
				y += 3;
				swap(a[i], a[i + 1]);
				k = j - 1;
			}
		}
	}
	b3 += b, y3 += y;
}
void ShellInsert2(int *a, int dk,int n, int &anum, int &bnum)
{
	int i, j;
	for (i = dk + 1; i <= n; i++) 
	{
		anum++;
		if (a[i]<a[i-dk]) 
		{
			bnum += 2;
			a[0] = a[i];
			a[i] = a[i - dk];
			for (j = i - 2 * dk; j > 0 && a[0] < a[j]; j -= dk)
			{
				a[j + dk] = a[j], anum++, bnum++;
			}
			a[j + dk] = a[0];
			anum++;
			bnum++;
		}
	}
}
void ShellSort2(int *a,int n)
{
	int i, dk, anum = 0, bnum = 0;
	dk = n/2;
	i = 0;
	while (dk != 1) 
	{
		ShellInsert2(a, dk,n, anum, bnum);
		dk = dk / 2;
		i++;
	}
	b4 += anum;
	y4 += bnum;
}
void HeapAdjust2(int *a, int s, int m)
{
	int i, j;
	++h;
	i = a[s];
	for (j = 2 * s; j <= m; j *= 2)
	{
		++d;
		if (j < m && a[j] < a[j + 1])
		{
			++d;
			j++;
			if (j >= m)
			{
				--d;
			}
		}
		++d;
		if (!(i < a[j]))
		{
			break;
		}
		++h;
		a[s] = a[j];
		s = j;
	}
	++h;
	a[s] = i;
}
void HeapSort2(int *a, int n)
{
	int i, k = 0;
	for (i = n / 2; i > 0; i--)
	{
		HeapAdjust2(a, i, n);
	}
	for (i = n; i > 1; i--)
	{
		h += 3;
		swap(a[1], a[i]);
		HeapAdjust2(a, 1, i - 1);
	}
	b5 += d, y5 += h;
}
int Partition2(int *a, int low, int high)
{
	int  i, j, k;
	j = low;
	k = high;
	qs += 2;
	a[0] = a[low];
	i = a[low];
	while (low < high)
	{
		++sq;
		while (low < high && a[high] >= i)
		{
			++sq;
			--high;
			if (low >= high)
			{
				--sq;
			}
		}
		++sq;
		if (a[low] == a[high])
		{
			break;
		}
		qs += 3;
		swap(a[low], a[high]);
		++sq;
		while (low < high && a[low] <= i)
		{
			++sq;
			++low;
			if (low >= high)
			{
				--sq;
			}
		}
		++sq;
		if (a[low] == a[high])
		{
			break;
		}
		qs += 3;
		swap(a[low], a[high]);
	}
	++qs;
	a[low] = a[0];
	return low;
}
void QuickSort2(int *a, int low, int high)
{
	int i;
	if (low < high)
	{
		i = Partition2(a, low, high);
		QuickSort2(a, low, i - 1);
		QuickSort2(a, i + 1, high);
	}
}
void merge2(int *initlist, int *templist, int left, int mid, int right, int &anum, int &bnum)
{
	int i = left, j = mid + 1, k = left;
	while (i <= mid&&j <= right)
	{
		++anum, ++bnum;
		if (initlist[i] <= initlist[j])
		{
			templist[k] = initlist[i];
			k++;
			i++;
		}
		else
		{
			templist[k] = initlist[j];
			k++;
			j++;
		}
	}
	if (i <= mid)
	{
		for (; i <= mid; i++, k++)
		{
			templist[k] = initlist[i];
			++bnum;
		}
	}
	else
	{
		for (; j <= right; j++, k++)
		{
			templist[k] = initlist[j];
			++bnum;
		}
	}
}
void MergePass2(int *initlist, int *templist, int len, int n, int &anum, int &bnum)
{
	int i = 1;
	while (i + 2 * len - 1 <= n)
	{
		merge(initlist, templist, i, i + len - 1, i + 2 * len - 1, anum, bnum);
		i = i + 2 * len;
	}
	if (i + len - 1 <= n)
	{
		merge(initlist, templist, i, i + len - 1, n, anum, bnum);
	}
	else
	{
		for (; i <= n; i++)
		{
			templist[i] = initlist[i], bnum++;
		}
	}
}
void MergeSort2(int *initlist, int n)
{
	int templist[MAXSIZE];
	int anum = 0, bnum = 0; 
	int len = 1;
	while (len < n)
	{
		MergePass2(initlist, templist, len, n, anum, bnum);
		len *= 2;
		MergePass2(templist, initlist, len, n, anum, bnum);
		len = len * 2;
	}
	b7 += anum, y7 += bnum;
}
void InsertionSort3(int *a, int n)
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		if (a[i] < a[i - 1])
		{
			a[0] = a[i];
			a[i] = a[i - 1];
			for (j = i - 2; a[0] < a[j]; --j)
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = a[0];
		}
	}
}
void SelectionSort3(int *a, int n)
{
	int i, j, k;
	for (i = 1; i < n; i++)
	{
		k = i;
		for (j = i + 1; j <= n; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		swap(a[k], a[i]);
	}
}
void BubbleSort3(int *a, int n)
{
	int i, j, k;
	k = n;
	while (k)
	{
		j = k;
		k = 0;
		for (i = 1; i <= j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = j - 1;
			}
		}
	}
}
void ShellInsert3(int *a, int dk, int n)
{
	int i, j;
	for (i = dk + 1; i <= n; i++)
	{
		if (a[i]<a[i - dk])
		{
			a[0] = a[i];
			a[i] = a[i - dk];
			for (j = i - 2 * dk; j > 0 && a[0] < a[j]; j -= dk)
			{
				a[j + dk] = a[j];
			}
			a[j + dk] = a[0];
		}
	}
}
void ShellSort3(int *a, int n)
{
	int i, dk;
	dk = n / 2;
	i = 0;
	while (dk != 1)
	{
		ShellInsert3(a, dk, n);
		dk = dk / 2;
		i++;
	}
}
void HeapAdjust3(int *a, int s, int m)
{
	int i, j;
	i = a[s];
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m && a[j] < a[j + 1])
		{
			j++;
		}
		if (!(i < a[j]))
		{
			break;
		}
		a[s] = a[j];
		s = j;
	}
	a[s] = i;
}
void HeapSort3(int *a, int n)
{
	int i, k = 0;
	for (i = n / 2; i > 0; i--)
	{
		HeapAdjust3(a, i, n);
	}
	for (i = n; i > 1; i--)
	{
		swap(a[1], a[i]);
		HeapAdjust3(a, 1, i - 1);
	}
}
int Partition3(int *a, int low, int high)
{
	int  i, j, k;
	j = low;
	k = high;
	a[0] = a[low];
	i = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= i)
		{
			--high;
		}
		if (a[low] == a[high])
		{
			break;
		}
		swap(a[low], a[high]);
		while (low < high && a[low] <= i)
		{
			++low;
		}
		if (a[low] == a[high])
		{
			break;
		}
		swap(a[low], a[high]);
	}
	a[low] = a[0];
	return low;
}
void QuickSort3(int *a, int low, int high)
{
	int i;
	if (low < high)
	{
		i = Partition3(a, low, high);
		QuickSort3(a, low, i - 1);
		QuickSort3(a, i + 1, high);
	}
}
void merge3(int *initlist, int *templist, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;
	while (i <= mid&&j <= right)
	{
		if (initlist[i] <= initlist[j])
		{
			templist[k] = initlist[i];
			k++;
			i++;
		}
		else
		{
			templist[k] = initlist[j];
			k++;
			j++;
		}
	}
	if (i <= mid)
	{
		for (; i <= mid; i++, k++)
		{
			templist[k] = initlist[i];
		}
	}
	else
	{
		for (; j <= right; j++, k++)
		{
			templist[k] = initlist[j];
		}
	}
}
void MergePass3(int *initlist, int *templist, int len, int n)
{
	int i = 1;
	while (i + 2 * len - 1 <= n)
	{
		merge3(initlist, templist, i, i + len - 1, i + 2 * len - 1);
		i = i + 2 * len;
	}
	if (i + len - 1 <= n)
	{
		merge3(initlist, templist, i, i + len - 1, n);
	}
	else
	{
		for (; i <= n; i++)
		{
			templist[i] = initlist[i];
		}
	}
}
void MergeSort3(int *initlist, int n)
{
	int templist[MAXSIZE];
	int len = 1;
	while (len < n)
	{
		MergePass3(initlist, templist, len, n);
		len *= 2;
		MergePass3(templist, initlist, len, n);
		len = len * 2;
	}
}
int main()
{
	int m;
	while (1)
	{
		cout << "�˳���0������1,���ԣ�2" << endl;
		cin >> m;
		if (m == 0)
		{
			break;
		}
		if (m == 1)
		{
			int p, n;
			cout << "������������ݵĸ���" << endl;
			cin >> n;
			input(a, n);
			cout << "���룺1" << '\n' << "ѡ��2" << '\n' << "ð�ݣ�3" << '\n' << "ϣ����4" << '\n' << "�ѣ�5" << '\n' << "���٣�6" << '\n' << "�鲢��7" << endl;
			cin >> p;
			switch (p)
			{
				case 1:
					InsertionSort(a, n);
					cout << "��������Ľ��Ϊ" << endl;
					output(a, n);
					break;
				case 2:
					cout << "ѡ������Ľ��Ϊ" << endl;
					SelectionSort(a, n);
					output(a, n);
					break;
				case 3:
					cout << "ð������Ľ��Ϊ" << endl;
					BubbleSort(a, n);
					output(a, n);
					break;
				case 4:
					cout << "ϣ������Ľ��Ϊ" << endl;
					ShellSort(a, n);
					output(a, n);
					break;
				case 5:
					cout << "������Ľ��Ϊ" << endl;
					HeapSort(a, n);
					output(a, n);
					break;
				case 6:
					output(a, n);
					QuickSort(a, 1, n);
					cout << "��������Ľ��Ϊ" << endl;
					output(a, n);
					cout << "��������ıȽϴ���Ϊ" << s << endl;
					cout << "����������ƶ�����Ϊ" << r << endl;
					break;
				case 7:
					MergeSort(a, n);
					output(a, n);

			}
		}
		if (m = 2)
		{
			int len, ci;
			int i, j;
			clock_t starttime, endtime;
			ofstream outfile;
			srand(unsigned(time(NULL)));
			cout << "����������ݵĳ���" << endl;
			cin >> len;
			ci = 200;
			for (i = 0; i < 200; i++)
			{
				randarray(cs[i], len);
			}
			for (i = 0; i < MAXSIZE; i++)
			{
				for (j = 1; j < MAXSIZE; j++)
				{
					cs1[i][j] = cs[i][j];
				}
			}
			outfile.open("insert.txt");
			starttime = clock();
			while (ci--)
			{
				InsertionSort2(cs[199-ci], len);
			}
			endtime = clock();
			outfile << "���ݳ���Ϊ" << len << endl;
			outfile << "��������2ƽ���Ƚϴ���" << b1 / 200 << endl;
			outfile << "��������2ƽ���ƶ�����" << y11 / 200 << endl;
			outfile << "��������2����ʱ��" << endtime - starttime << endl;
			cout << "��������2ƽ���Ƚϴ���" << b1 / 200 << endl;
			cout << "��������2ƽ���ƶ�����" << y11 / 200 << endl;
			cout << "��������2����ʱ��" << endtime - starttime<< endl;
			b1 = 0;
			y11 = 0;

			ci = 200;
			starttime = clock();
			while (ci--)
			{
				InsertionSort3(cs1[199 - ci], len);
			}
			endtime = clock();
			outfile << "��������3����ʱ��" << endtime - starttime << endl;
			cout << "��������3����ʱ��" << endtime - starttime << endl;
			outfile.close();


			ci = 200;
			for (i = 0; i < 200; i++)
			{
				randarray(cs[i], len);
			}
			for (i = 0; i < MAXSIZE; i++)
			{
				for (j = 1; j < MAXSIZE; j++)
				{
					cs1[i][j] = cs[i][j];
				}
			}
			outfile.open("select.txt");
			starttime = clock();
			while (ci--)
			{
				SelectionSort2(cs[199 - ci], len);
			}
			endtime = clock();
			outfile << "���ݳ���Ϊ" << len << endl;
			outfile << "ѡ������2ƽ���Ƚϴ���" << b2 / 200 << endl;
			outfile << "ѡ������2ƽ���ƶ�����" << y2 / 200 << endl;
			outfile << "ѡ������2����ʱ��" << endtime - starttime << endl;
			cout << "ѡ������2ƽ���Ƚϴ���" << b2 / 200 << endl;
			cout << "ѡ������2ƽ���ƶ�����" << y2 / 200 << endl;
			cout << "ѡ������2����ʱ��" << endtime - starttime << endl;
			b2 = 0;
			y2 = 0;

			ci = 200;
			starttime = clock();
			while (ci--)
			{
				SelectionSort3(cs1[199 - ci], len);
			}
			endtime = clock();
			outfile << "ѡ������3����ʱ��" << endtime - starttime << endl;
			cout << "ѡ������3����ʱ��" << endtime - starttime << endl;
			outfile.close();


			ci = 200;
			for (i = 0; i < 200; i++)
			{
				randarray(cs[i], len);
			}
			for (i = 0; i < MAXSIZE; i++)
			{
				for (j = 1; j < MAXSIZE; j++)
				{
					cs1[i][j] = cs[i][j];
				}
			}
			outfile.open("bubble.txt");
			starttime = clock();
			while (ci--)
			{
				BubbleSort2(cs[199 - ci], len);
			}
			endtime = clock();
			outfile << "���ݳ���Ϊ" << len << endl;
			outfile << "ð������2ƽ���Ƚϴ���" << b3 / 200 << endl;
			outfile << "ð������2ƽ���ƶ�����" << y3 / 200 << endl;
			outfile << "ð������2����ʱ��" << endtime - starttime << endl;
			cout << "ð������2ƽ���Ƚϴ���" << b3 / 200 << endl;
			cout << "ð������2ƽ���ƶ�����" << y3 / 200 << endl;
			cout << "ð������2����ʱ��" << endtime - starttime << endl;
			b3 = 0;
			y3 = 0;

			ci = 200;
			starttime = clock();
			while (ci--)
			{
				BubbleSort3(cs1[199 - ci], len);
			}
			endtime = clock();
			outfile << "ð������3����ʱ��" << endtime - starttime << endl;
			cout << "ð������3����ʱ��" << endtime - starttime << endl;
			outfile.close();


			ci = 200;
			for (i = 0; i < 200; i++)
			{
				randarray(cs[i], len);
			}
			for (i = 0; i < MAXSIZE; i++)
			{
				for (j = 1; j < MAXSIZE; j++)
				{
					cs1[i][j] = cs[i][j];
				}
			}
			outfile.open("shell.txt");
			starttime = clock();
			while (ci--)
			{
				ShellSort2(cs[199 - ci], len);
			}
			endtime = clock();
			outfile << "���ݳ���Ϊ" << len << endl;
			outfile << "ϣ������2ƽ���Ƚϴ���" << b4 / 200 << endl;
			outfile << "ϣ������2ƽ���ƶ�����" << y4 / 200 << endl;
			outfile << "ϣ������2����ʱ��" << endtime - starttime << endl;
			cout << "ϣ������2ƽ���Ƚϴ���" << b4 / 200 << endl;
			cout << "ϣ������2ƽ���ƶ�����" << y4 / 200 << endl;
			cout << "ϣ������2����ʱ��" << endtime - starttime << endl;
			b4 = 0;
			y4 = 0;

			ci = 200;
			starttime = clock();
			while (ci--)
			{
				ShellSort3(cs1[199 - ci], len);
			}
			endtime = clock();
			outfile << "ϣ������3����ʱ��" << endtime - starttime << endl;
			cout << "ϣ������3����ʱ��" << endtime - starttime << endl;
			outfile.close();


			ci = 200;
			for (i = 0; i < 200; i++)
			{
				randarray(cs[i], len);
			}
			for (i = 0; i < MAXSIZE; i++)
			{
				for (j = 1; j < MAXSIZE; j++)
				{
					cs1[i][j] = cs[i][j];
				}
			}
			outfile.open("heap.txt");
			starttime = clock();
			while (ci--)
			{
				HeapSort2(cs[199 - ci], len);
				d = 0;
				h = 0;
			}
			endtime = clock();
			outfile << "���ݳ���Ϊ" << len << endl;
			outfile << "������2ƽ���Ƚϴ���" << b5 / 200 << endl;
			outfile << "������2ƽ���ƶ�����" << y5 / 200 << endl;
			outfile << "������2����ʱ��" << endtime - starttime << endl;
			cout << "������2ƽ���Ƚϴ���" << b5 / 200 << endl;
			cout << "������2ƽ���ƶ�����" << y5 / 200 << endl;
			cout << "������2����ʱ��" << endtime - starttime << endl;
			b5 = 0;
			y5 = 0;

			ci = 200;
			starttime = clock();
			while (ci--)
			{
				HeapSort3(cs1[199 - ci], len);
			}
			endtime = clock();
			outfile << "������3����ʱ��" << endtime - starttime << endl;
			cout << "������3����ʱ��" << endtime - starttime << endl;
			outfile.close();


			ci = 200;
			for (i = 0; i < 200; i++)
			{
				randarray(cs[i], len);
			}
			for (i = 0; i < MAXSIZE; i++)
			{
				for (j = 1; j < MAXSIZE; j++)
				{
					cs1[i][j] = cs[i][j];
				}
			}
			outfile.open("quick.txt");
			starttime = clock();
			while (ci--)
			{
				QuickSort2(cs[199 - ci], 1, len);
				b6 += sq, y6 += qs;
				sq = 0;
				qs = 0;
			}
			endtime = clock();
			outfile << "���ݳ���Ϊ" << len << endl;
			outfile << "��������2ƽ���Ƚϴ���" << b6 / 200 << endl;
			outfile << "��������2ƽ���ƶ�����" << y6 / 200 << endl;
			outfile << "��������2����ʱ��" << endtime - starttime << endl;
			cout << "��������2ƽ���Ƚϴ���" << b6 / 200 << endl;
			cout << "��������2ƽ���ƶ�����" << y6 / 200 << endl;
			cout << "��������2����ʱ��" << endtime - starttime << endl;
			b6 = 0;
			y6 = 0;

			ci = 200;
			starttime = clock();
			while (ci--)
			{
				QuickSort3(cs1[199 - ci], 1, len);
			}
			endtime = clock();
			outfile << "��������3����ʱ��" << endtime - starttime << endl;
			cout << "��������3����ʱ��" << endtime - starttime << endl;
			outfile.close();


			ci = 200;
			for (i = 0; i < 200; i++)
			{
				randarray(cs[i], len);
			}
			for (i = 0; i < MAXSIZE; i++)
			{
				for (j = 1; j < MAXSIZE; j++)
				{
					cs1[i][j] = cs[i][j];
				}
			}
			outfile.open("merge.txt");
			starttime = clock();
			while (ci--)
			{
				MergeSort2(cs[199 - ci], len);
			}
			endtime = clock();
			outfile << "���ݳ���Ϊ" << len << endl;
			outfile << "�鲢����2ƽ���Ƚϴ���" << b7 / 200 << endl;
			outfile << "�鲢����2ƽ���ƶ�����" << y7 / 200 << endl;
			outfile << "�鲢����2����ʱ��" << endtime - starttime << endl;
			cout << "�鲢����2ƽ���Ƚϴ���" << b7 / 200 << endl;
			cout << "�鲢����2ƽ���ƶ�����" << y7 / 200 << endl;
			cout << "�鲢����2����ʱ��" << endtime - starttime << endl;
			b7 = 0;
			y7 = 0;

			ci = 200;
			starttime = clock();
			while (ci--)
			{
				MergeSort3(cs1[199 - ci], len);
			}
			endtime = clock();
			outfile << "�鲢����3����ʱ��" << endtime - starttime << endl;
			cout << "�鲢����3����ʱ��" << endtime - starttime << endl;
			outfile.close();


			if (len < 600)
			{
				ci = 200;
				for (i = 0; i < 200; i++)
				{
					randarray(cs[i], len);
				}
				starttime = clock();
				while (ci--)
				{
					ShellSort2(cs[199 - ci], len);
				}
				outfile.open("new.txt");
				endtime = clock();
				outfile << "���ݳ���Ϊ" << len << endl;
				outfile << "������ƽ���Ƚϴ���" << b4 / 200 << endl;
				outfile << "������ƽ���ƶ�����" << y4 / 200 << endl;
				cout << "������ƽ���Ƚϴ���" << b4 / 200 << endl;
				cout << "������ƽ���ƶ�����" << y4 / 200 << endl;
				cout << "����������ʱ��" << endtime - starttime << endl;
				b4 = 0;
				y4 = 0;
			}
			else
			{
				ci = 200;
				for (i = 0; i < 200; i++)
				{
					randarray(cs[i], len);
				}
				starttime = clock();
				while (ci--)
				{
					MergeSort2(cs[199 - ci], len);
				}
				endtime = clock();
				outfile << "���ݳ���Ϊ" << len << endl;
				outfile << "������ƽ���Ƚϴ���" << b7 / 200 << endl;
				outfile << "������ƽ���ƶ�����" << y7 / 200 << endl;
				cout << "������ƽ���Ƚϴ���" << b7 / 200 << endl;
				cout << "������ƽ���ƶ�����" << y7 / 200 << endl;
				cout << "����������ʱ��" << endtime - starttime << endl;
				b7 = 0;
				y7 = 0;
			}
			outfile.close();
		}
	}
	system("pause");
	return 0;
}
