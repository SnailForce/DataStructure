#include <iostream>
using namespace std;
typedef struct Graph
{
	char Vertex[10];
	int VertexNum;
	int EdgeNum;
	int Edges[10][10];
}*PGraph;
void createGraph(Graph &G)
{
	int i, j, k,m,n;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			G.Edges[i][j] = 0;
		}
	}
	cout << "����Ҫ������ͼ�Ķ������ͱ���" << endl;
	cin >> i >> j;
	G.VertexNum = i;
	G.EdgeNum = j;
	for (k = 0; k < i; k++)
	{
		cout << "����ͼ�Ķ���" << endl;
		cin >> G.Vertex[k];
	}
	for (k = 0; k < j; k++)
	{
		cout << "����ͼ�ı�" << endl;
		cin >> m >> n;
		G.Edges[m][n] = 1;
	}
}
int getNumVertices(Graph G)
{
	return G.VertexNum;
}
int getNumEdges(Graph G)
{
	return G.EdgeNum;
}
bool validVertex(Graph G, char u, int &i)
{
	int j;
	for (j = 0; j < G.VertexNum; j++)
	{
		if (G.Vertex[j] == u)
		{
			i = j;
			return 1;
		}
	}
	return 0;
}
bool hasEdge(Graph G, char u, char v, int &i, int &j)
{
	int m, n;
	for (n = 0; n < G.VertexNum; n++)
	{
		if (G.Vertex[n] == v)
		{
			break;
		}
	}
	for (m = 0; m < G.VertexNum; m++)
	{
		if (G.Vertex[m] == u)
		{
			if (G.Edges[m][n] == 1)
			{
				i = m;
				j = n;
				return 1;
			}
		}
	}
	return 0;
}
void addVertex(Graph &G, char u)
{
	G.Vertex[G.VertexNum] = u;
	G.VertexNum++;
}
bool addEdge(Graph &G, char u, char v)
{
	int i, j;
	for (j = 0; j < G.VertexNum; j++)
	{
		if (G.Vertex[j] == v)
		{
			break;
		}
	}
	for (i = 0; i < G.VertexNum; i++)
	{
		if (G.Vertex[i] == u)
		{
			if (G.Edges[i][j] != 1)
			{
				G.Edges[i][j] = 1;
				G.EdgeNum++;
				return 1;
			}
		}
	}
	return 0;
}
bool removeEdge(Graph &G, char u, char v)
{
	int i, j;
	for (j = 0; j < G.VertexNum; j++)
	{
		if (G.Vertex[j] == v)
		{
			break;
		}
	}
	for (i = 0; i < G.VertexNum; i++)
	{
		if (G.Vertex[i] == u)
		{
			if (G.Edges[i][j] == 1)
			{
				G.Edges[i][j] = 0;
				G.EdgeNum--;
				return 1;
			}
		}
	}
	return 0;
}
void shuchu(Graph G)
{
	int i, j;
	for (i = 0; i < G.VertexNum; i++)
	{
		cout << G.Vertex[i] << " ";
		for (j = 0; j < G.VertexNum; j++)
		{
			cout << G.Edges[i][j] << " ";
		}
		cout << endl;
	}
}
void zhuanzhi(Graph G,Graph &H)
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			H.Edges[i][j] = 0;
		}
	}
	for (i = 0; i < G.VertexNum; i++)
	{
		H.Vertex[i] = G.Vertex[i];
	}
	H.EdgeNum = G.EdgeNum;
	H.VertexNum = G.VertexNum;
	for (i = 0; i < G.VertexNum; i++)
	{
		for (j = 0; j < G.VertexNum; j++)
		{
			if (G.Edges[i][j] != 0)
			{
				H.Edges[j][i] = G.Edges[i][j];
			}
		}
	}
}
void jzcf(Graph G, Graph &NG)
{
	int i, j, k;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			NG.Edges[i][j] = 0;
		}
	}
	for (i = 0; i < G.VertexNum; i++)
	{
		NG.Vertex[i] = G.Vertex[i];
	}
	NG.EdgeNum = G.EdgeNum;
	NG.VertexNum = G.VertexNum;
	for (i = 0; i < G.VertexNum; i++)
	{
		for (j = 0; j < G.VertexNum; j++)
		{
			for (k = 0; k < G.VertexNum; k++)
			{
				NG.Edges[i][k] += G.Edges[i][j] * G.Edges[j][k];
			}
		}
	}
}
Graph gjcf(Graph G, Graph NG)
{
	int i, j, k;
	Graph MG;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			MG.Edges[i][j] = 0;
		}
	}
	for (i = 0; i < G.VertexNum; i++)
	{
		MG.Vertex[i] = G.Vertex[i];
	}
	MG.EdgeNum = G.EdgeNum;
	MG.VertexNum = G.VertexNum;
	for (i = 0; i < G.VertexNum; i++)
	{
		for (j = 0; j < G.VertexNum; j++)
		{
			for (k = 0; k < G.VertexNum; k++)
			{
				MG.Edges[i][k] += NG.Edges[i][j] * G.Edges[j][k];
			}
		}
	}
	return MG;
}
void shuchu2(Graph G,int k)
{
	int i, j;
	for (i = 0; i < G.VertexNum; i++)
	{
		cout << G.Vertex[i] << " ";
		for (j = 0; j < G.VertexNum; j++)
		{
			if (G.Edges[i][j] != 0&&j==k)
			{
				cout << 1 << " ";
			}
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
}
void length2Paths(Graph &H, char v,Graph &NG)
{
	int i, j, k;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			NG.Edges[i][j] = 0;
		}
	}
	for (i = 0; i < H.VertexNum; i++)
	{
		NG.Vertex[i] = H.Vertex[i];
	}
	NG.VertexNum = H.VertexNum;
    validVertex(H, v, k);
	for (i = 0; i < H.VertexNum; i++)
	{
		if (H.Edges[k][i] == 1)
		{
			for (j = 0; j < H.VertexNum; j++)
			{
				if (H.Edges[i][j] == 1)
				{
					NG.Edges[j][k] = 1;
					NG.EdgeNum++;
				}
			}
		}
	}
}
void length(Graph &NG, int length,char v)
{
	int i, j;
	for (i = 0; i < NG.VertexNum; i++)
	{
		for (j = 0; j < NG.VertexNum; j++)
		{
			if (NG.Edges[i][j] != length)
			{
				NG.Edges[i][j] = 0;
			}
		}
	}
}
void lujing(Graph G, char u)
{
	int i, j, k;
	validVertex(G, u, k);
	for (i = 0; i < G.VertexNum; i++)
	{
		for (j = 0; j < G.VertexNum; j++)
		{
			if (G.Edges[i][j] != 0 && G.Edges[j][k] != 0)
			{
				cout << i << "->" << j << "->" << k << endl;
			}
		}
	}
}
int main()
{
	int i, j, k, length;
	char u, v;
	Graph G, H, NG, MG;
	createGraph(G);
	shuchu(G);
	/*cout << "Gͼ�Ķ�������ͱ߸���Ϊ��" << endl;
	cout << getNumVertices(G) << " " << getNumEdges(G) << endl;
	cout << "����Ҫ��ѯ�Ķ���:" << endl;
	cin >> u;
	validVertex(G, u, i);
	cout << "��ѯ�Ķ���λ����" << endl;
	cout << i << endl;
	cout << "����Ҫ��ѯ�ıߵ���������:" << endl;
	cin >> u >> v;
	i = -1;
	j = -1;
	hasEdge(G, u, v, i, j);
	cout << "��ѯ�ı�����λ����:" << endl;
	cout << i << " " << j << endl;
	cout << "����Ҫ��ӵĶ���:" << endl;
	cin >> u;
	addVertex(G, u);
	shuchu(G);
	cout << "����Ҫ��ӵıߵ���������" << endl;
	cin >> u >> v;
	addEdge(G, u, v);
	shuchu(G);
	cout << "����Ҫ�Ƴ��ıߵ���������" <<endl;
	cin >> u >> v;
	removeEdge(G, u, v);
	shuchu(G);*/
	cout << "����Ҫ��ѯ�Ķ��㣬����Ϊ2" << endl;
	cin >> u;
	validVertex(G, u, i);
	jzcf(G, NG);
	shuchu2(NG,i);
	lujing(G, u);
	cout << "���볤�ȺͲ�ѯ�Ķ���" << endl;
	cin >> length >> u;
	validVertex(G, u, j);
	MG = NG;
	for (i = 2; i < length; i++)
	{
		MG = gjcf(G, MG);
	}
	shuchu2(MG, j);
	system("pause");	
	return 0;
}