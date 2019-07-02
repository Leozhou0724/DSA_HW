#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
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

int main()
{
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    edge *ptr;
    ptr = new edge;
    ptr->weight = 0.001;
    ptr->vertex_a = 8;
    ptr->vertex_b = 9;
    pq.push(*ptr);
    ptr = new edge;
    ptr->weight = 0.0001;
    ptr->vertex_a = 8;
    ptr->vertex_b = 9;
    pq.push(*ptr);
    edge e[3];
    e[0].vertex_a = 1;
    e[0].vertex_b = 2;
    e[0].weight = 0.1;
    e[1].vertex_a = 2;
    e[1].vertex_b = 3;
    e[1].weight = 0.2;
    e[2].vertex_a = 2;
    e[2].vertex_b = 3;
    e[2].weight = 0.01;
    pq.push(e[0]);
    pq.push(e[1]);
    pq.push(e[2]);
    edge min = pq.top();
    cout << min.weight << endl;
    pq.pop();
    min = pq.top();
    cout << min.weight << endl;
}