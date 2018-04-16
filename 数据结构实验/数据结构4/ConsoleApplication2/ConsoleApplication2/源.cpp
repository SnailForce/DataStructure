#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;
typedef struct HTNode
{
	int weight;
	int parent, lchild, rchild;
}*HuffmanTree;
typedef char *Huff;
typedef Huff *HuffCode;
void Select(const HuffmanTree HT, int j, int &s1, int &s2)
{
	int i, min1, min2;
	min1 = min2 = INT_MAX;
	s1 = s2 = 0;
	for (i = 1; i < j; ++i)
	{
		if (HT[i].parent == 0)
		{
			if (HT[i].weight < min1)
			{
				min2 = min1;
				s2 = s1;
				min1 = HT[i].weight;
				s1 = i;
			}
			else
				if (HT[i].weight >= min1&&HT[i].weight < min2)
				{
					min2 = HT[i].weight;
					s2 = i;
				}
		}
	}
}
void HuffmanCoding(HuffmanTree &HT, HuffCode &HC, int *w, int n)
{
	if (n <= 1)
		return;
	int m = 2 * n - 1, i, s1, s2, start, c, f;
	HuffmanTree p;
	Huff cd;
	HT = new HTNode[m + 1];
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w) *p = { *w,0,0,0 };
	for (; i <= m; ++i, ++p) *p = { 0,0,0,0 };
	for (i = n + 1; i <= m; ++i)
	{
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	HC = new Huff[n + 1];
	cd = new char[n];
	cd[n - 1] = '\0';
	for (i = 1; i < n; ++i)
	{
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			if (HT[f].lchild == c)
				cd[--start] = '\0x31';
			else
				cd[--start] = '\0x32';
			HC[i] = new char[n - start];
			strcpy(HC[i], &cd[start]);
		}
	}
	free(cd);
}
int main()
{
	char key[27] = { '0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int w1[9] = { 0,7,19,2,6,32,3,21,10 };
	HuffmanTree HT;
	HuffCode HC;
	HuffmanCoding(HT, HC, w1, 8);
	for (int i = 1; i < 9; ++i)
		cout << w1[i] << ":" << HC[i] << endl;
	return 0;
}