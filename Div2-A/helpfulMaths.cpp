//
// Created by misash on 29/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    getline(cin,s);
    vector<char> vec;
    for( char i:s){
      if(i != '+') vec.push_back(i);
    }

    sort(vec.begin(),vec.end());

    cout<<vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        cout<<"+"<<vec[i];
    }

}