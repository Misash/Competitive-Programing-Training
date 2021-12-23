//
// Created by misash on 26/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    string s1,s2;
    cin>>s1>>s2;

    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    transform(s2.begin(),s2.end(),s2.begin(),::tolower);

    cout<<((s1<s2)? -1:(s2<s1)? 1:0);

}
