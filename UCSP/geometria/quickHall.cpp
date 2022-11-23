//
// Created by misash on 23/11/22.
//

#include<bits/stdc++.h>
using namespace std;

#define Punto pair<int, int>

set<Punto> hull;


enum  { CO_LINEAR = 0, LEFT = 1 , RIGHT = -1};

// posicion de p respecto a linea p1-p2
int findSide(Punto p1, Punto p2, Punto p)
{
    int val = (p.second - p1.second) * (p2.first - p1.first) -
              (p2.second - p1.second) * (p.first - p1.first);

    if (val > 0)
        return LEFT;
    if (val < 0)
        return RIGHT;
    return CO_LINEAR;
}


// distancia de p a la linea p1-p2
int lineDist(Punto p1, Punto p2, Punto p)
{
    return abs ((p.second - p1.second) * (p2.first - p1.first) -
                (p2.second - p1.second) * (p.first - p1.first));
}


void quickHull(Punto a[], int n, Punto p1, Punto p2, int side)
{
    int ind = -1;
    int max_dist = 0;

    //punto con maxima distancia
    for (int i=0; i<n; i++)
    {
        int temp = lineDist(p1, p2, a[i]);
        if (findSide(p1, p2, a[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    // Sin puntos -> añadir a hull
    if (ind == -1)
    {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    // recorrer las parted divididas por  a[ind]
    quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
    quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}




int main()
{
    Punto a[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                 {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    int n = sizeof(a)/sizeof(a[0]);

    if (n < 3){cout << "Convex hull not possible\n";return 0;}

    // encontrar minima y maxima coordenada
    int min_x = 0, max_x = 0;
    for (int i=1; i<n; i++)
    {
        if (a[i].first < a[min_x].first)
            min_x = i;
        if (a[i].first > a[max_x].first)
            max_x = i;
    }

    cout<<"\nmin_coordenada : ("<<a[min_x].first<<" , "<<a[min_x].second<<") ";
    cout<<"\nmax_coordenada : ("<<a[max_x].first<<" , "<<a[max_x].second<<") "<<endl;


    //divide y vencerás
    quickHull(a, n, a[min_x], a[max_x], 1);
    quickHull(a, n, a[min_x], a[max_x], -1);

    cout << "Puntos de poligono convexo son :\n";
    while (!hull.empty())
    {
        cout << "(" <<( *hull.begin()).first << ", "
             << (*hull.begin()).second << ") ";
        hull.erase(hull.begin());
    }


}
