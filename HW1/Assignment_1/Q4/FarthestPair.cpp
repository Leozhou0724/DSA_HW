/*
HW1 Q4 Farthest Pair 
Yuhang Zhou
yz853
2/17/2018

*/
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	const int n = 10;
	double a[n];
	for (int i = 0; i < n; i++)					//create an array a[n], in this one it's{0,1,2.....,9}, it can be any array
	{
		a[i] = i;
	}
	double b[n][n];								//b[n] to record the difference of two data
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = abs(a[i] - a[j]);
		}
	}
	int x, y, s = 0;
	for (int i = 0; i < n; i++)					//find the largest difference and record the index of this pair
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] >= s)
			{
				s = b[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << "a[" << x << "] and a[" << y << "] are the farthest pair." << endl;
}
