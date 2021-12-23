//
// Created by misash on 26/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,ans,bef=0,now;
    cin>>n;
    ans=n;

    for (int i = 0; i < n; ++i) {
        cin>>now;
        ans-=(bef==now)? 1:0;
        bef=now;
    }

    cout<<ans;


}