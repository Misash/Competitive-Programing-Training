//
// Created by misash on 10/11/22.
//


#include <bits/stdc++.h>

using namespace std;

template<class T>
struct Graph {
    map<T, bool> visited;
    map<T, list<T> > adj;
    map<T, list<T> > adjReverse;
    stack<T> FinishTime;
    bool pila = true;

    void addEdge(T v, T w){
        adj[v].push_back(w);
        adjReverse[w].push_back(v);
    }

    void DFS(T v){
        visited[v] = true;
        cout << v << " ";

        for ( auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFS(*i);

        if(pila) FinishTime.push(v);
    }



    void kosaraju(){

        //Fill Finish Time stack
        cout<<"\nNodes: \n";
        for (auto it = adj.begin(); it != adj.end() ; ++it) {
            if(!visited[it->first]){
                DFS(it->first);
            }
        }

        //find scc from reverse graph
        visited.clear();adj = adjReverse;pila = false;
        cout<<"\n\nStrongly Connected Components: \n";
        while(!FinishTime.empty()){
            if(!visited[FinishTime.top()]){
                DFS(FinishTime.top());
                cout<<"\n";
            }
            FinishTime.pop();
        }

    }

};


int main(){


    Graph<char> g;



    g.addEdge('a','b');
    g.addEdge('b','e');
    g.addEdge('b','f');
    g.addEdge('b','c');
    g.addEdge('c','g');
    g.addEdge('c','d');
    g.addEdge('d','c');
    g.addEdge('d','h');
    g.addEdge('h','d');
    g.addEdge('h','g');
    g.addEdge('e','a');
    g.addEdge('e','f');
    g.addEdge('f','g');
    g.addEdge('g','f');

    g.kosaraju();


}

//    g.addEdge('A','B');
//    g.addEdge('B','C');
//    g.addEdge('B','D');
//    g.addEdge('C','A');
//    g.addEdge('D','E');
//    g.addEdge('E','F');
//    g.addEdge('F','D');
//    g.addEdge('G','F');
//    g.addEdge('G','H');
//    g.addEdge('H','I');
//    g.addEdge('I','J');
//    g.addEdge('J','K');
//    g.addEdge('J','G');