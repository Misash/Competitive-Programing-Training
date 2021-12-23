//
// Created by misash on 23/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,x,y,z,xs=0,ys=0,zs=0;

    cin>>n;

    for (int i = 0; i < n; ++i) {
        cin>>x>>y>>z;
       xs+=x; ys+=y; zs+=z;
    }

    if(xs==0 && ys==0 && zs==0 ) cout<<"YES";
    else cout<<"NO";




}