//
// Created by misash on 17/09/22.
//

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m,l,r,x;

    cin>>n>>m;
    set<int> alive;
    deque<int> k(n+1,0);

    //insert knights
    for (int i = 1; i <= n; ++i)  alive.insert(i);

    while(m--){
        cin>>l>>r>>x;
        for (auto it = alive.lower_bound(l); *it<=r && it != alive.end()  ; ) {
            if(*it != x){
                k[*it] = x;
                auto kill = it++;
                alive.erase(kill);
            }else{
                it++;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout<<k[i]<<" ";
    }
}


