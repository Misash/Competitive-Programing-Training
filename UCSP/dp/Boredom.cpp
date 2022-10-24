//
// Created by misash on 24/10/22.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int n;
    ll current,maxI1,maxI2;
    cin>>n;

    vector<ll> dp(100005,0);

    for (int i = 0; i < n ; ++i) {
        cin>>current;
        dp[current]++;
    }

    maxI1 = dp[1]; //index 1
    maxI2 = 0; //index 0

    for (int i = 2; i <= 100005 ; ++i) {
        current = max( maxI1, i * dp[i] + maxI2);
        maxI2 = maxI1;
        maxI1 = current;
    }

    cout<<maxI1;

}
