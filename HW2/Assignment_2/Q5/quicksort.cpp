/*
HW2 Q5 Quick sort with median-of-three
Yuhang Zhou
yz853

reference: lecture slides "advanced-sorting" quick sort part
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void load(int n, int a[]);
void sort(int a[], int lo, int hi, int &count);

int partition(int a[], int lo, int hi, int &count);
void swap(int a[], int i, int j);
void insertionsort(int a[], int n, int &count);

int main()
{
	int a[32768];					//Initialize an array
	int nn[] = { 1024,2048,4096,8192,16384,32768 };
	cout << "Ints\tComparison" << endl;
	for (int i = 0; i < 6; i++)
	{
		int n = nn[i];
		load(n, a);				// "n" is for numbers of ints, also a part of file name, shown in the load()
		int count = 0;
		sort(a, 0, n - 1, count);
		cout << n << "\t" << count  << endl;
		//cout << count << endl;
	}
	return 0;
}

void load(int n, int a[])
{
	string filename = "data1." + to_string(n);			//the name of read file is "data1.n"
	ifstream file(filename, ios::in);
	int i = 0;
	int m;
	while (file >> m)
	{
		a[i] = m;										//load data to a[] and b[]
		i++;
	}
}

void sort(int a[], int lo, int hi, int &count)
{
	/*
	int cutoff = 500;								//cutoff
	if (hi <= lo + cutoff + 1)						// this part for cutoff test
	{
		insertionsort(a, hi + 1, count);
		return;
	}
	*/
	if (hi > lo)
	{

		
		int mid = lo + (hi - lo) / 2;
		count = count + 3;
		if (a[lo] > a[hi])						//find the mid of 3 and move the mid one to a[lo]
		{
			swap(a, lo, hi);
		}
		if (a[mid] < a[lo])
		{
			swap(a, mid, lo);
		}
		if (a[mid] < a[hi])
		{
			swap(a, mid, lo);
		}
		else
		{
			swap(a, hi, lo);
		}
		int j = partition(a, lo, hi, count);
		sort(a, lo, j - 1, count);
		sort(a, j + 1, hi, count);
	}
}



int partition(int a[], int lo, int hi, int &count)
{
	int i = lo + 1;
	int j = hi;
	while (i < j)
	{
		while (a[i] < a[lo] && i < j)
		{
			i++;
			count++;					//count adds by 1 if the program gets into this while loop
		}
		while (a[j] > a[lo] && i < j)
		{
			j--;
			count++;
		}
		count = count + 2;			//2 comparisons to get out of upper 2 while loops
		swap(a, i, j);
		
	}
	count++;
	if (a[j] <= a[lo])
	{
		swap(a, j, lo);
	}
	else
	{
		j--;
	}
	
	
	return j;
}

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void insertionsort(int a[], int n, int &count)
{
	int gap = 1;						//Insertion sort is actually change the gap to 1
	for (int i = gap; i < n; i += 1)
	{
		count++;
		int temp = a[i];
		int j;
		for (j = i; j >= gap && a[j - gap] > temp; j -= gap)	//comparision happens here
		{
			a[j] = a[j - gap];
			count++;
		}
		a[j] = temp;
	}
}

