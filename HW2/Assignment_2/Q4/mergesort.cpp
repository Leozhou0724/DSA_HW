/*
HW2Q4 Mergesort
Yuhang Zhou
yz853

reference: Merge sort From Wikipedia, the free encyclopedia
			https://en.wikipedia.org/wiki/Merge_sort  &  https://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F#C++
			GeeksforGeeks a computer science portal for geeks, Merge sort
			https://www.geeksforgeeks.org/merge-sort/  &  https://www.geeksforgeeks.org/iterative-merge-sort/
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void load(int n, int a[], int b[]);
void sort(int a[], int lo, int hi, int &count);
void bottomup(int a[], int n, int &count1);
void merge(int a[], int lo, int mid, int hi, int &count);
int main()
{
	int a[32768], b[32768];					//Initialize an array, a[]for top-down, b[] for bottom-up
	int nn[] = { 1024,2048,4096,8192,16384,32768 };
	cout << "Ints\tTop-down\tBottom-up" << endl;
	for (int i = 0; i < 6; i++)
	{
		int n = nn[i];
		load(n, a, b);				// "n" is for numbers of ints, also a part of file name, shown in the load()
		int count0 = 0;			//count0 for counting the numbers of comparisons in Top-Down merge sort
		int count1 = 0;			//count1 for bottom-up algorithm
		sort(a, 0, n - 1, count0);		//transfer the address of count to this function, shown in func sort(&count)
		bottomup(b, n, count1);
		cout << n << "\t" << count0 << "\t\t" << count1 << endl;
	}
	
}

void load(int n, int a[], int b[])
{
	string filename = "data1." + to_string(n);			//the name of read file is "data1.n"
	ifstream file(filename, ios::in);
	int i = 0;
	int m;
	while (file >> m)
	{
		a[i] = m;										//load data to a[]
		b[i] = m;
		i++;
	}
}

void sort(int a[], int lo, int hi, int &count)
{
	if (lo < hi)
	{
		int mid = (lo + hi) / 2;
		sort(a, lo, mid, count);			//make sure the left part is sorted
		sort(a, mid + 1, hi, count);		//sort the right part
		merge(a, lo, mid, hi , count);		//merge this two parts
	}
	
}

void bottomup(int a[], int n, int &count1)
{
	int size;											//the size of the two data which will be merged in the merge()
	for (size = 1; size <= n - 1; size = size * 2)		//the size should not be bigger than n-1, or the whole data can not be divided into 2 parts
	{
		for (int i = 0; i < n - 1; i = i + size * 2)	//i is the start point of two parts which will be merged in this loop, so that i will increase by size*2 after one loop
		{
			int lo = i;
			int mid = lo + size - 1;
			int hi = lo + 2 * size;
			if (hi >= n - 1)							//hi is the end point of the second part, hi cannot be larger than n-1, or there will be no data left for the last time
			{
				hi = n - 1;
			}
			merge(a, lo, mid, hi, count1);				//two algorithm use the same merge()
		}
	}
}

void merge(int a[], int lo, int mid, int hi, int &count)
{
	int len1 = mid - lo + 1;				//get the arrary length of this two parts
	int len2 = hi - mid;
	int L[32768/2];							//creat two seperate arrays. the largest a[] in this dataset is 32768, so the size of each array should be half of that. 
	int	R[32768/2];							//I can't creat array like L[len1], because the size of array should be a constant value, len1 is not a constant, even I use const int len1=...
	for (int i = 0; i < len1; i++)			
	{
		L[i] = a[lo + i];					//two seperate arrays to save data from the original two arrays. then merge sort L[]and R[], put the data back to a[] in order
	}
	for (int i = 0; i < len2; i++)
	{
		R[i] = a[mid + 1 + i];
	}
	int i = 0, j = 0, k = lo;				//i for going through L[], j for R[], k for a[]
	while (i < len1 &&j < len2)
	{
		count++;							//do a comparision at this place, whether L[i] or R[j] is bigger, comparison happens once
		if (L[i] <= R[j])
		{
			a[k] = L[i];					//load the smaller data from L[] and R[] to a[]
			i++;
			k++;
		}
		else
		{
			a[k] = R[j];
			j++;
			k++;
		}
	}
	while (i < len1)						//this part is for when j>=len2, which means all the R[] data have already load to a[]
	{
		a[k] = L[i];						//load the rest data of L[] to a[]
		i++;
		k++;
	}
	while (j < len2)						//the opposite to the upper side while()
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

