/*
DSA HW3 Q2
Yuhang Zhou
yz853
4/2/2019
*/
#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left = NULL;
    node *right = NULL;
    node *parent = NULL;
};

class tree
{
  public:
    tree()
    {
        root = NULL;
        treesize = 0;
    }
    ~tree()
    {
        delete root;
    }
    void put(int key)
    {
        node *nnode = new node; //create a new node
        nnode->key = key;
        //cout << nnode << endl;
        if (root == NULL) //empty tree
        {
            root = nnode;
        }
        else
        {
            node *ptr = root;
            while (ptr) //find
            {
                if (nnode->key < ptr->key)
                {
                    if (ptr->left)
                    {
                        ptr = ptr->left;
                    }
                    else
                    {
                        ptr->left = nnode;
                        nnode->parent = ptr;
                        break;
                    }
                }
                else
                {
                    if (ptr->right)
                    {
                        ptr = ptr->right;
                    }
                    else
                    {
                        ptr->right = nnode;
                        nnode->parent = ptr;
                        break;
                    }
                }
            }
        }
        treesize++;
    }

    int size()
    {
        return treesize;
    }
    int length(int key)
    {
        int n = 0;
        if (treesize == 0)
        {
            return n;
        }
        else
        {
            node *ptr = root;
            while (ptr) //find
            {
                if (key == ptr->key)
                {
                    return n;
                    break;
                }
                else if (key < ptr->key)
                {

                    ptr = ptr->left;
                    n++;
                }
                else
                {

                    ptr = ptr->right;
                    n++;
                }
            }
        }
    }

    //private:
    node *root;
    int treesize;
};

int main()
{
    const int n = 10000; //number of insertions
    tree t1;
    tree t2;
    int i;
    int rnd[n]; //random insertions
    for (i = 0; i < n; i++)
    {
        rnd[i] = rand();
        t1.put(rnd[i]);
    }
    for (i = 0; i < n; i++) //sorted insertions
    {
        t2.put(i);
    }

    double l1 = 0; //total length
    double l2 = 0;
    for (i = 0; i < n; i++)
    {
        l1 += t1.length(rnd[i]);
    }
    cout << l1 / t1.size() << endl;
    for (i = 0; i < n; i++)
    {
        l2 += t2.length(i);
    }
    cout << l2 / t2.size() << endl;
}