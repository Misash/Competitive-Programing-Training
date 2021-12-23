//
// Created by misash on 28/07/21.
//

#include <bits/stdc++.h>

using namespace std;


int main(){

    int n,t,k,d;

    cin>>n>>t>>k>>d;

    int o1=0,o2=d,g=(n+k-1)/k;
    for (int i = 0; i < g; ++i) {
        if(o1 <= o2) o1+=t;
        else o2+=t;
    }

    cout<<((max(o1,o2) < g*t)? "YES":"NO");

}