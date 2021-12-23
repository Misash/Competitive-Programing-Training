//
// Created by misash on 28/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    string s,t;

    getline(cin,s);
    getline(cin,t);

    int pos=0;
    for( char i : t){
        if( i == s[pos%s.size()]){
            pos++;
        }
    }
    cout<<pos+1;

}