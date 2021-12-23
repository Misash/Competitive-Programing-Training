//
// Created by misash on 11/11/21.
//

#include <bits/stdc++.h>

using namespace  std;

#define ll long long

vector<pair <int,int> > adj[50001];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for (int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back(make_pair(b,c)); // Adjacent matrix
        adj[b].push_back(make_pair(a,c));
    }
    int be = 1, ed = 10000002;
    while (be <= ed)
    {
        int mid = (be + ed) / 2;
        // Check connectivity, using BFS
        int q[50001], visited[50001];
        int qbe = 0, qed = 1;
        q[0] = 1;
        memset(visited,0,sizeof(visited));
        visited[1] = 1;
        while (qbe < qed)
        {
            int len = adj[q[qbe]].size();
            for (int i=0; i<len; i++)
            {
                if (visited[adj[q[qbe]][i].first] == 0 && adj[q[qbe]][i].second <= mid)
                {
                    q[qed++] = adj[q[qbe]][i].first;
                    visited[adj[q[qbe]][i].first] = 1;
                }
            }
            qbe++;
        }
        if (visited[n] == 1)
            ed = mid-1;
        else
            be = mid+1;
    }
    if (be > 10000000)
        printf("NO PATH EXISTS\n");
    else
        printf("%d\n",be);

}