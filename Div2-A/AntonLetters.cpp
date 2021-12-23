//
// Created by misash on 29/07/21.
//

#include <bits/stdc++.h>


using namespace std;

int main(){

    string s;
    getline(cin,s);

    set<char> let;

    for( char i:s){
        if(96<i && i<123) let.insert(i);
    }

    cout<<let.size();


}