/*
DSA HW4 Q2
Yuhang Zhou
yz853

reference:Dijkstra's algorithm From Wikipedia, the free encyclopedia
          https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <queue>
using namespace std;

struct vertex_dis
{
    int vertex;
    float dist;
    friend bool operator>(const vertex_dis &a, const vertex_dis &b)
    {
        return (a.dist> b.dist);
    }
    friend bool operator<(const vertex_dis &a, const vertex_dis &b)
    {
        return (a.dist < b.dist);
    }
};
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
    }
    void Dijkstra()
    {
        float dist[V];
        for (int i = 0; i < V; i++)
        {
            dist[i] = INT_MAX;
        }
        dist[0] = 0; //vertex 0 as the source
        priority_queue<vertex_dis, vector<vertex_dis>, greater<vertex_dis>> pq;
        vertex_dis *ptr;
        vertex_dis *push;
        ptr = new vertex_dis;
        ptr->dist = 0;
        ptr->vertex = 0;
        pq.push(*ptr);
        Linkedlist::iterator i;
        int n = 0;
        while(!pq.empty())
        {
            *ptr = pq.top();
            pq.pop();
            cout << "pop vertex " << ptr->vertex << ", dist = " << ptr->dist << endl;
            if(dist[ptr->vertex]!=ptr->dist)
            {
                continue;
            }
            for(i = adj[ptr->vertex].begin(); i != adj[ptr->vertex].end(); ++i)
            {
                if(dist[ptr->vertex]+i->weight<dist[i->id])
                {
                    dist[i->id] = dist[ptr->vertex] + i->weight;
                    push = new vertex_dis;
                    push->vertex = i->id;
                    push->dist = dist[i->id];
                    pq.push(*push);
                    cout << "push vertex " << push->vertex << ", dist = " << push->dist << endl;
                }
            }
            n++;
            if(n>100)
            {
                break;
            }
        }
        cout << "result: " << endl;
        for (int j = 0; j < V;j++)
        {
            cout << "dist to vertex " << j << " : " << dist[j] << endl;
        }
    }
};
int main()
{
    int V, E;
    int v, w;
    float weight;
    string filename = "data_4a.txt";
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