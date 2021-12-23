//
// Created by misash on 28/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

   int n,b,d,a,sum=0,ans=0;

   cin>>n>>b>>d;

    for (int i = 0; i < n; ++i) {
        cin>>a;
        if(a<=b){
            sum+=a;
        }
        if(sum > d){
            sum=0;
            ans++;
        }
    }

    cout<<ans;



}