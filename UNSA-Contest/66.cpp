//
// Created by misash on 11/11/21.
//

#include <bits/stdc++.h>

using namespace  std;

#define ll long long


int main(){

    ll t;

    cin>>t;

    while(t--){

        ll n;
        cin>>n;
        ll prices[n];

        for (int i = 0; i < n; ++i) {
            cin>>prices[i];
        }

        ll p = 0 ,max = 0;

        for (ll i = n-1 ; i >= 0 ; i--) {
            if (prices[i] >= max) {
                max = prices[i];
            }
            p += max- prices[i];
        }

        cout<<p<<endl;
    }


}