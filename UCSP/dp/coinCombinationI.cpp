//
// Created by misash on 30/10/22.
//


#include <bits/stdc++.h>

using namespace std;


#define int long long int



signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mod = 1000000007;
    int n,x;

    cin>>n>>x;
    vector<int> nums(n);
    vector<int> dp(x+1,0);

    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }

    dp[0] = 1;
    
    for (int total = 1; total <= x ; ++total) {
        for (int i = 0; i < n ; ++i) {
            if( total >= nums[i])
                dp[total] += dp[total - nums[i]] % mod;
        }
    }

    cout<<dp[x] % mod;

}