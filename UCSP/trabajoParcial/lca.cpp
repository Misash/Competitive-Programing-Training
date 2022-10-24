//
// Created by misash on 03/10/22.
//


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


#define PII pair<ll, ll>
vector< vector<int> > g;
bool used[102400];
vector<int> tin, tout;
int timer, n, l;
vector < vector<int> > up;
vector <PII> edges;
map<PII, int> mp;
int cnt[102400];
int ans[102400];


void dfs (int v, int p = 0)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b)
{
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

void find (int v)
{
    ans[v] = cnt[v];
    used[v] = true;

    for(ll i=0; i< g[v].size(); i++)
    {
        int next = g[v][i];
        if (!used[next])
        {
            find(next);
            mp[PII(v, next)] = ans[next];
            mp[PII(next, v)] = ans[next];
            ans[v] += ans[next];
        }
    }
}

int main()
{
    cin >> n;
    g.resize(n);
    for(ll i=0; i<n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        edges.push_back(PII(x, y));
        g[x].push_back(y);
        g[y].push_back(x);
    }

    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs (0);

    int k;
    cin >> k;
    for(ll i=0; i< k; i++)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        int lc = lca(x, y);
        ++cnt[x]; ++cnt[y];
        cnt[lc] -= 2;
    }

    memset(used, 0, sizeof used);
    find(0);
    for(ll i=0; i< n-1; i++)
    {
        if (i)
            cout << " ";
        cout << mp[edges[i]];
    }
    cout << endl;
}
