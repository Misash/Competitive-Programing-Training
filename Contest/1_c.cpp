//
// Created by misash on 19/11/22.
//

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;


void dfs(int crr, int pre)
{
    cout<<crr<<" ";
    for(int nxt:G[crr])
    {
        if(nxt != pre)
        {
            dfs(nxt,crr);
            cout<<crr<<" ";
        }
    }
}
int main()
{
    cin >> n;
    G.resize(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
        sort(G[i].begin(), G[i].end());


    dfs(1, -1);

    return 0;
}


