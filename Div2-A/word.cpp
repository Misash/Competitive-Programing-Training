//
// Created by misash on 26/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    int up=0;
    getline(cin,s);

    for (char i : s) {
        if(i<91) up++;
    }

    transform(s.begin(),s.end(),s.begin(),((2*up>s.size())? ::toupper: ::tolower));

    cout<<s;

}