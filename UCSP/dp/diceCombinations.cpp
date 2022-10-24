//
// Created by misash on 22/10/22.
//


#include <bits/stdc++.h>


using namespace std;
#define ll  long long

ll n;
ll mod = 1000000007;

int main(){

    cin>>n;
    vector<ll> dp(n+1,0);
    dp[0] = 1;

    for (ll idx = 1; idx <= n; ++idx) {
        for (ll x = 1; x <= 6 && x <= idx  ; ++x) {
            dp[idx] =  (dp[idx] + dp[idx - x]) % mod;
        }
    }


    cout<<dp[n] ;

}