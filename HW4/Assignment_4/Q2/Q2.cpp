/*
DSA HW4 Q2
Yuhang Zhou
yz853

reference:GeeksForGeeks Prim’s Minimum Spanning Tree (MST) | Greedy Algo-5
          https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
*/
#include <iostream>
#include <fstream>
#include <string>
#include "linkedlist.h"
#include <queue>
#include <time.h>
#include <limits.h>
using namespace std;

class Graph
{
  public:
    int V;
    Linkedlist *adj;

    Graph(int v)
    {
        V = v;
        adj = new Linkedlist[V];
    }
    void addEdge(int v, int w, float weight)
    {
        Node *node;
        node = new Node(w, weight);
        adj[v].addtoend(node); //undirected graph, two vertices should be added to each other's adj list
        node = new Node(v, weight);
        adj[w].addtoend(node);
    }
    void prim_mst()
    {
        int parent[V];
        int cut[V];
        bool mst[V];
        for (int i = 0; i < V; i++)
        {
            cut[i] = INT_MAX;
            mst[i] = false;
        }
        cut[0] = 0; //add vertex to the cut in the first
        parent[0] = -1;
        for (int i = 0; i < V - 1; i++)
        {
            int min = INT_MAX;
            int min_idx;
            for (int j = 0; j < V; j++)
            {
                if (cut[j] < min && mst[j] == false)
                {
                    min = cut[j];
                    min_idx = j;
                }
            }
            mst[min_idx] = true; //add the smallest one of the cut to the mst

            Node *ptr;
            for (ptr = adj[min_idx].head; ptr != NULL; ptr = ptr->next)
            {
                if (mst[ptr->id] == false && ptr->weight < cut[ptr->id])
                {
                    parent[ptr->id] = min_idx;
                    cut[ptr->id] = ptr->weight;
                }
            }
        }
        /*
        float total_weight = 0;
        for (int i = 1; i < V;i++)
        {
            cout << parent[i] << " - " << i << endl;
            Node *ptr;
            for (ptr = adj[i].head; ptr != NULL; ptr = ptr->next)
            {
                if(ptr->id==parent[i])
                {
                    total_weight += ptr->weight;
                }
            }
        }
        */
        
    }
};

struct edge
{
    int vertex_a;
    int vertex_b;
    float weight;
    friend bool operator>(const edge &a, const edge &b)
    {
        return (a.weight > b.weight);
    }
    friend bool operator<(const edge &a, const edge &b)
    {
        return (a.weight < b.weight);
    }
};
int root(int i, int id[])
{
    while (i != id[i])
    {
        i = id[i];
    }
    return i;
}

bool find(int p, int q, int id[])
{
    return root(p, id) == root(q, id);
}

void Union(int p, int q, int id[])
{
    int i = root(p, id);
    int j = root(q, id);
    id[i] = j;
}
void kruskal_mst(priority_queue<edge, vector<edge>, greater<edge>> pq, int V, int n)
{
    
    int *id = new int[n];
    for (int i = 0; i < n; i++)
    {
        id[i] = i;
    }
    edge *min;
    int count = 0;
    
    while (count<249)
    {
        *min = pq.top();
        while (find(min->vertex_a, min->vertex_b, id))
        {
            pq.pop();
            *min = pq.top();
        }
        Union(min->vertex_a, min->vertex_b, id);
        //cout << min->vertex_a << " - " << min->vertex_b <<": "<<min->weight<< endl;
        cout <<min->weight<< endl;
        count++;
        pq.pop();
    }
    
}
int main()
{
    int V, n;
    int v, w;
    float weight;
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    string filename = "mediumEWG.txt";
    ifstream file(filename, ios::in);
    file >> V;
    file >> n;
    Graph g(V);
    edge *e;
    while (file >> v >> w >> weight) //load data
    {
        g.addEdge(v, w, weight);
        e = new edge;
        e->vertex_a = v;
        e->vertex_b = w;
        e->weight = weight;
        pq.push(*e);
    }
	//run both 2 functions at one time may leads to Memory overflow in my VM
	//you can comment one function and try one by one
    double t1 = clock();
    g.prim_mst();
    double t2 = clock();
    kruskal_mst(pq, V, n);
    double t3 = clock();
    cout << "Run time of prim is " << (double)(t2-t1)  << " ms" << endl;
    cout << "Run time of kruskal is " << (double)(t3-t2)  << " ms" << endl;
}
