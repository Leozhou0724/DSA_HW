/*
HW1 Q5 Faster-est-ist 3-sum
Yuhang Zhou
yz853
2/17/2019
reference: 3SUM From Wikipedia, the free encyclopedia Quadratic algorithm part
		https://en.wikipedia.org/wiki/3SUM
*/
#include <iostream>

using namespace std;
int main()
{
	const int n = 2000;
	int a[n];
	for (int i = 0; i < n; i++)			//rated array a[] to test the 3sum algorithm, a[]is {-1000, -999, -998....1000}, a[]can be any rated array
	{									//or it can use any array, but it needs to be rated first
		a[i] = i - n / 2;
	}

	int count = 0;
	int x, y;
	for (int i = 0; i < n - 2; i++)
	{
		x = i + 1;
		y = n - 1;
		while (x < y)					//find a pair whose sum is -a[i], in the rest data
		{
			if (a[i] + a[x] + a[y] == 0)		//the search starts from the first and the last one in the rest data 
			{
				count++;						
				y--;
			}
			else if (a[i] + a[x] + a[y] > 0)	//if the sum is >0, the last one move forward
			{
				y--;
			}
			else
			{
												//if the sum is <0, the first one move backward
			}
			{
				x++;
			}
		}
	}
	cout << "count = " << count << endl;

}
