/*
DSA HW4 Q5
Yuhang Zhou
yz853

Reference: GeeksForGeeks Depth First Search or DFS for a Graph
           https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
           GeeksForGeeks Breadth First Search or BFS for a Graph
           https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
struct node
{
    int id;
    int weight;
};
typedef list<node> Linkedlist;
class Graph
{
  public:
    int V;
    Linkedlist *adj;
    Graph(int v)
    {
        this->V = v;
        adj = new Linkedlist[v];
    }
    void addEdge(int v, int w, int weight)
    {
        node *tmp1;
        tmp1 = new node;
        tmp1->id = w;
        tmp1->weight = weight;
        adj[v].push_back(*tmp1);
        node *tmp2;
        tmp2 = new node;
        tmp2->id = v;
        tmp2->weight = weight;
        adj[w].push_back(*tmp2);
    }
    void DFS()
    {
        bool visited[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        int v = 1;
        DFS_rec(v, visited);
    }
    void DFS_rec(int v, bool visited[])
    {
        visited[v] = true;
        //cout << v << endl;
        Linkedlist::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[i->id])
            {
                DFS_rec(i->id, visited);
            }
        }
    }
    void BFS()
    {
        bool visited[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        int v = 1;
        list<int> queue;    //this queue stores vertices which is vistited while its surround vertices not
        queue.push_back(v);
        visited[v] = true;
        Linkedlist::iterator i;
        while(!queue.empty())
        {
            v = queue.front();
            //cout << v << endl;
            queue.pop_front();
            for (i = adj[v].begin(); i != adj[v].end();++i)
            {
                if(!visited[i->id])
                {
                    visited[i->id] = true;
                    queue.push_back(i->id);
                }
            }
        }
    }
};

int main()
{
    int V, E;
    int v, w, weight;
    string filename = "NYC.txt";
    ifstream file(filename, ios::in);
    file >> V;
    file >> E;
    Graph g(V);
    while (file >> v >> w >> weight) //load data
    {
        g.addEdge(v, w, weight);
    }
    g.BFS();
    g.DFS();    //my laptop cannot run all the DFS because of the memory resisctriction
    
}
