//
// Created by misash on 29/10/22.
//
#include <bits/stdc++.h>

using namespace std;

#define MAX 10000000

deque<int> depth(10000000,MAX);
int nums[1000];
int n,x;


inline int dp(int total){
    if(!total ) return 0;

    if(depth[total] != MAX ) return depth[total];

    for (int i = 0; i < n; ++i) {
        if( total >= nums[i])
            depth[total] = min(depth[total], dp(total - nums[i]) );
    }
    return ++depth[total];
}

int main() {


    cin>>n>>x;

    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }

    int res = dp(x);
    if( res >= MAX){
        cout<<-1;
    }else{
        cout<<res;
    }
}

