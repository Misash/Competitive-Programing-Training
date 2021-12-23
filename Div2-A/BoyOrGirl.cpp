//
// Created by misash on 26/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    set<string> set1;
    string s;

    cin>>s;

    for (char i : s) {
        set1.insert(to_string(i));
    }

    cout<<((set1.size()%2)? "IGNORE HIM!":"CHAT WITH HER!");

}