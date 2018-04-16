#include<iostream>
#include<string.h>
#include<fstream>
#include<limits>
using namespace std;
#define MAXSIZE 100
int total = 25;
struct train 
{
	int price, atime, ltime;
	char name[5];
	train *next;
};
struct airplane 
{
	int price, atime, ltime;
	char name[6];
	airplane *next;
};
struct route 
{
	int num;
	char name[3];
	train *train;
	airplane *plane;
	route *next;
};
struct citys 
{
	int num;
	char name[3];
	citys *next1; 
	route *next2;
};
struct trainroute
{
	int flag, num, price, atime, ltime;
	char name[5];
};
struct planeroute
{
	int flag, num, price, atime, ltime;
	char name[6];
};
void city(int i)
{
	switch (i)
	{
		case 1:
			cout << "哈尔滨" << endl;
		case 2:
			cout << "长春" << endl;
		case 3:
			cout << "沈阳" << endl;
		case 4:
			cout << "大连" << endl;
		case 5:
			cout << "天津" << endl;
		case 6:
			cout << "徐州" << endl;
		case 7:
			cout << "上海" << endl;
		case 8:
			cout << "福州" << endl;
		case 9:
			cout << "南昌" << endl;
		case 10:
			cout << "北京" << endl;
		case 11:
			cout << "郑州" << endl;
		case 12:
			cout << "武汉" << endl;
		case 13:
			cout << "株洲" << endl;
		case 14:
			cout << "广州" << endl;
		case 15:
			cout << "深圳" << endl;
		case 16:
			cout << "呼和浩特" << endl;
		case 17:
			cout << "西安" << endl;
		case 18:
			cout << "柳州" << endl;
		case 19:
			cout << "贵阳" << endl;
		case 20:
			cout << "南宁" << endl;
		case 21:
			cout << "兰州" << endl;
		case 22:
			cout << "成都" << endl;
		case 23:
			cout << "昆明" << endl;
		case 24:
			cout << "西宁" << endl;
		case 25:
			cout << "乌鲁木齐" << endl;
	}
}
void InitGraph(citys *c1)
{
	int i, j, k, m = 0;
	train *t1, *t2;
	citys *q1, *s1;
	ifstream infile;
	c1->next1 = NULL;
	c1->next2 = NULL;
	s1 = c1;
	infile.open("city.txt",ios_base::in);
	for (i = 1; i <= total; i++) 
	{
		q1 = new citys;
		q1->num = i;
		infile.getline(q1->name, sizeof(q1->name));
		q1->next1 = NULL;
		q1->next2 = NULL;
		s1->next1 = q1;
		s1 = s1->next1;
	}
	infile.close();
	route *r1, *r2;
	infile.open("route.txt", ios_base::in);
	k = 0;
	while (m == 0) 
	{
		infile >> i >> j;
		if (i == total)
		{
			m = 1;
		}
		q1 = c1->next1;
		while (q1->num != i)
		{
			q1 = q1->next1;
		}
		r1 = new route;
		if (i == k) 
		{
			r2->next = r1;
		}
		else 
		{
			q1->next2 = r1;
		}
		s1 = c1->next1;
		while (s1->num != j)
		{
			s1 = s1->next1;
		}
		r1->num = s1->num;
		strcpy(r1->name, s1->name);
		strcpy(r1->name, s1->name);
		r1->next = NULL;
		r1->train = NULL;
		r1->plane = NULL;
		r2 = r1;
		k = i;
	}
	infile.close();
	infile.open("train.txt", ios_base::in);

	while (!infile.eof() )
	{
		t1 = new train;
		infile >> i >> j >> t1->name >> t1->price >> t1->ltime >> t1->atime;
		t1->next = NULL;
		q1 = c1->next1;
		while (q1->num != i)
		{
			q1 = q1->next1;
		}
		r1 = q1->next2;
		while (r1->num != j)
		{
			r1 = r1->next;
		}
		t2 = r1->train;
		if (t2) 
		{
			while (t2->next)
			{
				t2 = t2->next;
			}
			t2->next = t1;
		}
		else 
		{
			r1->train = t1;
		}
	}
	infile.close();
	infile.open("plane.txt", ios_base::in);
	airplane *a2, *a3;
	while (!infile.eof()) 
	{
		a2 = new airplane;
		infile >> i >> j >> a2->name >> a2->price >> a2->ltime >> a2->atime;
		a2->next = NULL;
		q1 = c1->next1;
		while (q1->num != i)
		{
			q1 = q1->next1;
		}
		r1 = q1->next2;
		while (r1->num != j)
		{
			r1 = r1->next;
		}
		a3 = r1->plane;
		if (a3) 
		{
			while (a3->next)
			{
				a3 = a3->next;
			}
			a3->next = a2;
		}
		else 
		{
			r1->plane = a2;
		}
	}
}
void Addcity(citys *c1)
{
	citys a2, *p;
	cout << "要添加的城市名称为" << endl;
	cin >> a2.name;
	a2.num = ++total;
	a2.next1 = NULL;
	a2.next2 = NULL;
	p = c1->next1;
	while (p->next1)
	{
		p = p->next1;
	}
	p->next1 = &a2;
}
void Deletcity(citys *c1)
{
	citys *c2, *c3;
	route *r1, *r2;
	train *t1, *t2;
	airplane *a1, *a2;
	int n1;
	cout << "输入要删去的城市" << endl;
	cin >> n1;
	c2 = c1->next1;
	c3 = c1;
	while (c2->num != n1)
	{
		c2 = c2->next1;
		c3 = c3->next1;
	}
	r1 = c2->next2;
	r2 = c2->next2->next;
	while (r1)
	{
		t1 = r1->train;
		t2 = r1->train->next;
		while (t1)
		{
			delete c2;
			t1 = t2;
			if (t2)
			{
				t2 = t1->next;
			}
		}
		a1 = r1->plane;
		a2 = r1->plane->next;
		while (a1)
		{
			delete a1;
			a1 = a2;
			if (a2)
			{
				a2 = a1->next;
			}
		}
		delete r1;
		r1 = r2;
		if (r2)
		{
			r2 = r1->next;
		}
	}
	c3->next1 = c2->next1;
	delete c2;
	c2 = c1->next1;
	while (c2)
	{
		if (c2->next2->num == n1)
		{
			r2 = c2->next2;
			t1 = r2->train;
			t2 = r2->train->next;
			while (t1)
			{
				delete t1;
				t1 = t2;
				if (t2)
				{
					t2 = t1->next;
				}
			}
			a1 = r2->plane;
			a2 = r2->plane->next;
			while (a1)
			{
				delete a1;
				a1 = a2;
				if (a2)
				{
					a2 = a1->next;
				}
			}
			c2->next2 = r2->next;
			delete r2;
		}
		r1 = c2->next2;
		while (r1&&r1->next)
		{
			if (r1->next->num == n1)
			{
				r2 = r1->next;
				t1 = r2->train;
				t2 = r2->train->next;
				while (t1)
				{
					delete t1;
					t1 = t2;
					if (t2)
					{
						t2 = t1->next;
					}
				}
				a1 = r2->plane;
				a2 = r2->plane->next;
				while (a1)
				{
					delete a1;
					a1 = a2;
					if (a2)
					{
						a2 = a1->next;
					}
				}
				r1->next = r2->next;
				delete r2;
			}
			r1 = r1->next;
		}
		c2 = c2->next1;
	}
	total--;
}
void Addtrain(citys *c1)
{
	int i, j;
	citys *c;
	route *r;
	train  *t1, t2;
	cout << "输入起点和终点的序号" << endl;
	cin >> i >> j;
	cout << "火车的名称" << endl;
	cin >> t2.name;
	cout << "输入出发时间和到达时间" << endl;
	cin >> t2.ltime >> t2.atime;
	c = c1->next1;
	while (c->num != i)
	{
		c = c->next1;
	}
	r = c->next2;
	while (r->num != j)
	{
		r = r->next;
	}
	t1 = r->train;
	while (t1->next)
	{
		t1 = t1->next;
	}
	t1->next = &t2;
}
void Addplane(citys *c1)
{
	int i, j;
	citys *c;
	route *a;
	airplane a1, *a2;
	cout << "输入起点和终点的序号" << endl;
	cin >> i >> j;
	cout << "输入飞机的名称" << endl;
	cin >> a1.name;
	cout << "输入出发时间和到达时间" << endl;
	cin >> a1.ltime >> a1.atime;
	c = c1->next1;
	while (c->num != i)
	{
		c = c->next1;
	}
	a = c->next2;
	while (a->num != j)
	{
		a = a->next;
	}
	a2 = a->plane;
	while (a2->next)
	{
		a2 = a2->next;
	}
	a2->next = &a1;
}
void Deletetrain(citys *c1)
{
	int i, j;
	citys *p;
	route *a;
	train t, *t1, *t2;
	cout << "输入起点和终点的序号" << endl;
	cin >> i >> j;
	cout << "火车的名称" << endl;
	cin >> t.name;
	p = c1->next1;
	while (p->num != i)
	{
		p = p->next1;
	}
	a = p->next2;
	while (a->num != j)
	{
		a = a->next;
	}
	if (strcmp(a->train->name, t.name) == 0) 
	{
		t1 = a->train;
		a->train = t1->next;
		free(t1);
	}
	else 
	{
		t1 = a->train;
		while (strcmp(t1->next->name,t.name))
		{
			t1 = t1->next;
		}
		t2 = t1->next;
		t1->next = t2->next;
		free(t2);
	}
}
void Deleteplane(citys *c1)
{
	int i, j;
	citys *p;
	route *a;
	airplane t, *t1, *t2;
	cout << "输入起点和终点的序号" << endl;
	cin >> i >> j;
	cout << "飞机的名称" << endl;
	cin >> t.name;
	p = c1->next1;
	while (p->num != i)
	{
		p = p->next1;
	}
	a = p->next2;
	while (a->num != j)
	{
		a = a->next;
	}
	if (strcmp(a->plane->name, t.name) == 0) 
	{
		t1 = a->plane;
		a->plane = t1->next;
		delete t1;
	}
	else
	{
		t1 - a->plane;
		while (strcmp(t1->next->name, t.name))
		{
			t1 = t1->next;
		}
		t2 = t1->next;
		t1->next = t2->next;
		delete t2;
	}
}
void Faststrain(citys *c, int qs, int zd)
{
	int i, D[MAXSIZE + 1], min, w, v, S[MAXSIZE + 1], j;
	trainroute A[MAXSIZE + 1];
	citys *q1, *q2;
	route *r1;
	train *t1, *t2;
	for (i = 1; i <= total; i++)
	{
		A[i].num = i;
		A[i].flag = 0;
	}
	A[qs].num = 0;
	A[qs].flag = 1;
	for (i = 1; i <= total; i++)
	{
		D[i] = INT_MAX;
	}
	q1 = c->next1;
	while (q1->num != qs)
	{
		q1 = q1->next1;
	}
	r1 = q1->next2;
	while (r1)
	{
		t1 = r1->train;
		t2 = r1->train;
		while (t1)
		{
			if (t1->atime - t1->ltime < t2->atime - t2->ltime)
			{
				t2 = t1;
			}
			t1 = t1->next;
		}
		D[r1->num] = (t2->atime - t2->ltime + 48) % 24;
		A[r1->num].num = q1->num;
		A[r1->num].price = t2->price;
		A[r1->num].atime = t2->atime;
		A[r1->num].ltime = t2->ltime;
		strcpy(A[r1->num].name, t2->name);
		r1 = r1->next;
	}
	for (i = 1; i<total; i++) 
	{
		min = INT_MAX;
		for (w = 1; w <= total; w++)
		{
			if (A[w].flag == 0)
			{
				if (D[w]<min) 
				{
					v = w;
					min = D[w];
				}
			}
		}
		A[v].flag = 1;
		q1 = c->next1;
		while (q1->num != v)
		{
			q1 = q1->next1;
		}
		r1 = q1->next2;
		while (r1)
		{
			if (A[r1->num].flag == 0)
			{
				t2 = r1->train;
				while (t2)
				{
					if (min + (t2->atime - t2->ltime + (t2->ltime - A[v].atime + 48) % 24)<D[r1->num])
					{
						D[r1->num] = min + t2->atime - t2->ltime + (t2->ltime - A[v].atime + 48) % 24;
						A[r1->num].num = v;
						A[r1->num].price = t2->price;
						A[r1->num].atime = t2->atime;
						A[r1->num].ltime = t2->ltime;
						strcpy(A[r1->num].name, t2->name);
					}
					t2 = t2->next;
				}
			}
			r1 = r1->next;
		}
	}
	for (i = zd, j = 1; i != 0; i = A[i].num)
	{
		S[j] = i;
		j++;
	}
	S[0] = zd;
	for (j = j - 1; j >= 3; j--)
	{
		city(A[S[j - 1]].num);
		cout << "->";
		city(A[S[j - 2]].num);
		cout << A[S[j - 1]].name << A[S[j - 1]].ltime << A[S[j - 1]].atime << endl;
	}
	city(A[S[j - 1]].num);
	cout << "->";
	city(zd);
	cout << A[S[j - 1]].name << A[S[j - 1]].ltime << A[S[j - 1]].atime << endl;
	cout << D[zd] << endl;
}
void Fastplane(citys *c, int qs, int zd)
{
	int i, D[MAXSIZE + 1], min, w, v, S[MAXSIZE + 1], j;
	planeroute A[MAXSIZE + 1];
	citys *q1, *q2;
	route *r1;
	airplane *t1, *t2;
	for (i = 1; i <= total; i++)
	{
		A[i].num = i;
		A[i].flag = 0;
	}
	A[qs].num = 0;
	A[qs].flag = 1;
	for (i = 1; i <= total; i++)
	{
		D[i] = INT_MAX;
	}
	q1 = c->next1;
	while (q1->num != qs)
	{
		q1 = q1->next1;
	}
	r1 = q1->next2;
	while (r1)
	{
		min = INT_MAX;
		for (t1 = r1->plane; t1 != NULL; t1 = t1->next) 
		{
			if ((48 + t1->atime - t1->ltime) % 24<min) 
			{
				t2 = t1;
				min = (48 + t1->atime - t1->ltime) % 24;
			}
		}
		D[r1->num] = (t2->atime - t2->ltime + 48) % 24;
		A[r1->num].num = q1->num;
		A[r1->num].price = t2->price;
		A[r1->num].atime = t2->atime;
		A[r1->num].ltime = t2->ltime;
		strcpy(A[r1->num].name, t2->name);
		r1 = r1->next;
	}
	for (i = 1; i<total; i++) 
	{
		min = INT_MAX;
		for (w = 1; w <= total; w++) 
		{
			if (A[w].flag == 0)
			{
				if (D[w]<min) 
				{
					v = w;
					min = D[w];
				}
			}
		}
		A[v].flag = 1;
		for (q1 = c->next1; q1->num != v; q1 = q1->next1);
		for (r1 = q1->next2; r1 != NULL; r1 = r1->next) 
		{
			if (A[r1->num].flag == 0)
			{
				for (t2 = r1->plane; t2 != NULL; t2 = t2->next) 
				{
					if (min + (t2->atime - t2->ltime + (t2->ltime - A[v].atime + 48) % 24)<D[r1->num]) 
					{
						D[r1->num] = min + (t2->atime - t2->ltime + (t2->ltime - A[v].atime + 48) % 24);
						A[r1->num].num = v;
						A[r1->num].price = t2->price;
						A[r1->num].atime = t2->atime;
						A[r1->num].ltime = t2->ltime;
						strcpy(A[r1->num].name, t2->name);
					}
				}

			}
		}
	}
	for (i = zd, j = 1; i != 0; i = A[i].num) 
	{
		S[j] = i;
		j++;
	}
	S[0] = zd;
	for (j = j - 1; j >= 3; j--) 
	{
		city(A[S[j - 1]].num);
		cout << "->";
		city(A[S[j - 2]].num);
		cout << A[S[j - 1]].name << A[S[j - 1]].ltime << A[S[j - 1]].atime;
	}
	city(A[S[j - 1]].num);
	cout << "->";
	city(zd);
	cout << A[S[j - 1]].name << A[S[j - 1]].ltime << A[S[j - 1]].atime;
	cout << "时间为" << D[zd];
}
void Moneysavingtrain(citys *c, int qs, int zd)
{
	trainroute A[MAXSIZE + 1];
	int i, D[MAXSIZE + 1], min, w, v, S[MAXSIZE + 1], j;
	for (i = 1; i <= total; i++)
	{
		A[i].num = i;
		A[i].flag = 0;
	}
	A[qs].num = 0;
	A[qs].flag = 1;
	for (i = 1; i <= total; i++)
	{
		D[i] = INT_MAX;
	}
	citys *q1, *q2;
	route *r1;
	train *t1, *t2;
	q1 = c->next1;
	while (q1->num != qs)
	{
		q1 = q1->next1;
	}
	r1 = q1->next2;
	while (r1)
	{
		t1 = r1->train;
		t2 = r1->train;
		while (t1)
		{
			if (t1->price < t2->price)
			{
				t2 = t1;
			}
			t1 = t1->next;
		}
		D[r1->num] = t2->price;
		A[r1->num].num = q1->num;
		A[r1->num].price = t2->price;
		A[r1->num].atime = t2->atime;
		A[r1->num].ltime = t2->ltime;
		strcpy(A[r1->num].name, t2->name);
		r1 = r1->next;
	}
	for (i = 1; i<total; i++) 
	{
		min = INT_MAX;
		for (w = 1; w <= total; w++) 
		{
			if (A[w].flag == 0)
			{
				if (D[w] < min)
				{
					v = w;
					min = D[w];
				}
			}
		}
		A[v].flag = 1;
		q1 = c->next1;
		while (q1->num != v)
		{
			q1 = q1->next1;
		}
		r1 = q1->next2;
		while (r1)
		{
			if (A[r1->num].flag == 0) 
			{
				t2 = r1->train;
				while (t2)
				{
					if (min + t2->price < D[r1->num])
					{
						D[r1->num] = min + t2->price;
						A[r1->num].num = v;
						A[r1->num].price = t2->price;
						A[r1->num].atime = t2->atime;
						A[r1->num].ltime = t2->ltime;
						strcpy(A[r1->num].name, t2->name);
					}
					t2 = t2->next;
				}
			}
			r1 = r1->next;
		}
	}
	for (i = zd, j = 1; i != 0; i = A[i].num)
	{
		S[j] = i;
		j++;
	}
	S[0] = zd;
	for (j = j - 1; j >= 3; j--)
	{
		city(A[S[j - 1]].num);
		cout << "->";
		city(A[S[j - 2]].num);
		cout << A[S[j - 1]].name << A[S[j - 1]].ltime << A[S[j - 1]].atime;
	}
	city(A[S[j - 1]].num);
	cout << "->";
	city(zd);
	cout << A[S[j - 1]].name << A[S[j - 1]].ltime << A[S[j - 1]].atime;
	cout << "金钱为" << D[zd] << endl;
}
void Moneysavingplane(citys *c, int qs, int zd)
{
	int i, D[MAXSIZE + 1], min, w, v, S[MAXSIZE + 1], j;
	planeroute A[MAXSIZE + 1];
	citys *q1, *q2;
	route *r1;
	airplane *t1, *t2;
	for (i = 1; i <= total; i++)
	{
		A[i].num = i;
		A[i].flag = 0;
	}
	A[qs].num = 0;
	A[qs].flag = 1;
	for (i = 1; i <= total; i++)
	{
		D[i] = INT_MAX;
	}
	q1 = c->next1;
	while (q1->num != qs)
	{
		q1 = q1->next1;
	}
	r1 = q1->next2;
	while (r1)
	{
		min = INT_MAX;
		t1 = r1->plane;
		while (t1)
		{
			if (t1->price < min)
			{
				t2 = t1;
				min = t1->price;
			}
			t1 = t1->next;
		}
		D[r1->num] = t2->price;
		A[r1->num].num = q1->num;
		A[r1->num].price = t2->price;
		A[r1->num].atime = t2->atime;
		A[r1->num].ltime = t2->ltime;
		strcpy(A[r1->num].name, t2->name);
		r1 = r1->next;
	}
	for (i = 1; i < total; i++)
	{
		min = INT_MAX;
		for (w = 1; w <= total; w++)
		{
			if (A[w].flag == 0)
			{
				if (D[w] < min)
				{
					v = w;
					min = D[w];
				}
			}
		}
		A[v].flag = 1;
		q1 = c->next1;
		while (q1->num != v)
		{
			q1 = q1->next1;
		}
		r1 = q1->next2;
		while (r1)
		{
			if (A[r1->num].flag == 0)
			{
				t2 = r1->plane;
				while (t2)
				{
					if (min + t2->price < D[r1->num])
					{
						D[r1->num] = min + t2->price;
						A[r1->num].num = v;
						A[r1->num].price = t2->price;
						A[r1->num].atime = t2->atime;
						A[r1->num].ltime = t2->ltime;
						strcpy(A[r1->num].name, t2->name);
					}
					t2 = t2->next;
				}
			}
			r1 = r1->next;
		}
	}
	for (i = zd, j = 1; i != 0; i = A[i].num)
	{
		S[j] = i;
		j++;
	}
	S[0] = zd;
	for (j = j - 1; j >= 3; j--)
	{
		city(A[S[j - 1]].num);
		cout << "->";
		city(A[S[j - 2]].num);
		cout << A[S[j - 1]].name << A[S[j - 1]].ltime << A[S[j - 1]].atime;
	}
	city(A[S[j - 1]].num);
	cout << "->";
	city(zd);
	cout << A[S[j - 1]].name << A[S[j - 1]].ltime << A[S[j - 1]].atime;
	cout << "金钱为" << D[zd] << endl;
}
int main()
{
	citys c1;
	int i, j, yz, tp, n = 0;
	InitGraph(&c1);
	for (i = 1, j = 1; i <= total; i++, j++) 
	{
		cin >> i;
		city(i);
		if (j == 5) 
		{
			cout << endl;
			j = 1;
		}

	}
	while (n != 3) 
	{
		cout << "模式选择:1=管理编辑，2=交通咨询,3=退出" << endl;
		cin >> n;
		if (n == 1)
		{
			cout << "输入编辑操作:1=城市操作，2=列车操作，3=航班操作" << endl;
			cin >> n;
			if (n == 1)
			{
				cout << "1=添加，2=删除" << endl;
				cin >> n;
				if (n == 1)
				{
					Addcity(&c1);
				}
				if (n == 2)
				{
					Deletcity(&c1);
				}
			}
			else
			{
				if (n == 2)
				{
					cout << "1=添加，2=删除" << endl;
					cin >> n;
					if (n == 1)
					{
						Addtrain(&c1);
					}
					if (n == 2)
					{
						Deletetrain(&c1);
					}
				}

				else
				{
					if (n == 3)
					{
						cout << "1=添加，2=删除" << endl;
						cin >> n;;
						if (n == 1)
						{
							Addplane(&c1);
						}
						if (n == 2)
						{
							Deleteplane(&c1);
						}
					}
				}
			}
		}
		else 
		{
			if (n == 2)
			{
				cout << "输入起点和终点的序号" << endl;
				cin >> i >> j;
				cout << "输入决策原则:1=最快，2=最省钱" << endl;
				cin >> yz;
				cout << "输入交通工具:1=火车，2=飞机" << endl;
				cin >> tp;
				if (yz == 1) 
				{
					if (tp == 1)
					{
						Faststrain(&c1, i, j);
					}
					if (tp == 2)
					{
						Fastplane(&c1, i, j);
					}
				}
				if (yz == 2)
				{
					if (tp == 1)
					{
						Moneysavingtrain(&c1, i, j);
					}
					if (tp == 2)
					{
						Moneysavingplane(&c1, i, j);
					}
				}
			}
		}
	}
	system("pause");
}
