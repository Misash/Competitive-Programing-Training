#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Graph.cpp"

using namespace std;

int main()
{

    int start, stop, source;

    int V = 5;
    Graph g(V);
//    g.addEdge(0, 1, 4);
//    g.addEdge(0, 7, 8);
//    g.addEdge(1, 2, 8);
//    g.addEdge(1, 7, 11);
//    g.addEdge(2, 3, 7);
//    g.addEdge(2, 8, 2);
//    g.addEdge(2, 5, 4);
//    g.addEdge(3, 4, 9);
//    g.addEdge(3, 5, 14);
//    g.addEdge(4, 5, 10);
//    g.addEdge(5, 6, 2);
//    g.addEdge(6, 7, 1);
//    g.addEdge(6, 8, 6);
//    g.addEdge(7, 8, 7);

//    a b c d e
//    0 1 2 3 4
//    g.addEdge(0,1,6);
//    g.addEdge(0,3,1);
//    g.addEdge(1,3,2);
//    g.addEdge(1,4,2);
//    g.addEdge(1,2,5);
//    g.addEdge(2,4,5);
//    g.addEdge(3,4,1);

    g.addEdge('a','b',6);
    g.addEdge('a','d',1);
    g.addEdge('b','d',2);
    g.addEdge('b','e',2);
    g.addEdge('b','c',5);
    g.addEdge('c','e',5);
    g.addEdge('d','e',1);

    source = 'a';

    cout << "-----CLASSIC-----" << endl;
    start = clock();
    g.Dijkstra( source);
    stop = clock();
    cout << "Tiempo usando Dijsktra classic : " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;


    cout << "\n-----PRIORITY QUEQUE-----" << endl;
    start = clock();
    g.shortestPath(source, PRIORITY_QUEUE);
    stop = clock();
    cout << "Tiempo usando priority queue: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;

    cout << "\n-----FIBONACCI HEAPS-----" << endl;
    start = clock();
    g.shortestPath(source, FIBONACCI);
    stop = clock();
    cout << "Tiempo usando fibonacci : " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;

    return 0;
}
