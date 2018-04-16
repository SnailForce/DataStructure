#include<iostream>
using namespace std;
typedef struct bag
{
	int weight;
	int value;
}*bags;
void creatbag(bags B, int n)
{
	int i;
	cout << "输入物品的重量和价值" << endl;
	for (i = 1; i < n; i++)
	{
		cin >> B[i].weight >> B[i].value;
	}
}
void output(bags B, int n)
{
	int i;
	cout << "背包的重量和价值" << endl;
	for (i = 1; i < n; i++)
	{
		cout << B[i].weight << B[i].value;
	}
}
void biaoge(int a[][9], bags B)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		a[0][i] = 0;
		a[i][0] = 0;
	}
	for (i = 1; i < 6; i++)
	{
		for (j = 1; j < 9; j++)
		{
			if (j >= B[i].weight)
			{
				if (a[i - 1][j] >= B[i].value + a[i - 1][ j - B[i].weight])
				{
					a[i][j] = a[i - 1][j];
				}
				else
				{
					a[i][j] = B[i].value + a[i - 1][j - B[i].weight];
				}
			}
			else
			{
				a[i][j] = a[i - 1][j];
			}
		}
	}
}
void biaoge2(int a[][7], bags B)
{
	int i, j;
	for (i = 0; i < 7; i++)
	{
		a[0][i] = 0;
		a[i][0] = 0;
	}
	for (i = 1; i < 7; i++)
	{
		for (j = 1; j < 7; j++)
		{
			if (j >= B[i].weight)
			{
				if (a[i - 1][j] >= B[i].value + a[i - 1][j - B[i].weight])
				{
					a[i][j] = a[i - 1][j];
				}
				else
				{
					a[i][j] = B[i].value + a[i - 1][j - B[i].weight];
				}
			}
			else
			{
				a[i][j] = a[i - 1][j];
			}
		}
	}
}
void output2(int a[][9])
{
	int i, j;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
}
void output3(int a[][7])
{
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
}
void search(int a[][9], int m, bags B)
{
	int i, j, k, q, w[10], e, f;
	e = 0;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (a[i][j] == m)
			{
				k = i;
				q = j;
				while (k)
				{
					if (q >= B[k].weight)
					{
						if (a[k - 1][q] >= B[k].value + a[k - 1][q - B[k].weight])
						{
							k--;
						}
						else
						{
							w[e] = k;
							e++;
							k--;
							q -= B[k].weight;
						}
					}
					else
					{
						k--;
					}
				}
				cout << "实例一中物品序号为" << endl;
				for (f = e - 1; f >= 0; f--)
				{
					cout << w[f] << " ";
				}
				cout << endl;
				for (f = 0; f < 10; f++)
				{
					w[f] = 0;
				}
			}
		}
	}
}
void search(int a[][7], int m, bags B)
{
	int i, j, k, q, w[10], e, f;
	e = 0;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (a[i][j] == m)
			{
				k = i;
				q = j;
				while (k)
				{
					if (q >= B[k].weight)
					{
						if (a[k - 1][q] >= B[k].value + a[k - 1][q - B[k].weight])
						{
							k--;
						}
						else
						{
							w[e] = k;
							e++;
							k--;
							q -= B[k].weight;
						}
					}
					else
					{
						k--;
					}
				}
				cout << "实例二中物品序号为" << endl;
				for (f = e - 1; f >= 0; f--)
				{
					cout << w[f] << " ";
				}
				e = 0;
				cout << endl;
				for (f = 0; f < 10; f++)
				{
					w[f] = 0;
				}
			}
		}
	}
	
	
}
int main()
{
	int a[6][9], c[7][7];
	bag B[10], D[10];
	creatbag(B, 6);
	biaoge(a, B);
	output2(a);
	cout << "实例一中窃贼可窃取的物品最大价值为" << a[5][8] << endl;
	search(a, a[5][8], B);
	creatbag(D, 7);
	biaoge2(c, D);
	output3(c);
	search(c, 272, D);
	system("pause");
	return 0;
}
/*
3 25
2 20
1 15
4 40
5 50
*/
/*
1 46
1 17
1 25
1 201
1 400
1 94
*/
