//
// Created by misash on 26/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,ans=0; string s;
    cin>>n>>s;

    for (int i = 0; i <n-1 ; ++i) {
        ans+=(s[i]==s[i+1])? 1:0;
    }

    cout<<ans;

}