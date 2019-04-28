/*
DSA HW3 Q4
Yuhang Zhou
yz853
4/2/2019

rbtree.h head file is from wikipedia Chinese version
https://zh.wikipedia.org/wiki/%E7%BA%A2%E9%BB%91%E6%A0%91#C++%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81
I made some changes based on the original code, details in the top comments of head file
*/
#include "rbtree.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <math.h>
using namespace std;

int main()
{
    int *data = new int[10000];
    int i = 0;
    int n;
    ofstream file;
    file.open("Q4results.csv");
    srand(time(0));
    for (i = 0; i < 10000; i++)
    {
        *(data + i) = i;
    }
    for (n = 1; n <= 10000; n++)
    {
        unsigned seed = 0;
        shuffle(data, (data + n - 1), default_random_engine(seed)); //shuffle data to insert
        bst t;
        for (i = 0; i < n; i++)
        {
            t.insert(*(data + i));
        }
        int length[1000]; //record the length
        int randnode;
        double total_length = 0;
        for (i = 0; i < 1000; i++)
        {
            randnode = rand() % n;
            length[i] = t.length(randnode);
            total_length += length[i];
        }
        double avg = total_length / 1000;
        double dev;
        double total_dev = 0;
        for (i = 0; i < 1000; i++)
        {
            dev = (length[i] - avg) * (length[i] - avg);
            total_dev += dev;
        }
        double std_dev = sqrt(total_dev / 1000);
        file << n << "," << avg << "," << std_dev << endl;
        if (n % 500 == 0) //just for tracking
        {
            cout << n << endl;
        }
    }
}
