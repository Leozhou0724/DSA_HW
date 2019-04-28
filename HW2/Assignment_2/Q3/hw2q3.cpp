/*
HW2Q3
Yuhang Zhou
yz853


reference: GeeksforGeeks a computer science portal for geeks, Merge sort
			https://www.geeksforgeeks.org/iterative-merge-sort/
*/
#include <iostream>
using namespace std;
void merge(int a[], int lo, int mid, int hi);
int main()
{
	int a[8192];			//a[] is the dataset
	int i;
	int n = 8192;
	for (i = 0; i < 8192; i++)
	{
		if (i < 1024)
		{
			a[i] = 1111;
		}
		else if (i < 1024+2048)
		{
			a[i] = 111;
		}
		else if (i < 1024 + 2048 + 4096)
		{
			a[i] = 11;
		}
		else
		{
			a[i] = 1;
		}
	}
	
	int po[10];		//I watch a[] as 4 blocks in this sample, the po[] save the index of cut points of blocks
	int m = 0;
	po[m] = -1;		//{-1,1023,3071,7167,8191} the index of the last one of each block, or the one before the first of each block
	m++;			//m is the number of data in po[], which is also as the number of blocks of a[] - 1
	for (i = 0; i < n; i++)
	{
		if (a[i] != a[i + 1])
		{
			po[m] = i;
			m++;
		}
	}
	/*
	for (i = 0; i < m; i++)
	{
		cout << po[i] << endl;
	}
	cout << m;*/
	int size;
	for (size = 1; size < m - 2; size = size * 2)		//similar to the Bottom-up() merge sort I use in Q4
	{
		for (i = 0; i < m - 2; i = i + size * 2)
		{
			int lo = po[i] + 1;							//Change: the size of parts I put in merge() is not fixed, it'a based on these blocks
			int mid = po[i + size];
			int hi = po[i + size * 2];
			merge(a, lo, mid, hi);
		}
	}
	//output
	for (i = 0; i < 8192; i++)
	{
		cout << a[i] << endl;
	}
}

void merge(int a[], int lo, int mid, int hi)		//this is basically the same as the merge() function I use in Q4
{
	int len1 = mid - lo + 1;
	int len2 = hi - mid;
	int L[8192];
	int R[8192];
	for (int i = 0; i < len1; i++)
	{
		L[i] = a[lo + i];					
	}
	for (int i = 0; i < len2; i++)
	{
		R[i] = a[mid + 1 + i];
	}
	int i = 0, j = 0, k = lo;				
	while (i < len1 &&j < len2)
	{									
		if (L[i] <= R[j])
		{
			
			while (L[i] == L[i + 1])		//Change: this can transfer data to a[] if the data is the same as the one before it
			{
				a[k] = L[i];					
				i++;
				k++;
			}
			a[k] = L[i];
			i++;
			k++;
			
		}
		else
		{
			
			while (R[j] == R[j + 1])
			{
				a[k] = R[j];
				j++;
				k++;
			}
			a[k] = R[j];
			j++;
			k++;
		}
	}
	while (i < len1)						
	{
		a[k] = L[i];						
		i++;
		k++;
	}
	while (j < len2)						
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

