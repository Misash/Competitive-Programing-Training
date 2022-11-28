//
// Created by misash on 26/11/22.
//

#include <bits/stdc++.h>

using namespace std;


int bfs(int source, int sink, vector<int>& parent, vector<vector<int>>& residualGraph) {
    fill(parent.begin(), parent.end(), -1);
    int V = residualGraph.size();
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

    while (!q.empty()) {
        cout<<"\n"<<q.front().first+1;
        int u = q.front().first;
        int capacity = q.front().second;
        q.pop();
        for (int av=0; av < V; av++) {
            if (u != av && parent[av] == -1 && residualGraph[u][av] != 0) {
                parent[av] = u;
                int min_cap = min(capacity, residualGraph[u][av]);
                if (av == sink)
                    return min_cap;
                q.push({av, min_cap});
            }
        }
    }
    return 0;
}

int ford_fulkerson(vector<vector<int>>& graph, int source, int sink) {
    vector<int> parent(graph.size(), -1);
    vector<vector<int>> residualGraph = graph;
    int min_cap = 0, max_flow = 0;
    while (min_cap = bfs(source, sink, parent, residualGraph)) {
        max_flow += min_cap;
        int u = sink;
        cout<<"\n";
        while (u != source) {
            int v = parent[u];
            cout<<v+1<<" -> "<<u+1<<" ";
            residualGraph[u][v] += min_cap;
            residualGraph[v][u] -= min_cap;
            u = v;
        }
    }
    cout<<"\n";
    return max_flow;
}

void addEdge(vector<vector<int>>& graph,
             int u, int v, int w)
{
    graph[u][v] = w;
}

int main()
{

    int T,n;
    cin>>T;

    while(T--)
    {

        cin>>n;
        vector<vector<int>> graph(n, vector<int> (n, 0));

        int no,num;

        for(int i=0;i<n-1;i++)
        {
            cin>>no;
            for(int j=0;j<no;j++)
            {
                cin>>num;
                num--;
                if(i==0)
                    addEdge(graph, i, num, 1);
                else if(num==n-1)
                    addEdge(graph, i, num, 1);
                else
                    addEdge(graph, i, num, INT_MAX);
            }
        }
        cout << ford_fulkerson(graph, 0, n-1) << endl;
    }
}