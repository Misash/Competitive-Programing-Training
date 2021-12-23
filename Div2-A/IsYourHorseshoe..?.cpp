//
// Created by misash on 28/07/21.
//


#include <bits/stdc++.h>

using namespace std;


int main(){

    int arr[4],ans=0;

    for (int & i : arr) {
        cin>>i;
    }

    sort(arr,arr+4);

    for (int i = 0; i < 4; ++i) {
        if(i==4 || arr[i]!=arr[i+1]){
            ans++;
        }
    }

    cout<<4-ans;

}

