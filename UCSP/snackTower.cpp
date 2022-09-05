//
// Created by misash on 29/08/22.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    map<int,bool> has;

    int n,x,top;
    cin>>n;

    top=n;int nums[n];
    for(int i=0; i<n;i++) cin>>nums[i];

    for(int i=0;i<n;i++){
        has[nums[i]] = true;
        while(has[top]){
            cout<<top--<<" ";
        }
        cout<<"\n";
    }

}