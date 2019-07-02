/*
DSA HW4 Q6
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
#include <limits.h>
using namespace std;
struct node
{
    int id;
    float weight;
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
    void addEdge(int v, int w, float weight)
    {
        node *tmp1;
        tmp1 = new node;
        tmp1->id = w;
        tmp1->weight = weight;
        adj[v].push_back(*tmp1);
        /*
        node *tmp2;
        tmp2 = new node;
        tmp2->id = v;
        tmp2->weight = weight;
        adj[w].push_back(*tmp2);
        */
    }
    void Dijkstra()
    {
        float dist[V];
        bool visited[V];
        for (int i = 0; i < V; i++)
        {
            dist[i] = INT_MAX;
            visited[i] = false;
        }
        dist[0] = 0; //vertex 0 as the source
        Linkedlist::iterator iter;
        for (int i = 0; i < V ; i++)
        {
            float min = INT_MAX;
            int min_idx;
            for (int j = 0; j < V; j++)
            {
                if (visited[j] == false && dist[j] <= min)
                {
                    min = dist[j];
                    min_idx = j;
                }
            }
            visited[min_idx] = true;

            for (iter = adj[min_idx].begin(); iter != adj[min_idx].end(); ++iter)
            {
                if (/*visited[iter->id] == false &&*/ dist[min_idx] != INT_MAX && dist[min_idx] + iter->weight < dist[iter->id] && dist[min_idx] + iter->weight>=0)
                {
                    dist[iter->id] = dist[min_idx] + iter->weight;
                    cout << min_idx << " - " << iter->id << endl;
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            cout << "dist to vertex " << i << " : " << dist[i] << endl;
        }
    }
};
int main()
{
    int V, E;
    int v, w;
    float weight;
    string filename = "data_4b.txt";	//change the filename to try another dataset
    ifstream file(filename, ios::in);
    file >> V;
    file >> E;
    Graph g(V);
    while (file >> v >> w >> weight) //load data
    {
        g.addEdge(v, w, weight);
    }
    g.Dijkstra();
}