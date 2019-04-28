/*
HW2 Q2	Kendall Tau distance
Yuhang Zhou
yz853

 the Kendall Tau distance between these two arrays is that the times of doing swap 
 operations when I use insertion sort to sort the data1.* arrays
*/
#include  <iostream> 
#include <fstream>
#include <string>
using namespace std;
void load(int n, int a[]);
int insertionsort(int a[], int n);
int main()
{
	int a[32768];					//Initialize an array
	int nn[] = { 1024,2048,4096,8192,16384,32768 };
	cout << "Ints\tDistance" << endl;
	for (int i = 0; i < 6; i++)
	{
		int n = nn[i];
		load(n, a);				// "n" is for numbers of ints, also a part of file name, shown in the load()
		cout << n << "\t" <<  insertionsort(a, n) << endl;	//these function will return the times of insertionsort doing swap operations 
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
		a[i] = m;										//load data to a[]
		i++;
	}
}

int insertionsort(int a[], int n)
{
	int count = 0;
	for (int i = 1; i < n; i += 1)
	{

		int temp = a[i];
		int j;
		for (j = i; j >= 1 && a[j - 1] > temp; j -= 1)
		{
			a[j] = a[j - 1];
			count++;
		}
		a[j] = temp;
	}
	return count;
}
