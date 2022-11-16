//
// Created by misash on 16/11/22.
//
#include <bits/stdc++.h>
using namespace std;

#include "FibonacciHeap.cpp"

# define INF 0x3f3f3f3f

enum HeapType {CLASSIC, FIBONACCI ,PRIORITY_QUEUE};


class Graph
{
private:
    int V;
    list< pair<int, int> > *adj;
public:
    map<int , bool> visited;
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s, int heap_type);
    void Dijkstra(int src);
    int minDistance(vector<int> dist);
    int weight(int u,int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int> > [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u-97].push_back(make_pair(v-97, w));
    adj[v-97].push_back(make_pair(u-97, w));
}


int Graph::minDistance(vector<int> dist)
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

int Graph::weight(int u,int v)
{

    for (auto dupla : adj[u]) {
        if(dupla.first == v )
            return dupla.second;
    }

    return 0;
}

void Graph::Dijkstra(int src){
    src -=97;

    vector<int> dist(V, INF);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist);


        visited[u] = true;


        for (int v = 0; v < V; v++){
            int w =  weight(u,v);
            if (!visited[v] && w
                && dist[u] != INF
                && dist[u] + weight(u,v) < dist[v])
                dist[v] = dist[u] + weight(u,v);
        }

    }

    printf("Vertice\tDistancia\n");
    for (int i = 0; i < V; ++i)
        printf("%c \t\t %d\n", i+97, dist[i]);

}

void Graph::shortestPath(int src, int heap_type)
{
    src -=97;
    Heap *heap;

    switch(heap_type)
    {
        case PRIORITY_QUEUE: heap = new PriorityQueue(); break;
        case FIBONACCI: heap = new FibonacciHeap(); break;
    }

    vector<int> dist(V, INF);

    (*heap).push(make_pair(0, src));

    dist[src] = 0;

//    while ((*heap).top() != make_pair(-1, -1))
    while ((*heap).condition())
    {
        int u = (*heap).top().second;
        (*heap).pop();

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                (*heap).push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertice\tDistancia\n");
    for (int i = 0; i < V; ++i)
        printf("%c \t\t %d\n", i+97, dist[i]);


//    printf("Number of Operations performed : %d \n", (*heap).getOperations());
    return;
}

