//
// Created by misash on 28/07/21.
//

#include <bits/stdc++.h>

using namespace std;


int h[100] ;
int g[100] ;


int main(){

    int n,x,y,ans=0;

    cin>>n;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin>>x>>y;
        h[x-1]++;
        g[y-1]++;
    }

    for (int i = 0; i <100 ; ++i) {
        ans+=h[i]*g[i];
    }

    cout<<ans;

}