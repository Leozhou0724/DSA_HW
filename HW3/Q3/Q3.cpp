/*
DSA HW3 Q3
Yuhang Zhou
yz853
4/2/2019

rbtree.h head file is from wikipedia Chinese version
https://zh.wikipedia.org/wiki/%E7%BA%A2%E9%BB%91%E6%A0%91#C++%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81
I made some changes based on the original code, details in the top comments of head file

*/
//#include "redblacktree.h"
#include "rbtree.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3] = {10000, 100000, 1000000};
    int *data = new int[1000000]; //looks like array[1000000] is over the restriction of the stack in my laptop
                                  //so I use "new" to allocate memory
    int i = 0;
    for (i = 0; i < 1000000; i++)
    {
        *(data + i) = i;
    }
    
    //shuffle(data, (data + 999999), default_random_engine(seed));
    int n;
    for (n = 0; n < 3; n++)
    {
        double red = 0;
        for (int m = 0; m < 100; m++)
        {
            unsigned seed = 0;
            shuffle(data, (data + a[n] - 1), default_random_engine(seed));
            //RBTree t;
            bst t;
            for (i = 0; i < a[n]; i++)
            {
                t.insert(*(data + i));
            }
            //t.printInOrder();
            t.countredn();
            red += t.redn;
            if (n == 2 && m % 10 == 0) //just for tracking the process of the last set
            {
                cout << "-";
            }
        }
        double percentage = red / (a[n] * 100);
        cout << percentage << endl;
    }
}