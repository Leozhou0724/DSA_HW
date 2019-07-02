#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
class Node
{
  public:
    Node(int id, float weight)
        : id(id), weight(weight)
    {
        this->next = NULL;
    }
    int id;
    float weight;
    Node *next;
};
class Linkedlist
{
  public:
    Node *head;
    Node *tail;
    int size;
    Linkedlist()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    ~Linkedlist()
    {
        delete head;
    }
    void addtoend(Node *ptr)
    {
        if (head == NULL)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            tail = ptr;
        }
        size++;
    }
};
#endif