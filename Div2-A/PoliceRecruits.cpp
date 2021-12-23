//
// Created by misash on 26/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,e,p=0, c=0;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        cin>>e;
        if(e>0){
            p+=e;
        } else{
            if(p>0){
                p--;
            }else{
                c++;
            }
        }
    }
    cout<<c;

}