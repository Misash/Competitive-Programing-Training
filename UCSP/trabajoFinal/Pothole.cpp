//
// Created by misash on 26/11/22.
//

#include <bits/stdc++.h>

using namespace std;

#define    clr(v,d)   memset( v, d ,sizeof(v))
int n,v[209][209],vis[209],path[209],pathlen;


int dfs(int sr,int des,int len,int mi)
{
    path[len]=sr;
    if(sr==des)
    {
        pathlen=len+1;
        return mi;
    }
    vis[sr]=1;
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]||v[sr][i]<=0)
            continue;
        ret=dfs(i,des,len+1,min(mi,v[sr][i]));
        if(ret>0)
            return ret;
    }
    return ret;
}

int FordFulkerson()
{
    int flows=0;
    while(1)
    {
        clr(vis,0);
        int fl=dfs(1,n,0,INT_MAX);
        if(!fl)
            break;
        for(int i=1;i<pathlen;i++)
        {
            int fr=path[i-1]; int to=path[i];
            v[fr][to]-=fl;
            v[to][fr]+=fl;
        }
        flows+=fl;
    }
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
        clr(v,0);
        for(int i=1;i<=n-1;i++)
        {
            cin>>no;
            for(int j=0;j<no;j++)
            {
                cin>>num;
                if(i==1)
                    v[i][num]=1;
                else if(num==n)
                    v[i][num]=1;
                else
                    v[i][num]=INT_MAX;
            }
        }

        cout << FordFulkerson() << endl;
    }
}
