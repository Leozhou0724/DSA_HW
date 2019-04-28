/*
DSA HW3 Q5
Yuhang Zhou
yz853
4/2/2019

reference:
Binary Search Trees https://algs4.cs.princeton.edu/32bst/
*/
#include <iostream>
#include <fstream>
#include <string>
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
                    else if (nnode->key == ptr->key)
                    {
                        break;
                    }
                    else
                    {
                        ptr->left = nnode;
                        nnode->parent = ptr;
                        break;
                    }
                }
                else if (nnode->key == ptr->key)
                {
                    break;
                }
                else
                {
                    if (ptr->right)
                    {
                        ptr = ptr->right;
                    }
                    else if (nnode->key == ptr->key)
                    {
                        break;
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

    void traverse(node *ptr)
    {
        if (ptr == NULL)
        {
            return;
        }
        n++;

        traverse(ptr->left);
        traverse(ptr->right);
    }

    int numberofnodes(node *ptr)
    {
        n = 0;
        traverse(ptr);
        return n;
    }

    int rankbynode(int key, node *ptr)
    {
        if (ptr == NULL)
        {
            return 0;
        }
        else
        {
            if (key < ptr->key)
            {
                return rankbynode(key, ptr->left);
            }
            else if (key == ptr->key)
            {
                return numberofnodes(ptr->left);
            }
            else
            {
                return 1 + numberofnodes(ptr->left) + rankbynode(key, ptr->right);
            }
        }
    }

    int rank(int key)
    {
        node *ptr = root;
        return rankbynode(key, ptr);
    }

    int selectbynode(int ranknumber, node *ptr)
    {
        if (ptr == NULL)
        {
            return 0;
        }
        else
        {
            int leftnodes = numberofnodes(ptr->left);
            if (leftnodes == ranknumber)
            {
                return ptr->key;
            }
            else if (leftnodes < ranknumber)
            {
                selectbynode(ranknumber - leftnodes - 1, ptr->right);
            }
            else
            {
                selectbynode(ranknumber, ptr->left);
            }
        }
    }

    int select(int ranknumber)
    {
        node *ptr = root;
        return selectbynode(ranknumber, ptr);
    }
    //private:
    node *root;
    int treesize;
    int n;
};

int main()
{
    int *data = new int[1000000];
    int m;
    int i = 0;
    string filename = "select-data.txt";
    tree t;
    ifstream file(filename, ios::in);
    while (file >> m)
    {
        *(data + i) = m;
        i++;
    }
    for (i = 0; i < 1000000; i++)
    {
        t.put(*(data + i));
    }
    cout << "rank(7)=" << t.rank(7) << endl;
    cout << "select(7)=" << t.select(7) << endl;
}