//
// Created by misash on 26/11/22.
//



#include <bits/stdc++.h>

using namespace std;

#define    clr(v,d)   memset( v, d ,sizeof(v))
int n, Graph[209][209], visited[209], path[209], pathlen;


int dfs(int sr,int des,int len,int capacity)
{
    path[len]=sr;
    if(sr==des)
    {
        pathlen=len+1;
        return capacity;
    }

    visited[sr]=1;
    int min_cap=0;

    for(int i=1;i<=n;i++)
    {
        if(visited[i] || Graph[sr][i] <= 0)
            continue;
        min_cap=dfs(i, des, len + 1, min(capacity, Graph[sr][i]));
        if(min_cap > 0)
            return min_cap;
    }
    return min_cap;
}

int FordFulkerson()
{
    int flows=0;
    while(1)
    {
        clr(visited, 0);
        int fl=dfs(1,n,0,INT_MAX);
        if(!fl)
            break;
        cout<<"\n flow: "<<fl;
        cout<<"\n";
        for(int i=1;i<pathlen;i++)
        {
            cout<<path[i]<<" -> ";
            int fr=path[i-1];
            int to=path[i];
            Graph[fr][to]-=fl;
            Graph[to][fr]+=fl;
        }
        flows+=fl;
    }
    cout<<"\n";
    return flows;
}

int main()
{

    int T;
    cin>>T;

    while(T--)
    {

        cin>>n;
        int no,num;
        clr(Graph, 0);
        for(int i=1;i<=n-1;i++)
        {
            cin>>no;
            for(int j=0;j<no;j++)
            {
                cin>>num;
                if(i==1)
                    Graph[i][num]=1;
                else if(num==n)
                    Graph[i][num]=1;
                else
                    Graph[i][num]=INT_MAX;
            }
        }
        cout << FordFulkerson() << endl;
    }
}
