/*
DSA HW3 Q1
Yuhang Zhou
yz853
4/2/2019
*/
#include <iostream>
using namespace std;

struct node
{
    int key;
    double value;
    bool red; //red=1 means a red node, red=0 means a black node
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
    void put(int key, double value)
    {
        node *nnode = new node; //create a new node
        nnode->key = key;
        nnode->value = value;
        nnode->red = 1;
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
                        if (nnode->parent->red == 1) //change color
                        {
                            nnode->red = 0;
                        }
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
                        if (nnode->parent->red == 1) //change color
                        {
                            nnode->red = 0;
                        }
                        break;
                    }
                }
            }
        }
        treesize++;
    }
    double get(int key)
    {
        if (treesize == 0)
        {
            return 0;
        }
        else
        {
            node *ptr = root;
            while (ptr) //find
            {
                if (key == ptr->key)
                {
                    return ptr->value;
                    break;
                }
                else if (key < ptr->key)
                {
                    if (ptr->left)
                    {
                        ptr = ptr->left;
                    }
                    else
                    {
                        return 0;
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
                        return 0;
                        break;
                    }
                }
            }
        }
    }
    void delete1(int key) //can not use "delete" as a function name
    {
        node *ptr = root;
        while (ptr)
        {
            if (ptr->key == key)
            {
                ptr->key = 0;
                ptr->value = 0;
                treesize--;
            }
            else if (key < ptr->key)
            {
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
    }
    bool contains(int key)
    {
        if (treesize == 0)
        {
            return false;
        }
        else
        {
            node *ptr = root;
            while (ptr)
            {
                if (ptr->key == key)
                {
                    return true;
                    break;
                }
                else if (key < ptr->key)
                {
                    if (ptr->left == NULL)
                    {
                        return false;
                        break;
                    }
                    ptr = ptr->left;
                }
                else
                {
                    if (ptr->right == NULL)
                    {
                        return false;
                        break;
                    }
                    ptr = ptr->right;
                }
            }
        }
    }
    bool isEmpty()
    {
        if (treesize == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int size()
    {
        return treesize;
    }
    void traversal(node *ptr)
    {
        if (ptr->key)
        {
            cout << ptr->key << endl;
        }
        if (ptr->left)
        {
            traversal(ptr->left);
        }
        if (ptr->right)
        {
            traversal(ptr->right);
        }
    }
    void iterable()
    {
        if (treesize != 0)
        {
            node *ptr = root;
            traversal(ptr);
        }
    }

  private:
    node *root;
    int treesize;
};

int main()
{
    tree t;
    t.put(1, 5);
    t.put(2, 6);
    t.put(-1, -5);
    t.put(3, 7);
    t.delete1(-1);

    t.iterable(); //print all the keys
    cout << t.size() << endl;
    cout << t.get(3) << endl;
}