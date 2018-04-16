#include <iostream>
using namespace std;
#define MaxVertexNum 50
struct Node
{
	char adjvex;
	Node *next;
	int level;
};
struct VNode
{
	char vertex;
	Node *firstedge;
};
typedef VNode Adjlist[MaxVertexNum];
struct Graph
{
	Adjlist adjlist;
	int n, e;
};
struct stack
{
	int top;
	Node **base;
};
void stackinit(stack &s)
{
	s.base = new Node*[100];
	s.top = 0;
}
void push(stack &s, Node *p)
{
	s.top++;
	s.base[s.top] = p;
}
void pop(stack &s, Node *p)
{
	s.top--;
	p = s.base[s.top];
}
int stackempty(stack s)
{
	if (s.top == 0)
		return 1;
	else
		return 0;
}
void createGraph(Graph &G)
{
	int i, j, k;
	char a;
	Node *s;
	cout << "请输入图的顶点数和边数" << endl;
	cin >> i >> j;
	G.n = i;
	G.e = j;
	cout << "请输入顶点" << endl;
	for (i =0;i < G.n; i++)
	{
		cin >> a;
		G.adjlist[i].vertex = a;
		G.adjlist[i].firstedge = NULL;
	}
	cout << "请输入两个顶点之间的边" << endl;
	for (k = 0; k < G.e; k++)
	{
		cin >> i >> j;
		s = new Node;
		s->adjvex = j;
		s->next = G.adjlist[i].firstedge;
		G.adjlist[i].firstedge = s;
	}
}
int getNumVertices(Graph G)
{
	return G.n;
}
int getNumEdges(Graph G)
{
	return G.e;
}
int validVertex(Graph G, char v)
{
	int i,l;
	for (i = 0; i < G.n; i++)
	{
		l = 0;
		if (G.adjlist[i].vertex == v)
			return l;
		l++;
	}
	return -1;
}
int hasEdge(Graph G, char u, char v)
{
	int i,l;
	Node *j;
	for (i = 0; i < G.n; i++)
	{
		if (G.adjlist[i].firstedge->adjvex == u)
			break;
	}
	if (i < G.n)
	{
		j = G.adjlist[i].firstedge;
		l = 1;
		for (; j; j = j->next,l++)
		{
			if (j->adjvex == v)
				return l;
		}
	}
	return -1;
}
void addVertex(Graph G, char u)
{
	if (validVertex(G, u)==-1)
	{
		G.adjlist[G.n].vertex = u;
		G.adjlist[G.n].firstedge = NULL;
		G.n++;
	}
}
void addEdge(Graph &G, char u,char v)
{
	int i;
	Node *j,*l;
	if (hasEdge(G, u, v)==-1)
	{
		i=validVertex(G, u);
		j = G.adjlist[i].firstedge;
		while (j->next)
		{
			j = j->next;
		}
		l = new Node;
		l->adjvex = v;
		l->next = j->next;
		j->next = l;
	}
}
void removeEdge(Graph &G, char u, char v)
{
	int i;
	Node *j,*l;
	if (hasEdge(G, u, v) != -1)
	{
		i = validVertex(G, u);
		j = G.adjlist[i].firstedge;
		if (j->adjvex == v)
		{
			G.adjlist[i].firstedge = j->next;
			delete j;
		}
		else
		{
			while (j->next->adjvex != v)
			{
				j = j->next;
			}
			l = j->next;
			j->next = l->next;
			delete l;
		}
	}
}
void length2Paths(Graph G, char v,Graph &NG)
{
	int i,j;
	Node *k,*l;
	for (i = 0; i < G.n; i++)
	{
		NG.adjlist[i] = G.adjlist[i];
		NG.adjlist[i].firstedge = NULL;
	}
	NG.n = G.n;
	NG.e = 0;
	for (i = 0; i < G.n; i++)
	{
		if (hasEdge(G, G.adjlist[i].vertex, v) != -1)
		{
			for (j = 0; j < G.n; j++)
			{
				if (hasEdge(G, G.adjlist[j].vertex, G.adjlist[i].vertex)!=-1)
				{
					if (NG.adjlist[j].firstedge)
					{
						k = NG.adjlist[j].firstedge;
						l = new Node;
						l->adjvex = v;
						l->next = NG.adjlist[j].firstedge->next;
						NG.adjlist[j].firstedge = l;
					}
					else
					{
						l = new Node;
						l->adjvex = v;
						l->next = NG.adjlist[j].firstedge->next;
						NG.adjlist[j].firstedge = l;
					}
					NG.e++;
				}
			}
		}
	}	
}
Graph nixu(Graph G)
{
	int i;
	Node *j,*l;
	Graph H;
	for (i = 0; i < G.n; i++)
	{
		H.adjlist[i] = H.adjlist[i];
		H.adjlist[i].firstedge = NULL;
	}
	H.n = G.n;
	H.e = G.e;
	for (i = 0; i < G.n; i++)
	{
		for (j = G.adjlist[i].firstedge; j; j = j->next)
		{
			l = new Node;
			l->adjvex = G.adjlist[i].vertex;
			l->next = H.adjlist[validVertex(G, j->adjvex)].firstedge;
			H.adjlist[validVertex(G, j->adjvex)].firstedge = l;
		}
	}
	return H;
}
Graph BFS(Graph H, int length,char v,Graph G)
{
	int i,j;
	Node *p,*l;
	stack s;
	Graph NG;
	for (i = 0; i < G.n; i++)
	{
		NG.adjlist[i] = G.adjlist[i];
		NG.adjlist[i].firstedge = NULL;
	}
	NG.n = G.n;
	NG.e = 0;
	j = validVertex(H, v);
	stackinit(s);
	H.adjlist[j].firstedge->level = 1;
	push(s, (H.adjlist[j].firstedge));
	while (stackempty(s) != 0)
	{
		pop(s, p);
		for (i = 1; p->level <= length; i++)
		{
			for (; p; p = p->next)
			{
				p->level = i;
				push(s, p);
			}
		}
	}
	while (1)
	{
		pop(s, p);
		if (p->level == length)
		{
			j=validVertex(H, p->adjvex);
			l = new Node;
			l->adjvex = v;
			l->next = NG.adjlist[i].firstedge;
			NG.adjlist[j].firstedge = l;
		}
		if (p->level != length)
		{
			return NG;
		}
	}
}
void bianli(Graph G)
{
	int i;
	Node *j;
	for (i = 0; i < G.n; i++)
	{
		cout << i << " " << G.adjlist[i].vertex << " " << endl;
		for (j = G.adjlist[i].firstedge; j != NULL; j = j->next)
		{
			cout << j->adjvex << " ";
		}
		cout << endl;
	}
}
int main()
{
	char u, v;
	int length;
	Graph G,NG,H;
	cout << "创建有向图" << endl;
	createGraph(G);
	cout << "图中的顶点个数为：" << endl;
	cout << getNumVertices(G) << endl;
	cout << "图中的边的个数为：" << endl;
	cout << getNumEdges(G) << endl;
	cout << "请输入想要查询的顶点：" << endl;
	cin >> v;
	cout << validVertex(G,v) << endl;
	cout << "请输入想要查询的边：" << endl;
	cin >> u >> v;
	cout << hasEdge(G, u, v) << endl;
	bianli(G);
	cout << "请输入想要加入的顶点：" << endl;
	cin >> u;
	addVertex(G, u);
	cout << "图中的顶点个数为：" << endl;
	cout << getNumVertices(G) << endl;
	bianli(G);
	cout << "请输入想要加入的边：" << endl;
	cin >> u >> v;
	addEdge(G, u, v);
	cout << "图中的边的个数为：" << endl;
	cout << getNumEdges(G) << endl;
	bianli(G);
	cout << "请输入想要移除的边：" << endl;
	cin >> u >> v;
	removeEdge(G, u, v);
	cout << "图中的边的个数为：" << endl;
	cout << getNumEdges(G) << endl;
	bianli(G);
	cout << "请输入新图的顶点v：" << endl;
	cin >> v;
	length2Paths(G, v, NG);
	bianli(NG);
	cout << "请输入新图的长度和顶点：" << endl;
	cin >> length >> v;
	H=nixu(G);
	NG = BFS(H, length, v, G);
	bianli(NG);
	return 0;
}