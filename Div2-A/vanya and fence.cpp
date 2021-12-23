//
// Created by misash on 26/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,h,ans=0,x;
    cin>>n>>h;

    for (int i = 0; i < n; ++i) {
        cin>>x;
        ans+=(x>h)? 2:1;
    }

    cout<<ans;


}