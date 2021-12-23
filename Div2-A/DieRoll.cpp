//
// Created by misash on 28/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    int y,w,mx;

    cin>>y>>w;

    mx=max(y,w);

    int d=6;
    int n=d-mx+1;
    int gcd = __gcd(d,n);

    d/=gcd;
    n/=gcd;

    cout<<n<<"/"<<d;

}