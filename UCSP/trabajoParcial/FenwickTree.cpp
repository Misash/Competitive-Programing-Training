#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> a(900000), t(9000000);

void update(int ind, int val) {
    while (ind <= n) {
        t[ind] += val;
        ind += (ind & -ind);
    }
}
int query(int ind) {
    int s = 0;
    while (ind > 0) {
        s += t[ind];
        ind -= (ind & -ind);
    }
    return s;
}

void solve() {
    int q;
    cin >> n >> q;
    for (int k = 1; k <= n; k++) {
        cin >> a[k];
        update(k, a[k]);
    }
    int in, l, r;
    for (int k = 1; k <= q; k++) {
        cin >> in >> l >> r;
        l++;
        if (in == 0)
            update(l, r);
        else
            cout << query(r) - query(l - 1) << '\n';
    }
}

int32_t main() {
    solve();
    return 0;
}



#include <bits/stdc++.h>
using namespace std;


class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to Graph’s list.
}

void Graph::DFS(int v)
{

    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

// Driver's code
int main()
{

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";


    g.DFS(2);

    return 0;
}

// improved by Vishnudev C


















