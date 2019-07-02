/*
DSA HW4 Q1
Yuhang Zhou
yz853

Reference: GeeksForGeeks Detect cycle in an undirected graph
           https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
*/
#include <iostream>
#include <fstream>
#include <string>
#include "linkedlist.h"
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
    bool DFS(int v, int u, bool visited[])
    {
        //cout << v << "," << u << endl;
        visited[v] = true;      
        Node *ptr;
        for (ptr = adj[v].head; ptr != NULL; ptr = ptr->next)
        {
            if (!visited[ptr->id])      //ignore the checked vertex
            {
                if (DFS(ptr->id, v, visited))
                {
                    return true;
                }
            }
            else if (ptr->id != u)      //prevent going back
            {
                return true;
            }
        }
        return false;
    }
    bool cyclic()
    {
        bool visited[V];        //the array to store whether this vertex is already marked
        for (int i = 0; i < V; i++)     //initial the visted[]
        {
            visited[i] = false;
        }
        for (int i = 0; i < V; i++)     //DFS every vertex
        {
            if (!visited[i])
            {
                if (DFS(i, -1, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int V, n;
    int v, w;
    float weight;
    string filename = "mediumEWG.txt";
    ifstream file(filename, ios::in);
    file >> V;
    file >> n;
    Graph g(V);
    while (file >> v >> w >> weight)    //load data
    {
        g.addEdge(v, w, weight);
    }
	if(g.cyclic())
	{
		cout<<"this graph is cyclic."<<endl;
	}
	else
	{
		cout<<"this graph is acyclic"<<endl;
	}
    //cout << g.cyclic() << endl;
}
