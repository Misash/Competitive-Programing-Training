//
// Created by misash on 27/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0),cin.tie(0);

    int x,ans=0,arr[4];
    string s;

    for (int & i : arr) {
        cin>>i;
    }

    cin.ignore();
    getline(cin,s);

    for(char i:s){
        ans+= arr[i-'0'-1];
    }

    cout<<ans;

}