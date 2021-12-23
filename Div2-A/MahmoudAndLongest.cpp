//
// Created by misash on 10/09/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    string a,b;
    cin>>a>>b;

    int la=max(a.size(),b.size());

    cout<<( (a == b)? -1:la );

}