//
// Created by misash on 27/07/21.
//

#include <bits/stdc++.h>

using namespace std;


int main(){
    int ans=0,x='a';
    string s;
    getline(cin,s);

    for( char y:s)
        ans+= min(abs(x-y),26-abs(x-y)),x=y;

    cout<<ans;

}