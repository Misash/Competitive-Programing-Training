//
// Created by misash on 28/08/22.
//

#include <bits/stdc++.h>

using namespace std;


struct Graph{

    map<int, bool> visited;
    map<int, list<int> > adj;

    void addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool isCyclic(int v,int parent,int &nodes){

        visited[v] = true;

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i){
            if (!visited[*i]){
                nodes++;
                if(isCyclic(*i,v,nodes))
                    return true;
            }else if(*i != parent){
                return true;
            }
        }

        nodes = 0;
        return false;
    }

};



int main(){

    cin.tie(0); ios_base::sync_with_stdio(0);

    int n,m,x,y;
    cin>>n>>m;

    Graph g;
    while(m--){
        cin>>x>>y;
        g.addEdge(x,y);
    }

    int remove=0;

    for (int i = 1; i <= n; ++i) {
        int nodes = 1;
        if(!g.visited[i])
            if(g.isCyclic(i,-1,nodes))
                remove +=(nodes % 2 == 1);
    }

    if((n - remove)%2 == 1)
        remove++;

    cout<<remove;


}