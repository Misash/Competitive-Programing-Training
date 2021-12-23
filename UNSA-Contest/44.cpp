//
// Created by misash on 11/11/21.
//

#include <bits/stdc++.h>

using namespace  std;


int main(){

    int n,k=0;
    string s;

    cin>>n;
    cin>>s;

    if(s.size() < 3){ cout<<0  ; return 0;}

    for (int i = 0; i < (n-2); ++i) {
            if(s[i] == '0' && s[i+1] == '1' && s[i+2] == '0'){
                s[i+2] = '1';
                k++;
            }
    }

    cout<<k;


}