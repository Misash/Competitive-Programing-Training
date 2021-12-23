//
// Created by misash on 23/07/21.
//

#include <bits/stdc++.h>

using namespace std;


int main(){

    int n=5,t=1;
    cin>>n>>t;

    string s (n,' ');
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }


    while(t--){
        for (int i = 0; i < n-1; ++i) {
            if(s[i+1]-s[i] == 5){
                swap(s[i+1],s[i]);i++;
            }
        }
    }

    cout<<s;

};