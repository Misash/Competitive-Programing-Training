//
// Created by misash on 29/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n,x,d,nop=0;
    cin>>n>>x;

    string s;
    while(n--){
        cin>>s>>d;
        if(s == "+"){
            x+=d;
        }else if(d>x){
            nop++;
        }else{
            x-=d;
        }
    }

    cout<<x<<" "<<nop;


}