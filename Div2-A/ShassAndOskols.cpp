//
// Created by misash on 28/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m,x,y;
    cin>>n;
    int arr[n];

    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }

    cin>>m;

    while(m--){
        cin>>x>>y;
        int r = arr[x-1]-y;
        int l = y-1;

        if(x-1>0) arr[x-2]+=l;
        if(x<n) arr[x]+=r;

        arr[x-1]=0;

    }

    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<"\n";
    }

}