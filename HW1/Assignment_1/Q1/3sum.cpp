/*
HW1 Q1 3Sum
Yuhang Zhou
yz853
2/17/2019
Reference； lecture slides fundamentals-I 3sum part
*/
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;
using std::string;
void threesum(int n, int a[]);
int main()
{
	cout << "8int:" << endl;
	int n = 8, a[8];			
	threesum(n, a);				//the file name will be "nint.txt", detail in the threesum() function

	cout << "\n32int:" << endl;
	n = 32;
	int b[32];					//creat different size array for different input data
	threesum(n, b);

	cout << "\n128int:" << endl;
	n = 128;
	int c[128];
	threesum(n, c);

	cout << "\n512int:" << endl;
	n = 512;
	int d[512];
	threesum(n, d);

	cout << "\n1024int:" << endl;
	n = 1024;
	int e[1024];
	threesum(n, e);

	cout << "\n4096int:" << endl;		//run time will be long since here, need patient to wait
	n = 4096;
	int f[4096];
	threesum(n, f);

	cout << "\n4192int:" << endl;
	n = 4192;
	int g[4192];
	threesum(n, g);

	cout << "\n8192int:" << endl;
	n = 8192;
	int h[8192];
	threesum(n, h);
}

void threesum(int n,int a[])
{
	//const int n=8;
	int i = 0;
	//int a[n];
	int m;
	string filename = to_string(n) + "int.txt";				//file name "nint.txt"
	ifstream file(filename, ios::in);
	while (file >> m)										//load data into a[i]
	{
		a[i] = m;
		i++;
	}
	clock_t time1, time2, time3, time4;
	cout << "O(N^3) 3 sum program: " << endl;

	time1 = clock();										//record time
	int count = 0;
	for (i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (a[i] + a[j] + a[k] == 0)
				{
					count++;
					//cout << a[i] << " " << a[j] << " " << a[k] << endl;
				}
			}
		}
	}
	time2 = clock();
	//cout << "Count is " << count << endl;
	cout << "Run time is " << (double)(time2 - time1) / CLOCKS_PER_SEC << " s" << endl;		//time difference is the run time

	//sort
	for (i = 0; i < n - 1; i++)								//bubble sort the data
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	
	cout << "O(N^2 lg N) 3 sum program: " << endl;
	time3 = clock();
	count = 0;
	for (i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int low = j + 1, high = n, mid;							//binary research starts here
			int third = -a[i] - a[j];
			while (low <= high)
			{

				mid = (low + high) / 2;
				if (a[mid] == third)
				{
					count++;
					//cout << a[i] << " " << a[j] << " " << a[mid] << endl;
					low = high + 1;
				}
				else if (a[mid] < third)
				{
					low = mid + 1;
				}
				else high = mid - 1;
			}
		}
	}
	time4 = clock();
	//cout << "Count is " << count << endl;
	cout << "Run time is " << (double)(time4 - time3) / CLOCKS_PER_SEC << " s" << endl;
}
