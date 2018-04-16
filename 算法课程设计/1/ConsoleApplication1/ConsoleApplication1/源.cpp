#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef struct
{
	int x, y;
}postype;
typedef struct
{
	postype seat;
	int di;
}position;
typedef struct 
{
	int m, n;
	int a[MAXSIZE][MAXSIZE];
}matrix;
typedef struct stacknode
{
	position data;
	stacknode *next;
}*stacklink;
typedef struct
{
	stacklink top;
	int length;
}stack;
void initstack(stack &S)
{
	S.top = NULL;
	S.length = 0;
}
int stackempty(stack S)
{
	if (S.top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pass(matrix M, postype curpos)
{
	if (M.a[curpos.y][curpos.x] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void footprint(matrix &M, postype curpos)
{
	M.a[curpos.y][curpos.x] = 2;
}
void markprint(matrix &M, postype curpos)
{
	M.a[curpos.y][curpos.x] = 3;
}
postype Nextpos(postype p, int a) 
{
	postype q;
	if (a == 1)
	{
		q.x = p.x + 1;
		q.y = p.y;
	}
	else
	{
		if (a == 2)
		{
			q.x = p.x;
			q.y = p.y + 1;
		}

		else
		{
			if (a == 3)
			{
				q.x = p.x - 1;
				q.y = p.y;
			}
			else
			{
				if (a == 4)
				{
					q.x = p.x;
					q.y = p.y - 1;
				}
			}
		}
	}
	return q;
}
void push(stack &S, position e)
{
	stacklink p;
	p = new stacknode;
	p->data = e;
	p->next = S.top;
	S.top = p;
	++S.length;
}
bool pop(stack &S, position &e)
{
	if (!S.top)
	{
		return false;
	}
	else
	{
		stacklink p;
		e = S.top->data;
		p = S.top;
		S.top = S.top->next;
		delete p;
		--S.length;
		return true;
	}
}
void creatmatrix(matrix &M)
{
	int i, j;
	cout << "请输入迷宫的行数和列数" << endl;
	cin >> M.m >> M.n;
	cout << "请输入迷宫的形状（0：障碍；1：非障碍）" << endl;
	for (i = 0; i < M.m; i++)
	{
		for (j = 0; j < M.n; j++)
		{
			cin >> M.a[i][j];
		}
	}
}
void mazepath(matrix &M, postype start, postype end)
{
	stack S;
	initstack(S);
	position e;
	postype curpos;
	curpos = start;
	do {
		if (pass(M, curpos)) 
		{
			footprint(M, curpos);
			e.di = 1, e.seat = curpos;
			push(S, e);
			if (curpos.x == end.x&&curpos.y == end.y) 
			{
				break;
			} 
			curpos = Nextpos(curpos, e.di);
		}
		else 
		{
			if (!stackempty(S)) 
			{
				pop(S, e);
				while (e.di == 4 && !stackempty(S))
				{
					markprint(M, e.seat);
					pop(S, e);
				}
				if (e.di < 4) 
				{
					e.di++;
					push(S, e);
					curpos = Nextpos(e.seat, e.di);
				}
			}
		}
	} while (!stackempty(S));
	if (!stackempty(S))
	{
		stack A;
		initstack(A);
		while (!stackempty(S))
		{
			pop(S, e);
			push(A, e);
		}
		while (!stackempty(A))
		{
			pop(A, e);
			cout << "(" << e.seat.x << "," << e.seat.y << "," << e.di << ")" << "->";
		}
		cout << '\b' << '\b' << " " << " ";
		cout << endl;
	}
}
void output(matrix M)
{
	int i, j;
	cout << "迷宫的行数为" << M.m << endl;
	cout << "迷宫的列数为" << M.n << endl;
	cout << "迷宫的形状" << endl;
	cout << "  ";
	for (i = 0; i < M.n; i++)
	{
		 cout<< i+1 << " ";
	}
	cout << endl;
	for (i = 0; i < M.m; i++)
	{
		if (i < 9)
		{
			cout << i + 1 << " :";
		}
		else
		{
			cout << i + 1 << ":";
		}
		for (j = 0; j < M.n; j++)
		{
			cout << M.a[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	matrix M;
	postype start, end;
	creatmatrix(M);
	cout << "输入起点和终点" << endl;
	cin >> start.x >> start.y >> end.x >> end.y;
	mazepath(M, start, end);
	output(M);
	system("pause");
}
/*
0 0 0 0 0 0 0 0 0 0
0 1 1 0 1 1 1 0 1 0
0 1 1 0 1 1 1 0 1 0
0 1 1 1 1 0 0 1 1 0
0 1 0 0 0 1 1 1 1 0
0 1 1 1 0 1 1 1 1 0
0 1 0 1 1 1 0 1 1 0
0 1 0 0 0 1 0 0 1 0
0 0 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0
*/