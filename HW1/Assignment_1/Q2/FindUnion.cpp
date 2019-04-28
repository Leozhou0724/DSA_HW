/*
HW1 Q2
Yuhang Zhou
yz853
reference: lecture slides fundamentals-I.s19 FindUnion part
*/
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

void load(int n, int pid[], int qid[]);
bool find1(int p, int q, int id[]);
void union1(int p, int q, int id[], int n);
int root(int i, int id[]);
bool find2(int p, int q, int id[]);
void union2(int p, int q, int id[]);
void union3(int p, int q, int id[], int sz[]);

int main()
{
	cout << "Pair\tQkFind\t\tQkUnion\t\tWeBalan" << endl;
	int a[7] = { 8,32,128,512,1024,4096,8192 };
	for (int i = 0; i < 7; i++)
	{
		int n = a[i];
		cout << n << "\t";
		int id[8192], p[8192], q[8192];
		for (int i = 0; i < 8192; i++)
		{
			id[i] = i;
		}
		load(n, p, q);				//the name of file read is npair.txt, in the load() function
		clock_t time1, time2, time3, time4, time5, time6;


		//quick find
		time1 = clock();
		for (int i = 0; i < n; i++)
		{
			if (find1(p[i], q[i], id) == false)			//Union this pair if they are not connected
			{
				union1(p[i], q[i], id, n);				//The comment below can print this pair, but it will be a mess
				//cout << p[i] << " & "<<q[i] << endl;
			}
		}
		time2 = clock();
		cout << (double)(time2 - time1) / CLOCKS_PER_SEC << "\t\t";


		for (int i = 0; i < 8192; i++)		//recover id[]
		{
			id[i] = i;
		}
		//quick union
		time3 = clock();
		for (int i = 0; i < n; i++)
		{
			if (find2(p[i], q[i], id) == false)
			{
				union2(p[i], q[i], id);
				//cout << p[i] << " & "<<q[i] << endl;
			}
		}
		time4 = clock();
		cout << (double)(time4 - time3) / CLOCKS_PER_SEC << "\t\t";


		for (int i = 0; i < 8192; i++)			//recover id[]
		{
			id[i] = i;
		}
		//quick union with weight balancing
		time5 = clock();
		int sz[8192];							//initial an array to record the weight
		for (int i = 0; i < 8192; i++)
		{
			sz[i] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			if (find2(p[i], q[i], id) == false)			//the find() of Q2 and Q3 are the same
			{
				union3(p[i], q[i], id, sz);
				//cout << p[i] << " & "<<q[i] << endl;
			}
		}
		time6 = clock();
		cout << (double)(time6 - time5) / CLOCKS_PER_SEC << endl;

	}
	



	
}

void load(int n, int p[],int q[])
{
	int i = 0;
	int pp, qq;
	string filename = to_string(n) + "pair.txt";		//file name
	ifstream file(filename, ios::in);
	while (file >> pp >> qq)							//load p and q into 2 arraies
	{
		p[i] = pp;
		q[i] = qq;
		i++;
	}
}

bool find1(int p, int q, int id[])						//following functions are based on the codes in the lecture slides
{
	return id[p] == id[q];
}

void union1(int p, int q, int id[], int n)
{
	int pid = id[p];
	int qid = id[q];
	for (int i = 0; i < n; i++)
	{
		if (id[i] == pid)
		{
			id[i] = qid;
		}
	}
}

int root(int i, int id[])
{
	while (i != id[i])
	{
		i = id[i];
	}
	return i;
}

bool find2(int p, int q, int id[])
{
	return root(p, id) == root(q, id);
}

void union2(int p, int q, int id[])
{
	int i = root(p, id);
	int j = root(q, id);
	id[i] = j;
}

void union3(int p, int q, int id[], int sz[])
{
	int i = root(p, id);
	int j = root(q, id);
	if (sz[i] < sz[j])
	{
		id[i] = j;
		sz[j] = sz[j] + sz[i];
	}
	else
	{
		id[j] = i;
		sz[i] = sz[i] + sz[j];
	}
}
