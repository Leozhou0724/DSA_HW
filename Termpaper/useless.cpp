#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void BADCHAR(string find, int badchar[], int m)
{
    for (int i = 0; i < 256; i++)
    {
        badchar[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        badchar[int(find[i])] = i;
    }
}
int main()
{
    string a = "aABA";
    int n = a.length();
    int badchar[256];
    BADCHAR(a, badchar, n);
    for (int i = 0; i < sizeof(badchar) / sizeof(badchar[0]); i++)
    {
        cout << i << ":" << badchar[i] << endl;
    }
}