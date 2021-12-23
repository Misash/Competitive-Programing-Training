//
// Created by misash on 28/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0); cin.tie(0);

    int k,r,ans=0;
    cin>>k>>r;


    do{
        ans++;
    }while((k*ans)%10!=0 && (k*ans)%10!=r);

    cout<<ans;

}