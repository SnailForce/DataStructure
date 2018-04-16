#include <iostream>
using namespace std;
#define MAXEDGE 20
#define MAXNODE 100
typedef struct
{
	char begin;
	char end;
	int weight;
}edge;
typedef struct
{
	int nodenum;
	int edgenum;
	char n[MAXNODE];
	edge e[MAXEDGE];
}Graph;
void swap(edge &a, edge &b)
{
	edge t;
	t = a;
	a = b;
	b = t;
}
void selectsort(Graph &G)
{
	int i, j, k;
	char m;
	for (i = 1; i <= 14; i++)
	{
		k = i;
		for (j = i + 1; j <= 14; j++)
		{
			if (G.e[j].weight < G.e[k].weight)
			{
				k = j;
			}
		}
		if (k != i)
		{
			swap(G.e[k], G.e[i]);
		}
	}
	for (i = 1; i <= 14; i++)
	{
		if (G.e->begin > G.e->end)
		{
			m = G.e->begin;
			G.e->begin = G.e->end;
			G.e->end = m;
		}
	}
}
void creatgraph(Graph &G)
{
	int i;
	char x;
	x = 'a';
	G.nodenum = 8;
	G.edgenum = 14;
	for (i = 1; i <= 8; i++)
	{
		G.n[i] = x;
		x++;
	}
	G.e[1].begin = 'a';
	G.e[1].end = 'b';
	G.e[1].weight = 4;

	G.e[2].begin = 'a';
	G.e[2].end = 'c';
	G.e[2].weight = 3;

	G.e[3].begin = 'b';
	G.e[3].end = 'c';
	G.e[3].weight = 5;

	G.e[4].begin = 'b';
	G.e[4].end = 'd';
	G.e[4].weight = 5;

	G.e[5].begin = 'c';
	G.e[5].end = 'd';
	G.e[5].weight = 5;

	G.e[6].begin = 'b';
	G.e[6].end = 'e';
	G.e[6].weight = 9;

	G.e[7].begin = 'c';
	G.e[7].end = 'h';
	G.e[7].weight = 5;

	G.e[8].begin = 'e';
	G.e[8].end = 'f';
	G.e[8].weight = 3;

	G.e[9].begin = 'd';
	G.e[9].end = 'f';
	G.e[9].weight = 6;

	G.e[10].begin = 'd';
	G.e[10].end = 'g';
	G.e[10].weight = 5;

	G.e[11].begin = 'd';
	G.e[11].end = 'h';
	G.e[11].weight = 4;

	G.e[12].begin = 'd';
	G.e[12].end = 'e';
	G.e[12].weight = 7;

	G.e[13].begin = 'f';
	G.e[13].end = 'g';
	G.e[13].weight = 2;

	G.e[14].begin = 'g';
	G.e[14].end = 'h';
	G.e[14].weight = 6;
}
int locate(Graph G, char i, char j)
{
	int k;
	for (k = 1; k <= 14; k++)
	{
		if (G.e[k].begin == i&&G.e[k].end == j)
		{
			return G.e[k].weight;
		}
	}
}
Graph kruskal(Graph G)
{
	Graph H;
	int m[9], i, j, k;
	char x;
	x = 'a';
	for (i = 1; i <= 8; i++)
	{
		H.n[i] = x;
		x++;
	}
	H.edgenum = 7;
	H.nodenum = 8;
	for (i = 1; i <= 8; i++)
	{
		m[i] = i;
	}
	k = 1;
	for (i = 1; i <= 7; i++)
	{
		for (j = k; j <= 14; j++)
		{
			if (m[G.e[j].begin - 'a' + 1] != m[G.e[j].end - 'a' + 1])
			{
				H.e[i].begin = G.e[j].begin;
				H.e[i].end = G.e[j].end;
				H.e[i].weight = G.e[j].weight;
				m[G.e[j].end - 'a' + 1] = m[G.e[j].begin - 'a' + 1];
				k = j;
				break;
			}
		}
	}
	return H;
}
void output(Graph G)
{
	int i;
	cout << G.nodenum << endl;
	for (i = 1; i <= 8; i++)
	{
		cout << G.n[i] << endl;
	}
	cout << G.edgenum << endl;
	for (i = 1; i <= 14; i++)
	{
		cout << G.e[i].begin << " " << G.e[i].end << " " << G.e[i].weight << endl;
	}
}
void output2(Graph G)
{
	int i;
	cout << G.nodenum << endl;
	for (i = 1; i <= 8; i++)
	{
		cout << G.n[i] << endl;
	}
	cout << G.edgenum << endl;
	for (i = 1; i <= 7; i++)
	{
		cout << G.e[i].begin << " " << G.e[i].end << " " << G.e[i].weight << endl;
	}
}
int main()
{
	Graph G, H;
	creatgraph(G);
	output(G);
	selectsort(G);
	output(G);
	H = kruskal(G);
	output2(H);
	system("pause");
}