//
// Created by misash on 11/11/21.
//

#include <bits/stdc++.h>
using namespace  std;
#define ll long long


bool check(string s, string pas){
    for (int i = 0; i <pas.size() ; ++i) {
        for (int j = 0; j < s.size(); ++j) {
            if(pas[i] == s[j]) return 1;
        }
    }
    return 0;
}


int main () {

    string num  =  "0123456789";
    string min  =  "abcdefghijklmnopqrstuvwxyz";
    string may  =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string carac  =  "!@#$%^&*()-+";


    ll n,cumple=0;
    string pas;

    cin>>n;
    cin>>pas;


    if(!check(num,pas)) {cumple++ ; }
    if(!check(min,pas)) {cumple++ ; }
    if(!check(may,pas)) {cumple++ ; }
    if(!check(carac,pas)){cumple++ ; }



    if(pas.size() + cumple < 6){
        cumple += 6 - pas.size() - cumple;
    }

    cout<<cumple;
}