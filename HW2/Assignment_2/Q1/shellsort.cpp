/*
HW2 Q1	Shellsort
Yuhang Zhou
yz853

Reference:Shellsort From Wikipedia, the free encyclopedia   
          https://en.wikipedia.org/wiki/Shellsort
*/
#include  <iostream> 
#include <fstream>
#include <string>
using namespace std;
void load(int n, int a[], int b[]);
int shellsort(int a[], int n);
int insertionsort(int a[], int n);
int main()
{
	int a[32768];					//Initialize 2 arrays for shellsort and insertionsort seperately, but the data of arrays is the same
	int b[32768];					//Because whether the array is already sorted may affect the result, I prepare two arrays for these two functions
	int nn[] = { 1024,2048,4096,8192,16384,32768 };
	cout << "Ints\tShellsort\tInsertionsort" << endl;
	for (int i = 0; i < 6; i++)
	{
		int n = nn[i];
		load(n, a, b);				// "n" is for numbers of ints, also a part of file name, shown in the load()
		cout << n << "\t" << shellsort(a, n) << "\t\t" << insertionsort(b, n) << endl;	//these two functions will return the comparison numbers
	}
	return 0;
}

void load(int n, int a[], int b[])
{
	string filename = "data1." + to_string(n);			//the name of read file is "data1.n"
	ifstream file(filename, ios::in);
	int i = 0;
	int m;
	while (file >> m)
	{
		a[i] = m;										//load data to a[] and b[]
		b[i] = m;
		i++;
	}
}

int shellsort(int a[], int n)
{
	int count = 0;
	int g[] = { 7,3,1 };								//increment sequence 7, 3, 1
	for (int x = 0; x < 3; x++)
	{
		int gap = g[x];
		for (int i = gap; i < n; i += 1)
		{
			int temp = a[i];							//the i starts from the second gap, then compare with the data which is one gap before itself
			int j;
			count++;									//every data needs to compare with the data before itself, that's one comparisom
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)	//data is smaller than the data before itself, swap them
			{
				a[j] = a[j - gap];
				count++;								//if a swap happens, after that this data needs to compare with the data before itself once more
			}
			a[j] = temp;
		}
	}
	return count;
}
int insertionsort(int a[], int n)
{
	int count = 0;
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
	return count;
}
